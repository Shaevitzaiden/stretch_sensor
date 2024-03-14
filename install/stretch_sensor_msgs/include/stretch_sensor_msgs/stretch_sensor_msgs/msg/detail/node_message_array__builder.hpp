// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from stretch_sensor_msgs:msg/NodeMessageArray.idl
// generated code does not contain a copyright notice

#ifndef STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE_ARRAY__BUILDER_HPP_
#define STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "stretch_sensor_msgs/msg/detail/node_message_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace stretch_sensor_msgs
{

namespace msg
{

namespace builder
{

class Init_NodeMessageArray_node_data
{
public:
  Init_NodeMessageArray_node_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::stretch_sensor_msgs::msg::NodeMessageArray node_data(::stretch_sensor_msgs::msg::NodeMessageArray::_node_data_type arg)
  {
    msg_.node_data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::stretch_sensor_msgs::msg::NodeMessageArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::stretch_sensor_msgs::msg::NodeMessageArray>()
{
  return stretch_sensor_msgs::msg::builder::Init_NodeMessageArray_node_data();
}

}  // namespace stretch_sensor_msgs

#endif  // STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE_ARRAY__BUILDER_HPP_
