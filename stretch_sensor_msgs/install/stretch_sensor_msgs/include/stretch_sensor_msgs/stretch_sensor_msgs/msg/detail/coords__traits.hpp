// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from stretch_sensor_msgs:msg/Coords.idl
// generated code does not contain a copyright notice

#ifndef STRETCH_SENSOR_MSGS__MSG__DETAIL__COORDS__TRAITS_HPP_
#define STRETCH_SENSOR_MSGS__MSG__DETAIL__COORDS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "stretch_sensor_msgs/msg/detail/coords__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'coord'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace stretch_sensor_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Coords & msg,
  std::ostream & out)
{
  out << "{";
  // member: coord
  {
    out << "coord: ";
    to_flow_style_yaml(msg.coord, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Coords & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: coord
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "coord:\n";
    to_block_style_yaml(msg.coord, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Coords & msg, bool use_flow_style = false)
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
  const stretch_sensor_msgs::msg::Coords & msg,
  std::ostream & out, size_t indentation = 0)
{
  stretch_sensor_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use stretch_sensor_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const stretch_sensor_msgs::msg::Coords & msg)
{
  return stretch_sensor_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<stretch_sensor_msgs::msg::Coords>()
{
  return "stretch_sensor_msgs::msg::Coords";
}

template<>
inline const char * name<stretch_sensor_msgs::msg::Coords>()
{
  return "stretch_sensor_msgs/msg/Coords";
}

template<>
struct has_fixed_size<stretch_sensor_msgs::msg::Coords>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value> {};

template<>
struct has_bounded_size<stretch_sensor_msgs::msg::Coords>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value> {};

template<>
struct is_message<stretch_sensor_msgs::msg::Coords>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // STRETCH_SENSOR_MSGS__MSG__DETAIL__COORDS__TRAITS_HPP_
