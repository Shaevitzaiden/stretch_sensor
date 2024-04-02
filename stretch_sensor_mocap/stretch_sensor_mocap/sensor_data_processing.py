#!/usr/bin/env python3

# Ros2 imports
import rclpy
from rclpy.node import Node

# Import custon node sensor messages
from stretch_sensor_msgs.msg import NodeMessage, NodeMessageArray

# Import deque to handle fixed size storage of sensor data history
from collections import deque

# Numpy and scipy
import numpy as np
from scipy.spatial.transform import Rotation as R


class SensorDataSubscriber(Node):
    def __init__(self) -> None:
        node_name = "sensor_data_processor"
        super().__init__(node_name)
        
        self.declare_parameters(
            namespace="",
            parameters=[
                ('num_nodes', 5),
                ('node_data_size', 14),
            ]
        )

        # Create subscription to sensor data
        self.sensor_subscription = self.create_subscription(NodeMessageArray, 'sensor_data', self.callback, 10)
        
        # Create publisher to republish processed sensor data
        self.sensor_publisher = self.create_publisher(NodeMessageArray, "processed_sensor_data", 10)
        
        # Store messages to monitor sensor history, used for identifying rotation quadrant using history of gyroscope data, there is a deque for each node
        self.gyroscope_history = [deque([], maxlen=10) for x in range(self.get_parameter('num_nodes').get_parameter_value().integer_value)]
        self.rotation_history = [deque([], maxlen=10) for x in range(self.get_parameter('num_nodes').get_parameter_value().integer_value)]
        
        # Lambda functions to reference when correcting roll axis for quadrants 1-4 
        self.roll_funcs = [lambda x: x, lambda x: 180-x, lambda x: -180-x, lambda x: x]
        self.current_roll_func = self.roll_funcs[0]
        self.roll_func_thresh = 2
        
    def callback(self, msg):
        # # store most recent message
        # self.most_recent_messages.appendleft(msg)
        
        # Populate strain sensor stuffs
        msg = self._process_strain_data(msg)
        
        # Populate euler angle fields and correct limited rotation range of ??? axis 
        msg = self._process_IMU_data(msg)

        # republish message with populated values for strain and euler rotations
        self.sensor_publisher.publish(msg)    
    
    def _process_IMU_data(self, msg):
        for i, sensor_node in enumerate(msg.node_data):    
            # Store most recent gyroscope values for each node in a separate deque
            # self.gyroscope_history[i].appendleft([sensor_node.gyroscope.x, sensor_node.gyroscope.y, sensor_node.gyroscope.z])
            # Average value in each column (x, y, z)
            avg_angular_velocities = np.mean(self.gyroscope_history[i], axis=0)
        
            # Store rotation using quaternion and then convert to euler
            r_quat = R.from_quat([sensor_node.quaternion.x, sensor_node.quaternion.y, sensor_node.quaternion.z, sensor_node.quaternion.w])
            r_euler_intrinsic = r_quat.as_euler('XYZ', degrees=True) # 'xyz' for extrinsic, 'XYZ' for intrinsic rotations
            r_euler_extrinsic = r_quat.as_euler('xyz', degrees=True)

            # Check rotation axis ??? against previous rotation angle and gyroscope to see if it shifted quadrants
            # Maybe instead check the gravity vector to set standard for what quadrant is what at startup? 
            if len(self.rotation_history[i]) == 0:
                self.rotation_history[i].appendleft(r_euler_intrinsic)
            else:
                delta = (r_euler_intrinsic - self.rotation_history[i])

            # Correct y-axis euler intrinsic rotation to full 180 degree rotation window
            # if (np.abs(r_euler_intrinsic[1]) - 90) < self.roll_func_thresh:
            #     s = np.sign(r_euler_intrinsic[1])
            #     if avg_angular_velocities[1] > 0:
            #         self.current_roll_func = self.roll_funcs[1] if (s > 0) else self.roll_funcs[3]
            #     elif avg_angular_velocities[1] < 0:
            #         self.current_roll_func = self.roll_funcs[0] if (s > 0) else self.roll_funcs[2]
            # if np.abs(r_euler_intrinsic[1]) < self.roll_func_thresh:
            #     s = np.sign(r_euler_intrinsic[1])
            #     if avg_angular_velocities[1] > 0:
            #         self.current_roll_func = self.roll_funcs[0] if (s > 0) else self.roll_funcs[2]
            #     elif avg_angular_velocities[1] < 0:
            #         self.current_roll_func = self.roll_funcs[1] if (s > 0) else self.roll_funcs[3]
            
            
            # Probably don't actually need to calculate these, but we are going to need to use the extrinsic rotations for the algorithm, whether in quaternion form or euler angle form
            # The intrinsic rotations are probably only going to be used for comparing against the gyroscope since that is attached the sensor's coordinate frame
            # sensor_node.euler_angles.x = r_euler_intrinsic[0]
            # sensor_node.euler_angles.y = self.current_roll_func(r_euler_intrinsic[1])
            # sensor_node.euler_angles.z = r_euler_intrinsic[2]
            
            
            sensor_node.euler_angles.x = r_euler_extrinsic[0]
            sensor_node.euler_angles.y = r_euler_extrinsic[1]
            sensor_node.euler_angles.z = r_euler_extrinsic[2]

        return msg
                

    def _process_strain_data(self, msg: NodeMessageArray):
        v_ref = 3300 # mV
        r_static = 2100 # ohms
        idle_length = 50 # mm -- this is should be specified elsewhere more configurable, will change later
        
        # Convert adc values into strains
        for sensor_node in msg.node_data:  
            resistance_array = []
            strain_array = []
            length_array = []
            for i in range(len(sensor_node.strain_adc)):  
                voltage = v_ref * sensor_node.strain_adc[i] / 2**12 / sensor_node.gain
                resistance_array.append((voltage * r_static) / (v_ref - voltage))
                
                # Calculate strain and length and add to sensor message
                strain_array.append(np.sqrt(resistance_array[i]/r_static) - 1)
                length_array.append(idle_length * (1 + np.sqrt(resistance_array[i] / r_static)))
            
            # Populate sensor node message fields
            sensor_node.resistance = resistance_array
            sensor_node.strain = strain_array
            sensor_node.length = length_array
        return msg
    

def main(args=None):
    # Init rclpy, always do this
    rclpy.init(args=args)
    
    # Instantiate node class
    sensor_data_subscriber = SensorDataSubscriber()
    
    # Spin up ROS2
    rclpy.spin(sensor_data_subscriber)
    
    # Clean shutdown 
    rclpy.shutdown()


if __name__ ==  "__main__":
    main()