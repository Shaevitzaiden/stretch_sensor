// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from stretch_sensor_msgs:msg/NodeMessageArray.idl
// generated code does not contain a copyright notice

#ifndef STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE_ARRAY__STRUCT_H_
#define STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'node_data'
#include "stretch_sensor_msgs/msg/detail/node_message__struct.h"

/// Struct defined in msg/NodeMessageArray in the package stretch_sensor_msgs.
/**
  * Just an array of node messages
 */
typedef struct stretch_sensor_msgs__msg__NodeMessageArray
{
  stretch_sensor_msgs__msg__NodeMessage__Sequence node_data;
} stretch_sensor_msgs__msg__NodeMessageArray;

// Struct for a sequence of stretch_sensor_msgs__msg__NodeMessageArray.
typedef struct stretch_sensor_msgs__msg__NodeMessageArray__Sequence
{
  stretch_sensor_msgs__msg__NodeMessageArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} stretch_sensor_msgs__msg__NodeMessageArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE_ARRAY__STRUCT_H_
