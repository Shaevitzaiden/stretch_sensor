#!/usr/bin/env python3

# Ros2 imports
import rclpy
from rclpy.node import Node

from visualization_msgs.msg import Marker, MarkerArray
from geometry_msgs.msg import Pose, Point


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
                ('slerp_size', 10),
                ('marker_publish_freq', 15)
            ]
        )  

        # Create subscription to sensor data
        self.sensor_subscription = self.create_subscription(NodeMessageArray, 'processed_sensor_data', self.callback, 10)
        
        # Create publisher to republish processed sensor data
        self.sensor_publisher = self.create_publisher(NodeMessageArray, "sensor_data_with_poses", 10)

        # Publisher for visualizing quaternion coordinate frames in rviz
        self.coordinate_marker_publisher = self.create_publisher(MarkerArray, "coordinates_frame_markers", 10)
        self.marker_counter = 0
        
        # Thread the marker publishing at a set frequency
        marker_publish_period = 1/self.get_parameter('marker_publish_freq').get_parameter_value().integer_value
        self.marker_publish_timer = self.create_timer(marker_publish_period, self.marker_publish_callback)

        # Sensor message history for algorithm purposes
        self.pose_estimate_history = [deque([], maxlen=10) for x in range(self.get_parameter('num_nodes').get_parameter_value().integer_value)]
        self.most_recent_slerp = None
        
    
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
        num_interp_quats = self.get_parameter('slerp_size').get_parameter_value().integer_value
        times = np.linspace(0,1,num_interp_quats)
        for i in range(len(msg.node_data)-1):
            # First run slerp to get array of quaternions
            quat1 = [msg.node_data[i].quaternion.x, msg.node_data[i].quaternion.y, msg.node_data[i].quaternion.z, msg.node_data[i].quaternion.w]
            quat2 = [msg.node_data[i+1].quaternion.x, msg.node_data[i+1].quaternion.y, msg.node_data[i+1].quaternion.z, msg.node_data[i+1].quaternion.w]
            
            node_quaternions = R.from_quat([quat1, quat2])
            slerp_object = Slerp([0, 1], node_quaternions)

            # Perform slerp, gets out [start, ...num_interp_quats-2..., End]
            quats = slerp_object(times)
            self.most_recent_slerp = quats
            
            # Rotate a bunch of vectors by quaternions of length decided by the strain sensor length divided by the number of segments
            # Add vectors to get next node location
            # ------- Make vectors ------
            # ------- Rotate vectors ----
            # ------- Add vectors -------

            # Store the pose of node i+1 (i=0 assumed to be at origin)
        return msg

    def marker_publish_callback(self):
        if self.most_recent_slerp is not None:
            self.coordinate_marker_publisher.publish(self.create_coordinate_marker_array())
            
            # reset marker counter
            self.marker_counter = 0
    
    def create_coordinate_marker_array(self):
        slerp_size = self.get_parameter('slerp_size').get_parameter_value().integer_value
        current_slerp = self.most_recent_slerp
        x = np.zeros([slerp_size, 3])
        x[:,0] = 1
        y = np.zeros([slerp_size, 3])
        y[:,1] = 1
        z = np.zeros([slerp_size, 3])
        z[:,2] = 1
        unit_vectors = [x, y, z]
        # green, red, blue
        colors = [[0.0,1.0,0.0,1.0],[1.0,0.0,0.0,1.0],[0.0,0.0,1.0,1.0]]
        
        # Create empty marker array
        marker_array = MarkerArray()
        # list to store markers in before putting in marker array
        marker_array_temp = []
        
        # Rotate unit vectors by all quaternions produced by slerp
        rotated_x_vec = current_slerp.apply(x)
        rotated_y_vec = current_slerp.apply(y)
        rotated_z_vec = current_slerp.apply(z)
        
        # array of vector positions to place coordinate frames origins at
        origins = np.zeros([slerp_size, 3])
        origins[:,0] = np.arange(slerp_size)
        
        
        for i in range(len(rotated_x_vec[:,0])):
            # Make point lists for each arrow x, y, z
            p_x = [self._make_point(origins[i]), self._make_point(rotated_x_vec[i]+origins[i])]
            p_y = [self._make_point(origins[i]), self._make_point(rotated_y_vec[i]+origins[i])]
            p_z = [self._make_point(origins[i]), self._make_point(rotated_z_vec[i]+origins[i])]
        
            # create arrows 
            m_x = self.create_arrow_marker_msg(p_x, color=colors[0])
            m_y = self.create_arrow_marker_msg(p_y, color=colors[1])
            m_z = self.create_arrow_marker_msg(p_z, color=colors[2])
            
            # add arrows to temporary marker array
            marker_array_temp.append(m_x)
            marker_array_temp.append(m_y)
            marker_array_temp.append(m_z)
        
        # Populate marker array message with arrows
        marker_array.markers = marker_array_temp
        return marker_array
    
    @staticmethod
    def _make_point(vec: np.ndarray)->Point:
        p = Point()
        p.x = vec[0]
        p.y = vec[1]
        p.z = vec[2]
        return p
    
    def create_marker_msg(self, pose, marker_type=0, frame_id='/map', scale=[0.4,0.05,0.05], color=[1.0,0.0,0.0,1.0], text=None) -> Marker:
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

    def create_arrow_marker_msg(self, points, marker_type=0, frame_id='/map', scale=[0.05,0.07,0.0], color=[1.0,0.0,0.0,1.0], text=None) -> Marker:
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

        marker.points = points

        marker.color.r = color[0]
        marker.color.g = color[1]
        marker.color.b = color[2]
        marker.color.a = color[3]

        return marker


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