// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from stretch_sensor_msgs:msg/NodeMessage.idl
// generated code does not contain a copyright notice

#ifndef STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE__STRUCT_H_
#define STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'quaternion'
#include "geometry_msgs/msg/detail/quaternion__struct.h"
// Member 'euler_angles'
// Member 'acceleration'
// Member 'gyroscope'
#include "geometry_msgs/msg/detail/vector3__struct.h"
// Member 'strain_adc'
// Member 'base_resistance'
// Member 'resistance'
// Member 'strain'
// Member 'base_length'
// Member 'length'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/NodeMessage in the package stretch_sensor_msgs.
/**
  * Header
 */
typedef struct stretch_sensor_msgs__msg__NodeMessage
{
  std_msgs__msg__Header header;
  /// Orientation
  geometry_msgs__msg__Quaternion quaternion;
  geometry_msgs__msg__Vector3 euler_angles;
  int32_t rotation_quality;
  /// Accelerometer
  geometry_msgs__msg__Vector3 acceleration;
  /// Gyroscope
  geometry_msgs__msg__Vector3 gyroscope;
  /// Strain sensor
  rosidl_runtime_c__int64__Sequence strain_adc;
  rosidl_runtime_c__double__Sequence base_resistance;
  rosidl_runtime_c__double__Sequence resistance;
  rosidl_runtime_c__double__Sequence strain;
  rosidl_runtime_c__double__Sequence base_length;
  rosidl_runtime_c__double__Sequence length;
  /// Gain
  int32_t gain;
  /// Node frame
  int64_t frame;
} stretch_sensor_msgs__msg__NodeMessage;

// Struct for a sequence of stretch_sensor_msgs__msg__NodeMessage.
typedef struct stretch_sensor_msgs__msg__NodeMessage__Sequence
{
  stretch_sensor_msgs__msg__NodeMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} stretch_sensor_msgs__msg__NodeMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE__STRUCT_H_
