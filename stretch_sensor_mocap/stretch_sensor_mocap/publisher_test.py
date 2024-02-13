#!/usr/bin/env python3

# ROS2 imports
import rclpy
from rclpy.node import Node

# Import messages
from std_msgs.msg import Int64
from stretch_sensor_msgs.msg import Coords # Custom message


class MinimalPublisher(Node):
    def __init__(self) -> None:
        node_name = "minimal_publisher"
        super().__init__(node_name)
        
        # Timer stuff
        timer_frequency = 10 # publish frequency
        timer_period = 1/timer_frequency # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        
        
    def timer_callback(self):
        msg = Coords()
        
    def wavy_taurus():
        t = rclpy.time.Time()
        