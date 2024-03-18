# Stretchable Sensor for Real-Time 3D Reconstruction

A project using ROS2 to process sensor data and test 3D reconstruction algorithms while providing nice visuals

## Description



## Getting Started

### Dependencies

- [ROS2 Humble](https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debians.html)

- [PlotJuggler](https://github.com/facontidavide/PlotJuggler)
  
      sudo apt install ros-$ROS_DISTRO-plotjuggler-ros
  
- [Pyserial](https://pyserial.readthedocs.io)

        pip install pyserial

### Hardware/Firmware (optional)
- A SAMD21 based microcontroller board. This project used an [M0 feather](https://www.adafruit.com/product/3403)
- A minimum of two Bosch BNO085 IMUs (easy to use as a [breakout board](https://www.adafruit.com/product/4754))
- For firmware the [Arduino IDE](https://www.arduino.cc/en/software) with the appropriate board definition for programming the SAMD21. Instructions on how to set this up [here](https://learn.adafruit.com/adafruit-feather-m0-basic-proto/using-with-arduino-ide)

### Installing

Make a ROS workspace

    mkdir ros_ws/src && cd src

Clone this repository

    git clone git@github.com:ali-clara/apple_gripper.git

Install all dependencies with [rosdep](https://docs.ros.org/en/humble/Tutorials/Intermediate/Rosdep.html)

    rosdep install --from-paths src -y --ignore-src

Build

    cd ~/ros_ws
    colcon build --symlink-install

### Executing program

To run
```
code blocks for commands
```

## Help

Any advise for common problems or issues.
```
command to run if program contains helper info
```

## Authors

Contributors names and contact info

ex. Dominique Pizzie  
ex. [@DomPizzie](https://twitter.com/dompizzie)

## Version History

* 0.2
    * Various bug fixes and optimizations
    * See [commit change]() or See [release history]()
* 0.1
    * Initial Release

## License

This project is licensed under the [NAME HERE] License - see the LICENSE.md file for details

## Acknowledgments

Inspiration, code snippets, etc.
* [awesome-readme](https://github.com/matiassingers/awesome-readme)
* [PurpleBooth](https://gist.github.com/PurpleBooth/109311bb0361f32d87a2)
* [dbader](https://github.com/dbader/readme-template)
* [zenorocha](https://gist.github.com/zenorocha/4526327)
* [fvcproductions](https://gist.github.com/fvcproductions/1bfc2d4aecb01a834b46)
 
