#!/usr/bin/env python3

# Ros2 imports
import rclpy
from rclpy.node import Node

from visualization_msgs.msg import Marker, MarkerArray
from geometry_msgs.msg import Pose


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

        # Publisher for visualizing quaternion coordinate frames in rviz
        self.coordinate_marker_publisher = self.create_publisher(MarkerArray, "coordinates_frame_marksers", 10)
        self.marker_counter = 0
        
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

            # Make arrow marker array and publish
            self.clear_markers()
            self.coordinate_marker_publisher.publish(self.create_marker_array(quats.as_quat()))
            
            
            # Rotate a bunch of vectors by quaternions of length decided by the strain sensor length divided by the number of segments
            # Add vectors to get next node location
            # ------- Make vectors ------
            # ------- Rotate vectors ----
            # ------- Add vectors -------

            # Store the pose of node i+1 (i=0 assumed to be at origin)
        return msg

    def create_marker_array(self, quats):
        marker_array = MarkerArray()
        marker_array_temp = []
        for i,q in enumerate(quats):
            p = Pose()
            p.orientation.x = q[0]
            p.orientation.y = q[1]
            p.orientation.z = q[2]
            p.orientation.w = q[3]
            p.position.x = i*0.05
            p.position.y = 0.0
            p.position.z = 1.0
   
            marker_array_temp.append(self.create_marker_msg(p))
        marker_array.markers = marker_array_temp
        return marker_array
            
    def create_marker_msg(self, pose, marker_type=0, frame_id='/map', scale=[0.04,0.005,0.005], color=[1.0,0.0,0.0,1.0], text=None) -> Marker:
        marker = Marker()

        marker.type = marker_type
            
        marker.header.frame_id = frame_id
        marker.header.stamp = self.get_clock().now().to_msg()
        marker.id = self.marker_counter
        self.marker_counter += 1
        
        # add the marker
        marker.action = 0

        marker.scale.x = scale[0]
        marker.scale.y = scale[1]
        marker.scale.z = scale[2]

        marker.pose = pose

        marker.color.r = color[0]
        marker.color.g = color[1]
        marker.color.b = color[2]
        marker.color.a = color[3]

        return marker

    def clear_markers(self, frame="/map"):
        marker_array = MarkerArray()
        marker_array_temp = []
        for i in range(self.marker_counter):
            marker = Marker()
            marker.id = i
            marker.header.frame_id = frame
            marker.action = Marker.DELETEALL
            marker_array_temp.append(marker)
        marker_array.markers = marker_array_temp
        self.coordinate_marker_publisher.publish(marker_array)


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