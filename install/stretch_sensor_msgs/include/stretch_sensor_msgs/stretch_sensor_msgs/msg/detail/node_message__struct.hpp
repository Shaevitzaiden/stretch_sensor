// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from stretch_sensor_msgs:msg/NodeMessage.idl
// generated code does not contain a copyright notice

#ifndef STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE__STRUCT_HPP_
#define STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'quaternion'
#include "geometry_msgs/msg/detail/quaternion__struct.hpp"
// Member 'euler_angles'
// Member 'acceleration'
// Member 'gyroscope'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__stretch_sensor_msgs__msg__NodeMessage __attribute__((deprecated))
#else
# define DEPRECATED__stretch_sensor_msgs__msg__NodeMessage __declspec(deprecated)
#endif

namespace stretch_sensor_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NodeMessage_
{
  using Type = NodeMessage_<ContainerAllocator>;

  explicit NodeMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    quaternion(_init),
    euler_angles(_init),
    acceleration(_init),
    gyroscope(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->rotation_quality = 0l;
      this->gain = 0l;
      this->frame = 0ll;
    }
  }

  explicit NodeMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    quaternion(_alloc, _init),
    euler_angles(_alloc, _init),
    acceleration(_alloc, _init),
    gyroscope(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->rotation_quality = 0l;
      this->gain = 0l;
      this->frame = 0ll;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _quaternion_type =
    geometry_msgs::msg::Quaternion_<ContainerAllocator>;
  _quaternion_type quaternion;
  using _euler_angles_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _euler_angles_type euler_angles;
  using _rotation_quality_type =
    int32_t;
  _rotation_quality_type rotation_quality;
  using _acceleration_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _acceleration_type acceleration;
  using _gyroscope_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _gyroscope_type gyroscope;
  using _strain_adc_type =
    std::vector<int64_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int64_t>>;
  _strain_adc_type strain_adc;
  using _base_resistance_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _base_resistance_type base_resistance;
  using _resistance_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _resistance_type resistance;
  using _strain_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _strain_type strain;
  using _base_length_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _base_length_type base_length;
  using _length_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _length_type length;
  using _gain_type =
    int32_t;
  _gain_type gain;
  using _frame_type =
    int64_t;
  _frame_type frame;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__quaternion(
    const geometry_msgs::msg::Quaternion_<ContainerAllocator> & _arg)
  {
    this->quaternion = _arg;
    return *this;
  }
  Type & set__euler_angles(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->euler_angles = _arg;
    return *this;
  }
  Type & set__rotation_quality(
    const int32_t & _arg)
  {
    this->rotation_quality = _arg;
    return *this;
  }
  Type & set__acceleration(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->acceleration = _arg;
    return *this;
  }
  Type & set__gyroscope(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->gyroscope = _arg;
    return *this;
  }
  Type & set__strain_adc(
    const std::vector<int64_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int64_t>> & _arg)
  {
    this->strain_adc = _arg;
    return *this;
  }
  Type & set__base_resistance(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->base_resistance = _arg;
    return *this;
  }
  Type & set__resistance(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->resistance = _arg;
    return *this;
  }
  Type & set__strain(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->strain = _arg;
    return *this;
  }
  Type & set__base_length(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->base_length = _arg;
    return *this;
  }
  Type & set__length(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->length = _arg;
    return *this;
  }
  Type & set__gain(
    const int32_t & _arg)
  {
    this->gain = _arg;
    return *this;
  }
  Type & set__frame(
    const int64_t & _arg)
  {
    this->frame = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    stretch_sensor_msgs::msg::NodeMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const stretch_sensor_msgs::msg::NodeMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<stretch_sensor_msgs::msg::NodeMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<stretch_sensor_msgs::msg::NodeMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      stretch_sensor_msgs::msg::NodeMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<stretch_sensor_msgs::msg::NodeMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      stretch_sensor_msgs::msg::NodeMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<stretch_sensor_msgs::msg::NodeMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<stretch_sensor_msgs::msg::NodeMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<stretch_sensor_msgs::msg::NodeMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__stretch_sensor_msgs__msg__NodeMessage
    std::shared_ptr<stretch_sensor_msgs::msg::NodeMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__stretch_sensor_msgs__msg__NodeMessage
    std::shared_ptr<stretch_sensor_msgs::msg::NodeMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NodeMessage_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->quaternion != other.quaternion) {
      return false;
    }
    if (this->euler_angles != other.euler_angles) {
      return false;
    }
    if (this->rotation_quality != other.rotation_quality) {
      return false;
    }
    if (this->acceleration != other.acceleration) {
      return false;
    }
    if (this->gyroscope != other.gyroscope) {
      return false;
    }
    if (this->strain_adc != other.strain_adc) {
      return false;
    }
    if (this->base_resistance != other.base_resistance) {
      return false;
    }
    if (this->resistance != other.resistance) {
      return false;
    }
    if (this->strain != other.strain) {
      return false;
    }
    if (this->base_length != other.base_length) {
      return false;
    }
    if (this->length != other.length) {
      return false;
    }
    if (this->gain != other.gain) {
      return false;
    }
    if (this->frame != other.frame) {
      return false;
    }
    return true;
  }
  bool operator!=(const NodeMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NodeMessage_

// alias to use template instance with default allocator
using NodeMessage =
  stretch_sensor_msgs::msg::NodeMessage_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace stretch_sensor_msgs

#endif  // STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE__STRUCT_HPP_
