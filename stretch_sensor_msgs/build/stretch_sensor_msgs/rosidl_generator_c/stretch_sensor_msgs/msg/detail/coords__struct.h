// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from stretch_sensor_msgs:msg/Coords.idl
// generated code does not contain a copyright notice

#ifndef STRETCH_SENSOR_MSGS__MSG__DETAIL__COORDS__STRUCT_H_
#define STRETCH_SENSOR_MSGS__MSG__DETAIL__COORDS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'coord'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/Coords in the package stretch_sensor_msgs.
typedef struct stretch_sensor_msgs__msg__Coords
{
  geometry_msgs__msg__Point coord;
} stretch_sensor_msgs__msg__Coords;

// Struct for a sequence of stretch_sensor_msgs__msg__Coords.
typedef struct stretch_sensor_msgs__msg__Coords__Sequence
{
  stretch_sensor_msgs__msg__Coords * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} stretch_sensor_msgs__msg__Coords__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // STRETCH_SENSOR_MSGS__MSG__DETAIL__COORDS__STRUCT_H_
