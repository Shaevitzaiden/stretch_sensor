import os
from glob import glob

from setuptools import find_packages, setup


package_name = 'stretch_sensor_mocap'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob(os.path.join('launch', '*launch.[pxy][yma]*'))),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='aidenshaevitz',
    maintainer_email='39567668+Shaevitzaiden@users.noreply.github.com',
    description='TODO: Package description',
    license='BSD-3-Clause',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'sensor_publisher = stretch_sensor_mocap.serial_data_publisher:main',
            'sensor_processor = stretch_sensor_mocap.sensor_data_processing:main'
        ],
    },
)
