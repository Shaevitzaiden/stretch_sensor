from setuptools import find_packages
from setuptools import setup

setup(
    name='stretch_sensor_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('stretch_sensor_msgs', 'stretch_sensor_msgs.*')),
)
