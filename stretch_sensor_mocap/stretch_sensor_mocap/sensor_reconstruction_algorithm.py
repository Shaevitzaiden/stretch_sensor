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
from scipy.spatial.transform import Slerp


class PoseEstimator(Node):
    def __init__(self) -> None:
        node_name = "sensor_reconstruction_algorithm"
        super().__init__(node_name)
        
        self.declare_parameters(
            namespace="",
            parameters=[
                ('num_nodes', 2),
                ('node_data_size', 14),
                ('node_sample_freq', 200)
            ]
        )  

        # Create subscription to sensor data
        self.sensor_subscription = self.create_subscription(NodeMessageArray, 'processed_sensor_data', self.callback, 10)
        
        # Create publisher to republish processed sensor data
        self.sensor_publisher = self.create_publisher(NodeMessageArray, "sensor_data_with_poses", 10)

        # Sensor message history for algorithm purposes
        self.pose_estimate_history = [deque([], maxlen=10) for x in range(self.get_parameter('num_nodes').get_parameter_value().integer_value)]

    def callback(self, msg):
        # store most recent message
        self.estimate_poses(msg)

        # republish message with populated values for strain and euler rotations
        self.sensor_publisher.publish(msg)

    def estimate_poses(self, msg):
        # Store messages for later use (maybe)
        # for i, sensor_node in enumerate(msg.node_data):    
        #     # --------------- Will need to update messages in the msg package for this to work (need to add point msg)
        #     self.pose_estimate_history[i].appendleft([sensor_node.position.x, sensor_node.position.y, sensor_node.position.z, 
        #                                               sensor_node.quaternion.x, sensor_node.quaternion.y, sensor_node.quaternion.z, sensor_node.quaternion.w])

        # Actual base reconstruction algorithm based on quaternion slerp
        num_interp_quats = 10
        times = np.linspace(0,1,num_interp_quats)
        for i in range(len(msg.node_data)-1):
            # First run slerp to get array of quaternions
            quat1 = [msg.node_data[i].quaternion.x, msg.node_data[i].quaternion.y, msg.node_data[i].quaternion.z, msg.node_data[i].quaternion.w]
            quat2 = [msg.node_data[i+1].quaternion.x, msg.node_data[i+1].quaternion.y, msg.node_data[i+1].quaternion.z, msg.node_data[i+1].quaternion.w]
            node_quaternions = R.from_quat([quat1, quat2])
            slerp_object = Slerp([0, 1], node_quaternions)

            # Perform slerp, gets out [start, ...num_interp_quats-2..., End]
            quats = slerp_object(times)

            # Rotate a bunch of vectors by quaternions of length decided by the strain sensor length divided by the number of segments
            # Add vectors to get next node location
            # ------- Make vectors ------
            # ------- Rotate vectors ----
            # ------- Add vectors -------

            # Store the pose of node i+1 (i=0 assumed to be at origin)
        return msg


def main(args=None):
    # Init rclpy, always do this
    rclpy.init(args=args)
    
    # Instantiate node class
    reconstruction_node = PoseEstimator()
    
    # Spin up ROS2
    rclpy.spin(reconstruction_node)
    
    # Clean shutdown 
    rclpy.shutdown()


if __name__ ==  "__main__":
    main()