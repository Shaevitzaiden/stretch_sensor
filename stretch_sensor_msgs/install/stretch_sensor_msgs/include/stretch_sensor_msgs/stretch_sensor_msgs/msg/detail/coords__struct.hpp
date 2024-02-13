// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from stretch_sensor_msgs:msg/Coords.idl
// generated code does not contain a copyright notice

#ifndef STRETCH_SENSOR_MSGS__MSG__DETAIL__COORDS__STRUCT_HPP_
#define STRETCH_SENSOR_MSGS__MSG__DETAIL__COORDS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'coord'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__stretch_sensor_msgs__msg__Coords __attribute__((deprecated))
#else
# define DEPRECATED__stretch_sensor_msgs__msg__Coords __declspec(deprecated)
#endif

namespace stretch_sensor_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Coords_
{
  using Type = Coords_<ContainerAllocator>;

  explicit Coords_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : coord(_init)
  {
    (void)_init;
  }

  explicit Coords_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : coord(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _coord_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _coord_type coord;

  // setters for named parameter idiom
  Type & set__coord(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->coord = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    stretch_sensor_msgs::msg::Coords_<ContainerAllocator> *;
  using ConstRawPtr =
    const stretch_sensor_msgs::msg::Coords_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<stretch_sensor_msgs::msg::Coords_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<stretch_sensor_msgs::msg::Coords_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      stretch_sensor_msgs::msg::Coords_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<stretch_sensor_msgs::msg::Coords_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      stretch_sensor_msgs::msg::Coords_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<stretch_sensor_msgs::msg::Coords_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<stretch_sensor_msgs::msg::Coords_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<stretch_sensor_msgs::msg::Coords_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__stretch_sensor_msgs__msg__Coords
    std::shared_ptr<stretch_sensor_msgs::msg::Coords_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__stretch_sensor_msgs__msg__Coords
    std::shared_ptr<stretch_sensor_msgs::msg::Coords_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Coords_ & other) const
  {
    if (this->coord != other.coord) {
      return false;
    }
    return true;
  }
  bool operator!=(const Coords_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Coords_

// alias to use template instance with default allocator
using Coords =
  stretch_sensor_msgs::msg::Coords_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace stretch_sensor_msgs

#endif  // STRETCH_SENSOR_MSGS__MSG__DETAIL__COORDS__STRUCT_HPP_
