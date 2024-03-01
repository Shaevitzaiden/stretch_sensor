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
from std_msgs.msg import Int64MultiArray, Int64, Int32, Header
from geometry_msgs.msg import Quaternion, Vector3


class SensorDataPublisher(Node):
    def __init__(self) -> None:
        node_name = "sensor_publisher"
        super().__init__(node_name)

        self.declare_parameters(
            namespace="",
            parameters=[
                ('serial_port', "/dev/ttyACM0"),
                ('baudrate', 115200),
                ('sensor_array_size', 14)
            ]
        )  
        
        # Create serial port interface object
        port = self.get_parameter('serial_port').get_parameter_value().string_value
        baudrate = self.get_parameter('baudrate').get_parameter_value().integer_value
        self.serObj = serial.Serial(port, 115200, timeout=1)
        
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
        
        # Start data polling over serial and publishing as fast as possible
        self.stream_data()
        
    def stream_data(self):
        # Write a character to trigger data output from microcontroller
        self.serObj.write(b'a')
        
        # Stream data while ros2 still workin
        while rclpy.ok():
            # If there is data in the serial buffer
            if self.serObj.in_waiting > 0:
                # Read message as array
                dataArray = self._readBytesArray(arrayLen=29)
                # self.get_logger().info()
                # print([dataArray[i].__class__ for i in range(len(dataArray))])
                self.publish_data(dataArray)
            self.get_logger().info("Failed to grab data")
                
                    
    def publish_data(self, data_to_pub):
        msg = NodeMessage()
        
        # Header msg
        msg.header.frame_id = 1
        msg.header.stamp = self.get_clock.now()
        
        # Quaternion
        msg.quaternion.x = 0
        msg.quaternion.y = 0
        msg.quaternion.z = 0
        msg.quaternion.w = 0
        
        # Accelerometer
        msg.acceleration.x = 0
        msg.acceleration.y = 0
        msg.acceleration.z = 0
        
        # Gyroscope
        msg.gyroscope.x = 0
        msg.gyroscope.y = 0
        msg.gyroscope.z = 0
        
        # Strain sensors
        msg.strain_adc = [0, 0]
        
        # Gain
        msg.gain = 0
        
        # Node frame
        msg.frame = data_to_pub[-1]
        
        
          
    def _readBytesArray(self, arrayLen=43):
        data = []
        for i in range(arrayLen):
            msg = self._read14orMoreBitMsg()
            data.append(int(msg))
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
    # while True:
    #         try:
    #             if ser.in_waiting > 0:
    #                 # Read messages and write them to a csv
    #                 dataArray = readBytesArray(ser, arrayLen=29)
    #                 # readBytesArray(ser)
    #                 # dataStr = ', '.join(map(str, dataArray))
    #                 print(dataArray)
    #         except KeyboardInterrupt:
    #             print('ok, ok, terminating now...')
    #             break
            
    #         except IndexError:
    #             print("Index Error")
    #             continue
            
    # # Empty buffer and close serial port
    # ser.reset_input_buffer()
    # ser.close()
    
    # print("Done")