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
        'juggler_test.xml')
    
    
    launch_plotjuggler = Node(
        package='plotjuggler',
        executable='plotjuggler',
        arguments=['-l', rviz_config_dir],
        # parameters=[{'use_sim_time': True}],
        # output='log'
        )
    
    # Create launch description and add actions
    ld = LaunchDescription()
    ld.add_action(launch_plotjuggler)
    
    
    return ld