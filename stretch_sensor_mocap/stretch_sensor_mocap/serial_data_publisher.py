#!/usr/bin/env python3

# Pyserial library
import serial

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

        self.declare_parameters(
            namespace="",
            parameters=[
                ('serial_port', "/dev/ttyACM0"),
                ('baudrate', 115200),
                ('num_nodes', 2),
                ('node_data_size', 14),
                ('node_sample_freq', 200)
            ]
        )  
        
        # Create serial port interface object
        port = self.get_parameter('serial_port').get_parameter_value().string_value
        baudrate = self.get_parameter('baudrate').get_parameter_value().integer_value
        self.serObj = serial.Serial(port, baudrate, timeout=1)
        
        # Check if open
        if not self.serObj.is_open:
            self.get_logger().error("serial port failed to open, attempting to del serial port object")
            try:
                self.serObj.__del__()
                self.get_logger().error("serial port obj instance succesfully deleted")
            except:
                pass
            # Cleanly shutdown rclpy
            self.get_logger().error("Shutting down rclpy since serial failed")
            self.rclpy.shutdown()
        self.get_logger().info("Serial port successfully opened")
                
        # Create the publisher
        self.publisher = self.create_publisher(NodeMessageArray, "sensor_data", 10)
        
        # Other stuff
        self.time_since_last_sensor_data = self.get_clock().now()
        
        # Start data polling over serial and publishing as fast as possible
        self.stream_data()
        
    def stream_data(self):
        # Amount to delay between checking serial inbound buffer (reduce extraneous looping)
        # delay_amount = 1/(1.5*self.get_parameter('node_sample_freq').get_parameter_value().integer_value)
        
        # Write a character to trigger data output from microcontroller
        self.serObj.write(b'a')
        
        # Stream data while ros2 still workin
        while rclpy.ok():
            # If there is data in the serial buffer read it
            if self.serObj.in_waiting > 0:
                # Read message as array
                dataArray = self._readBytesArray(arrayLen=29)

                # Publish data
                self.publish_data(dataArray)
 
                
                    
    def publish_data(self, data_to_pub):
        array_msg = NodeMessageArray()
        msgs = [NodeMessage() for n in range(self.get_parameter('num_nodes').get_parameter_value().integer_value)]
        
        for i in range(len(data_to_pub)-1):
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
            msgs[i].frame = data_to_pub[-1]
        array_msg.node_data = msgs
        self.publisher.publish(array_msg)
    
                
    def _readBytesArray(self, arrayLen=14):
        data = []
        # loop over each node
        for n in range(self.get_parameter("num_nodes").get_parameter_value().integer_value):        
            # Read and store data from each node in a separate list
            node_data = []
            for i in range(self.get_parameter("node_data_size").get_parameter_value().integer_value):
                msg = self._read14orMoreBitMsg()
                node_data.append(int(msg))
            data.append(node_data)
        
        # Read frame counter from nodes
        data.append(self._read14orMoreBitMsg())
        return data

    def _read14orMoreBitMsg(self):
        msg = 0
        b = int.from_bytes(self.serObj.read(1),'big')
        byteArray = [b]

        while ((b >> 7) & 1):
            b = int.from_bytes(self.serObj.read(1),'big')
            byteArray.append(b)

        for i, byte in enumerate(reversed(byteArray)):
            byte = byte & ~(1<<7)
            msg = msg | (byte << (i*7))
        if msg > 50000:
            msg = msg - 65536
        return msg


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
