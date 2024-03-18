#!/usr/bin/env python3

# Pyserial library
import serial

# OS
import os

# Other
import numpy as np
import time

# Rospy
import rclpy
from rclpy.node import Node

# Import messages
from stretch_sensor_msgs.msg import NodeMessage, NodeMessageArray


class SensorDataPublisher(Node):
    def __init__(self) -> None:
        node_name = "sensor_publisher"
        super().__init__(node_name)

        # csv_dir = os.path.abspath(os.path.join(os.getcwd(), os.pardir, 'resource', '5-node_sensor-v2_single-bend-point.csv'))
        # csv_dir = os.path.abspath(os.path.join(os.getcwd(), os.pardir, 'resource', '5-node_sensor-v2_double-bend_points.csv'))
        
        self.declare_parameters(
            namespace="",
            parameters=[
                ('serial_port', "/dev/ttyACM0"),
                ('baudrate', 115200),
                ('num_nodes', 5),
                ('node_data_size', 14),
                ('node_sample_freq', 100),
                ('csv_dir', csv_dir)
            ]
        )  
        print('---------------------------------------------------------------------------------------')
        print(self.get_parameter('csv_dir').get_parameter_value().string_value)
        
        # Data from csv to stream
        self.data = np.loadtxt(self.get_parameter('csv_dir').get_parameter_value().string_value, delimiter=',')
        self.data_row = 0
        
        # Timer to call publisher
        self.pub_timer = self.create_timer(1/self.get_parameter('node_sample_freq').get_parameter_value().integer_value, self.publish_data)
        
        # Create the publisher
        self.publisher = self.create_publisher(NodeMessageArray, "sensor_data", 10)
                
                    
    def publish_data(self):
        array_msg = NodeMessageArray()
        msgs = [NodeMessage() for n in range(self.get_parameter('num_nodes').get_parameter_value().integer_value)]
        
        try:
            current_data = self.data[self.data_row,:]
        except IndexError:
            self.data_row = 0
            current_data = self.data[self.data_row,:]
        self.data_row += 1
        data_to_pub = []
        
        for i in range(self.get_parameter('num_nodes').get_parameter_value().integer_value):
            idx0 = i * self.get_parameter('node_data_size').get_parameter_value().integer_value
            idx1 = idx0 + self.get_parameter('node_data_size').get_parameter_value().integer_value
            data_to_pub.append([current_data[j] for j in range(idx0,idx1)])
        # print(data_to_pub)
        
        for i in range(len(data_to_pub)):
            data = data_to_pub[i]
            
            # Header msg
            msgs[i].header.frame_id = str(i)
            # msg.header.stamp = self.get_clock().now()
            
            # Quaternion
            msgs[i].quaternion.x = float(data[9])
            msgs[i].quaternion.y = float(data[10])
            msgs[i].quaternion.z = float(data[11])
            msgs[i].quaternion.w = float(data[8])
            
            # Rotation quality estimate
            msgs[i].rotation_quality = int(data[12])
            
            # Accelerometer
            msgs[i].acceleration.x = float(data[2])
            msgs[i].acceleration.y = float(data[3])
            msgs[i].acceleration.z = float(data[4])
            
            # Gyroscope
            msgs[i].gyroscope.x = float(data[5])
            msgs[i].gyroscope.y = float(data[6])
            msgs[i].gyroscope.z = float(data[7])
            
            # Strain sensors
            msgs[i].strain_adc = [int(data[0]), int(data[1])]
            
            # Gain
            msgs[i].gain = int(data[13])
            
            # Node frame
            msgs[i].frame = int(current_data[-1])
        array_msg.node_data = msgs
        self.publisher.publish(array_msg)


def main(args=None):
    # Init rclpy, always do this
    rclpy.init(args=args)
    
    # Instantiate node class
    sensor_data_publisher = SensorDataPublisher()
    
    # Spin up ROS2
    rclpy.spin(sensor_data_publisher)
    
    # Clean shutdown 
    rclpy.shutdown()
        

if __name__ == "__main__":
    main()
