#!/usr/bin/env python3

# ROS2 imports
import rclpy
from rclpy.node import Node

# Import messages
from std_msgs.msg import Int64
from stretch_sensor_msgs.msg import Coords # Custom message

# Other imports
import numpy as np


class MinimalPublisher(Node):
    def __init__(self) -> None:
        node_name = "minimal_publisher"
        super().__init__(node_name)
        
        # Create publisher
        self.publisher = self.create_publisher(Coords, 'taurus_coords', 10)
        
        # Timer stuff
        timer_frequency = 10 # publish frequency
        timer_period = 1/timer_frequency # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        
        
    def timer_callback(self):
        msg = Coords()
        
        (x,y,z) = self.wavy_taurus()
        Coords.x = x
        Coords.y = y
        Coords.z = z
        
        self.publ
    
    @staticmethod
    def wavy_taurus():
        t = rclpy.time.Time()
        x = np.cos(t)
        y = np.sin(t)
        z = y
        return (x, y, z)
        
        
def main(args=None):
    # Init rclpy, always do this
    rclpy.init(args=args)
    
    # Instantiate node class
    minimal_publisher = MinimalPublisher
    
    # Spin up ROS2
    rclpy.spin(minimal_publisher)
    
    # Clean shutdown 
    rclpy.shutdown()
    

if __name__ == "__main__":
    # Run main function
    main()