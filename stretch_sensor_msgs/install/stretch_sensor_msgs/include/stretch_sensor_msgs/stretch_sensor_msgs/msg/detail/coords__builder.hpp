// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from stretch_sensor_msgs:msg/Coords.idl
// generated code does not contain a copyright notice

#ifndef STRETCH_SENSOR_MSGS__MSG__DETAIL__COORDS__BUILDER_HPP_
#define STRETCH_SENSOR_MSGS__MSG__DETAIL__COORDS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "stretch_sensor_msgs/msg/detail/coords__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace stretch_sensor_msgs
{

namespace msg
{

namespace builder
{

class Init_Coords_coord
{
public:
  Init_Coords_coord()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::stretch_sensor_msgs::msg::Coords coord(::stretch_sensor_msgs::msg::Coords::_coord_type arg)
  {
    msg_.coord = std::move(arg);
    return std::move(msg_);
  }

private:
  ::stretch_sensor_msgs::msg::Coords msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::stretch_sensor_msgs::msg::Coords>()
{
  return stretch_sensor_msgs::msg::builder::Init_Coords_coord();
}

}  // namespace stretch_sensor_msgs

#endif  // STRETCH_SENSOR_MSGS__MSG__DETAIL__COORDS__BUILDER_HPP_
