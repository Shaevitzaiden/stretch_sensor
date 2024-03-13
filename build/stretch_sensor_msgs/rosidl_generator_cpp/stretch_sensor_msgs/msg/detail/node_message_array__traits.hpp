// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from stretch_sensor_msgs:msg/NodeMessageArray.idl
// generated code does not contain a copyright notice

#ifndef STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE_ARRAY__TRAITS_HPP_
#define STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "stretch_sensor_msgs/msg/detail/node_message_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'node_data'
#include "stretch_sensor_msgs/msg/detail/node_message__traits.hpp"

namespace stretch_sensor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const NodeMessageArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: node_data
  {
    if (msg.node_data.size() == 0) {
      out << "node_data: []";
    } else {
      out << "node_data: [";
      size_t pending_items = msg.node_data.size();
      for (auto item : msg.node_data) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NodeMessageArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: node_data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.node_data.size() == 0) {
      out << "node_data: []\n";
    } else {
      out << "node_data:\n";
      for (auto item : msg.node_data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NodeMessageArray & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace stretch_sensor_msgs

namespace rosidl_generator_traits
{

[[deprecated("use stretch_sensor_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const stretch_sensor_msgs::msg::NodeMessageArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  stretch_sensor_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use stretch_sensor_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const stretch_sensor_msgs::msg::NodeMessageArray & msg)
{
  return stretch_sensor_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<stretch_sensor_msgs::msg::NodeMessageArray>()
{
  return "stretch_sensor_msgs::msg::NodeMessageArray";
}

template<>
inline const char * name<stretch_sensor_msgs::msg::NodeMessageArray>()
{
  return "stretch_sensor_msgs/msg/NodeMessageArray";
}

template<>
struct has_fixed_size<stretch_sensor_msgs::msg::NodeMessageArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<stretch_sensor_msgs::msg::NodeMessageArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<stretch_sensor_msgs::msg::NodeMessageArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE_ARRAY__TRAITS_HPP_
