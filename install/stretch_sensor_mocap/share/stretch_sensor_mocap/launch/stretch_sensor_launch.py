import launch
import launch_ros.actions

def generate_launch_description():
    return launch.LaunchDescription([
        # node using pyserial to sample sensors
        launch_ros.actions.Node(
            package='stretch_sensor_mocap',
            executable='sensor_publisher',
            parameters=[
                {'serial_port': "/dev/ttyACM0"},
                {'baudrate': 115200},
                {'num_nodes': 2},
                {'node_data_size': 14},
                {'node_sample_freq': 200}
            ]
            ),
        
        launch_ros.actions.Node(
            package='stretch_sensor_mocap',
            executable='sensor_processor',
            parameters=[
                {'num_nodes': 2},
                {'node_data_size': 14},
            ]
            ),
        
        launch_ros.actions.Node(
            package='stretch_sensor_mocap',
            executable='sensor_processor',
            parameters=[
                {'num_nodes': 2},
                {'slerp_size': 15},
                {'marker_publish_freq': 15}
            ]
            ),
        
        launch_ros.actions.Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            # arguments=['-d', rviz_config_dir],
            parameters=[{'use_sim_time': 'false'}],
            output='screen')
        
        ])