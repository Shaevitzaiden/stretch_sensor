#!/usr/bin/env python3

# Ros2 imports
import rclpy
import rclpy.node as Node

# Import custon node sensor messages
from stretch_sensor_msgs.msg import NodeMessage, NodeMessageArray

# Import deque to handle fixed size storage of sensor data history
from collections import deque


class SensorDataSubscriber(Node):
    def __init__(self):
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
    
    def _process_strain_data(self, msg):
        # Convert adc values into strains
        v_ref = 3300 # mV
        r_static = 2100 # ohms
        idle_length = 50 # mm -- this is should be specified elsewhere more configurable, will change later
        
        voltage = v_ref * adc / 2^12 / gain
           
        
    