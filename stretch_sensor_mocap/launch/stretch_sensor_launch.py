import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, SetEnvironmentVariable, DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():
    rviz_config_dir = os.path.join(
        get_package_share_directory('stretch_sensor_mocap'),
        'config',
        'test.rviz')
    
    plotjuggler_layout_dir = os.path.join(
        get_package_share_directory('stretch_sensor_mocap'),
        'config',
        'juggler_test.xml')
    
    # node using pyserial to sample sensors
    launch_serial = Node(
        package='stretch_sensor_mocap',
        executable='sensor_publisher',
        parameters=[
            {'serial_port': "/dev/ttyACM0"},
            {'baudrate': 115200},
            {'num_nodes': 2},
            {'node_data_size': 14},
            {'node_sample_freq': 200}
        ]
        )
    
    launch_processing = Node(
        package='stretch_sensor_mocap',
        executable='sensor_processor',
        parameters=[
            {'num_nodes': 2},
            {'node_data_size': 14},
        ]
        )
    
    launch_reconstruction = Node(
        package='stretch_sensor_mocap',
        executable='reconstruction',
        parameters=[
            {'num_nodes': 2},
            {'slerp_size': 10},
            {'marker_publish_freq': 15}
        ]
        )
    
    launch_rviz2 = Node(
        package='rviz2',
        executable='rviz2',
        arguments=['-d', rviz_config_dir],
        parameters=[{'use_sim_time': False}],
        output='log'
        )
    
    launch_plotjuggler = Node(
        package='plotjuggler',
        executable='plotjuggler',
        arguments=['-l', plotjuggler_layout_dir]
        )
    
    # Create launch description and add actions
    ld = LaunchDescription()
    
    ld.add_action(launch_serial)
    ld.add_action(launch_processing)
    ld.add_action(launch_reconstruction)
    ld.add_action(launch_rviz2)
    ld.add_action(launch_plotjuggler)
    
    return ld