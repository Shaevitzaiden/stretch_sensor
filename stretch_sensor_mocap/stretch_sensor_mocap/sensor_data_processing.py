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
        
        # Create subscription to sensor data
        self.sensor_subscription = self.create_subscription(NodeMessageArray, 'sensor_data', self.callback, 10)
        
        # Create publisher to republish processed sensor data
        self.sensor_publisher = self.create_publisher(NodeMessageArray, "processed_sensor_data", 10)
        
        # Store messages to monitor sensor history, used for identifying rotation quadrant using history of gyroscope data
        self.most_recent_messages = deque([],maxlen=10)
        
    def callback(self, msg):
        # store most recent message
        self.most_recent_messages.appendleft(msg)
        
        # Populate strain sensor stuffs
        msg = self._process_strain_data(msg)

        # republish message with populated values for strain and euler rotations
        self.sensor_publisher.publish(msg)    
    
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