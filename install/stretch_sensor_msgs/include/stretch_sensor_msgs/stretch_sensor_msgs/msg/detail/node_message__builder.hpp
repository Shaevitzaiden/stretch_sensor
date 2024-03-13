// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from stretch_sensor_msgs:msg/NodeMessage.idl
// generated code does not contain a copyright notice

#ifndef STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE__BUILDER_HPP_
#define STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "stretch_sensor_msgs/msg/detail/node_message__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace stretch_sensor_msgs
{

namespace msg
{

namespace builder
{

class Init_NodeMessage_frame
{
public:
  explicit Init_NodeMessage_frame(::stretch_sensor_msgs::msg::NodeMessage & msg)
  : msg_(msg)
  {}
  ::stretch_sensor_msgs::msg::NodeMessage frame(::stretch_sensor_msgs::msg::NodeMessage::_frame_type arg)
  {
    msg_.frame = std::move(arg);
    return std::move(msg_);
  }

private:
  ::stretch_sensor_msgs::msg::NodeMessage msg_;
};

class Init_NodeMessage_gain
{
public:
  explicit Init_NodeMessage_gain(::stretch_sensor_msgs::msg::NodeMessage & msg)
  : msg_(msg)
  {}
  Init_NodeMessage_frame gain(::stretch_sensor_msgs::msg::NodeMessage::_gain_type arg)
  {
    msg_.gain = std::move(arg);
    return Init_NodeMessage_frame(msg_);
  }

private:
  ::stretch_sensor_msgs::msg::NodeMessage msg_;
};

class Init_NodeMessage_length
{
public:
  explicit Init_NodeMessage_length(::stretch_sensor_msgs::msg::NodeMessage & msg)
  : msg_(msg)
  {}
  Init_NodeMessage_gain length(::stretch_sensor_msgs::msg::NodeMessage::_length_type arg)
  {
    msg_.length = std::move(arg);
    return Init_NodeMessage_gain(msg_);
  }

private:
  ::stretch_sensor_msgs::msg::NodeMessage msg_;
};

class Init_NodeMessage_base_length
{
public:
  explicit Init_NodeMessage_base_length(::stretch_sensor_msgs::msg::NodeMessage & msg)
  : msg_(msg)
  {}
  Init_NodeMessage_length base_length(::stretch_sensor_msgs::msg::NodeMessage::_base_length_type arg)
  {
    msg_.base_length = std::move(arg);
    return Init_NodeMessage_length(msg_);
  }

private:
  ::stretch_sensor_msgs::msg::NodeMessage msg_;
};

class Init_NodeMessage_strain
{
public:
  explicit Init_NodeMessage_strain(::stretch_sensor_msgs::msg::NodeMessage & msg)
  : msg_(msg)
  {}
  Init_NodeMessage_base_length strain(::stretch_sensor_msgs::msg::NodeMessage::_strain_type arg)
  {
    msg_.strain = std::move(arg);
    return Init_NodeMessage_base_length(msg_);
  }

private:
  ::stretch_sensor_msgs::msg::NodeMessage msg_;
};

class Init_NodeMessage_resistance
{
public:
  explicit Init_NodeMessage_resistance(::stretch_sensor_msgs::msg::NodeMessage & msg)
  : msg_(msg)
  {}
  Init_NodeMessage_strain resistance(::stretch_sensor_msgs::msg::NodeMessage::_resistance_type arg)
  {
    msg_.resistance = std::move(arg);
    return Init_NodeMessage_strain(msg_);
  }

private:
  ::stretch_sensor_msgs::msg::NodeMessage msg_;
};

class Init_NodeMessage_base_resistance
{
public:
  explicit Init_NodeMessage_base_resistance(::stretch_sensor_msgs::msg::NodeMessage & msg)
  : msg_(msg)
  {}
  Init_NodeMessage_resistance base_resistance(::stretch_sensor_msgs::msg::NodeMessage::_base_resistance_type arg)
  {
    msg_.base_resistance = std::move(arg);
    return Init_NodeMessage_resistance(msg_);
  }

private:
  ::stretch_sensor_msgs::msg::NodeMessage msg_;
};

class Init_NodeMessage_strain_adc
{
public:
  explicit Init_NodeMessage_strain_adc(::stretch_sensor_msgs::msg::NodeMessage & msg)
  : msg_(msg)
  {}
  Init_NodeMessage_base_resistance strain_adc(::stretch_sensor_msgs::msg::NodeMessage::_strain_adc_type arg)
  {
    msg_.strain_adc = std::move(arg);
    return Init_NodeMessage_base_resistance(msg_);
  }

private:
  ::stretch_sensor_msgs::msg::NodeMessage msg_;
};

class Init_NodeMessage_gyroscope
{
public:
  explicit Init_NodeMessage_gyroscope(::stretch_sensor_msgs::msg::NodeMessage & msg)
  : msg_(msg)
  {}
  Init_NodeMessage_strain_adc gyroscope(::stretch_sensor_msgs::msg::NodeMessage::_gyroscope_type arg)
  {
    msg_.gyroscope = std::move(arg);
    return Init_NodeMessage_strain_adc(msg_);
  }

private:
  ::stretch_sensor_msgs::msg::NodeMessage msg_;
};

class Init_NodeMessage_acceleration
{
public:
  explicit Init_NodeMessage_acceleration(::stretch_sensor_msgs::msg::NodeMessage & msg)
  : msg_(msg)
  {}
  Init_NodeMessage_gyroscope acceleration(::stretch_sensor_msgs::msg::NodeMessage::_acceleration_type arg)
  {
    msg_.acceleration = std::move(arg);
    return Init_NodeMessage_gyroscope(msg_);
  }

private:
  ::stretch_sensor_msgs::msg::NodeMessage msg_;
};

class Init_NodeMessage_rotation_quality
{
public:
  explicit Init_NodeMessage_rotation_quality(::stretch_sensor_msgs::msg::NodeMessage & msg)
  : msg_(msg)
  {}
  Init_NodeMessage_acceleration rotation_quality(::stretch_sensor_msgs::msg::NodeMessage::_rotation_quality_type arg)
  {
    msg_.rotation_quality = std::move(arg);
    return Init_NodeMessage_acceleration(msg_);
  }

private:
  ::stretch_sensor_msgs::msg::NodeMessage msg_;
};

class Init_NodeMessage_euler_angles
{
public:
  explicit Init_NodeMessage_euler_angles(::stretch_sensor_msgs::msg::NodeMessage & msg)
  : msg_(msg)
  {}
  Init_NodeMessage_rotation_quality euler_angles(::stretch_sensor_msgs::msg::NodeMessage::_euler_angles_type arg)
  {
    msg_.euler_angles = std::move(arg);
    return Init_NodeMessage_rotation_quality(msg_);
  }

private:
  ::stretch_sensor_msgs::msg::NodeMessage msg_;
};

class Init_NodeMessage_quaternion
{
public:
  explicit Init_NodeMessage_quaternion(::stretch_sensor_msgs::msg::NodeMessage & msg)
  : msg_(msg)
  {}
  Init_NodeMessage_euler_angles quaternion(::stretch_sensor_msgs::msg::NodeMessage::_quaternion_type arg)
  {
    msg_.quaternion = std::move(arg);
    return Init_NodeMessage_euler_angles(msg_);
  }

private:
  ::stretch_sensor_msgs::msg::NodeMessage msg_;
};

class Init_NodeMessage_header
{
public:
  Init_NodeMessage_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NodeMessage_quaternion header(::stretch_sensor_msgs::msg::NodeMessage::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_NodeMessage_quaternion(msg_);
  }

private:
  ::stretch_sensor_msgs::msg::NodeMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::stretch_sensor_msgs::msg::NodeMessage>()
{
  return stretch_sensor_msgs::msg::builder::Init_NodeMessage_header();
}

}  // namespace stretch_sensor_msgs

#endif  // STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE__BUILDER_HPP_
