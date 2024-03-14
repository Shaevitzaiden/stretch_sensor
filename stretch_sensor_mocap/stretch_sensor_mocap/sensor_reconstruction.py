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
                ('slerp_size', 15),
                ('marker_publish_freq', 15)
            ]
        )  

        # Create subscription to sensor data
        self.sensor_subscription = self.create_subscription(NodeMessageArray, 'processed_sensor_data', self.callback, 10)
        
        # Create publisher to republish processed sensor data
        self.sensor_publisher = self.create_publisher(NodeMessageArray, "sensor_data_with_poses", 10)

        # Publisher for visualizing quaternion coordinate frames in rviz
        self.marker_counter = 0
        self.test_scalar = 5
        self.coordinate_marker_publisher = self.create_publisher(MarkerArray, "coordinates_frame_markers", 10)
        
        # Thread the marker publishing at a set frequency
        marker_publish_period = 1/self.get_parameter('marker_publish_freq').get_parameter_value().integer_value
        self.marker_publish_timer = self.create_timer(marker_publish_period, self.marker_publish_callback)

        # Sensor message history for algorithm purposes
        self.pose_estimate_history = [deque([], maxlen=10) for x in range(self.get_parameter('num_nodes').get_parameter_value().integer_value)]
        self.most_recent_reconstruction = None
        
    
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

        # List comprehension of lists containing quaternion components for each sensor node
        quats_array = [[msg.node_data[i].quaternion.x, msg.node_data[i].quaternion.y, msg.node_data[i].quaternion.z, msg.node_data[i].quaternion.w]
                        for i in range(len(msg.node_data)-1)]
        
        # Window where each 
        slerp_window = np.arange(len(quats_array)) 
        node_quaternions = R.from_quat(quats_array)
        
        # Make slerp object from window and quaternions
        slerp_object = Slerp(slerp_window, node_quaternions)

        # Perform slerp with num_inter_quats between each quaternion, gets out [start, ...num_interp_quats-2..., End]
        times = np.linspace([0, slerp_window[-1]], num_interp_quats*len(quats_array))
        quats = slerp_object(times)
        
        # Make vectors using vector corresponding to direction axis strain sensor is attached to
        x_vecs = np.zeros([num_interp_quats, 3])
        x_vecs[:,1] = 1
        
        # Rotate vectors 
        rotated_x_vectors = quats.apply(x_vecs)
        
        # Cumulative sum of vectors to build out curve
        summed_rotated_x_vectors = np.cumsum(rotated_x_vectors, axis=0)
        
        # Scale the vectors by the length of the strain sensors divided by the number of segments
        strain_scaled_rotated_x_vectors = self.test_scalar*summed_rotated_x_vectors/(num_interp_quats-1)
        
        self.most_recent_reconstruction = [strain_scaled_rotated_x_vectors, quats]
        # Store the pose of node i+1 (i=0 assumed to be at origin)
        return msg

    def marker_publish_callback(self):
        if self.most_recent_reconstruction is not None:
            self.coordinate_marker_publisher.publish(self.create_coordinate_marker_array())
            
            # reset marker counter
            self.marker_counter = 0
    
    def create_coordinate_marker_array(self):
        slerp_size = self.get_parameter('slerp_size').get_parameter_value().integer_value
        [current_points, current_slerp] = self.most_recent_reconstruction
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
        origins = np.vstack([np.array([0,0,0]), current_points])
        
        
        for i in range(len(rotated_x_vec[:,0])):
            # Make point lists for each arrow x, y, z
            p_x = [self._make_point(origins[i]), self._make_point(self.test_scalar*rotated_x_vec[i]/(slerp_size-1)+origins[i])]
            p_y = [self._make_point(origins[i]), self._make_point(self.test_scalar*rotated_y_vec[i]/(slerp_size-1)+origins[i])]
            p_z = [self._make_point(origins[i]), self._make_point(self.test_scalar*rotated_z_vec[i]/(slerp_size-1)+origins[i])]
        
            # create arrows 
            m_x = self.create_arrow_marker_msg(p_x, color=colors[0], scale=[0.5/slerp_size,1.2/slerp_size,0.0])
            m_y = self.create_arrow_marker_msg(p_y, color=colors[1], scale=[0.5/slerp_size,1.2/slerp_size,0.0])
            m_z = self.create_arrow_marker_msg(p_z, color=colors[2], scale=[0.5/slerp_size,1.2/slerp_size,0.0])
            
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