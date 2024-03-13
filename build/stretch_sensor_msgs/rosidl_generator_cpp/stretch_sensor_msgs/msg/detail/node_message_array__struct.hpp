// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from stretch_sensor_msgs:msg/NodeMessageArray.idl
// generated code does not contain a copyright notice

#ifndef STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE_ARRAY__STRUCT_HPP_
#define STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'node_data'
#include "stretch_sensor_msgs/msg/detail/node_message__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__stretch_sensor_msgs__msg__NodeMessageArray __attribute__((deprecated))
#else
# define DEPRECATED__stretch_sensor_msgs__msg__NodeMessageArray __declspec(deprecated)
#endif

namespace stretch_sensor_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NodeMessageArray_
{
  using Type = NodeMessageArray_<ContainerAllocator>;

  explicit NodeMessageArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit NodeMessageArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _node_data_type =
    std::vector<stretch_sensor_msgs::msg::NodeMessage_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<stretch_sensor_msgs::msg::NodeMessage_<ContainerAllocator>>>;
  _node_data_type node_data;

  // setters for named parameter idiom
  Type & set__node_data(
    const std::vector<stretch_sensor_msgs::msg::NodeMessage_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<stretch_sensor_msgs::msg::NodeMessage_<ContainerAllocator>>> & _arg)
  {
    this->node_data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    stretch_sensor_msgs::msg::NodeMessageArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const stretch_sensor_msgs::msg::NodeMessageArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<stretch_sensor_msgs::msg::NodeMessageArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<stretch_sensor_msgs::msg::NodeMessageArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      stretch_sensor_msgs::msg::NodeMessageArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<stretch_sensor_msgs::msg::NodeMessageArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      stretch_sensor_msgs::msg::NodeMessageArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<stretch_sensor_msgs::msg::NodeMessageArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<stretch_sensor_msgs::msg::NodeMessageArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<stretch_sensor_msgs::msg::NodeMessageArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__stretch_sensor_msgs__msg__NodeMessageArray
    std::shared_ptr<stretch_sensor_msgs::msg::NodeMessageArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__stretch_sensor_msgs__msg__NodeMessageArray
    std::shared_ptr<stretch_sensor_msgs::msg::NodeMessageArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NodeMessageArray_ & other) const
  {
    if (this->node_data != other.node_data) {
      return false;
    }
    return true;
  }
  bool operator!=(const NodeMessageArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NodeMessageArray_

// alias to use template instance with default allocator
using NodeMessageArray =
  stretch_sensor_msgs::msg::NodeMessageArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace stretch_sensor_msgs

#endif  // STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE_ARRAY__STRUCT_HPP_
