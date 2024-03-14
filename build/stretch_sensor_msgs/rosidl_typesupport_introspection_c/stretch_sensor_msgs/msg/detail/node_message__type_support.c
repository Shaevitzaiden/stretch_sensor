// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from stretch_sensor_msgs:msg/NodeMessage.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "stretch_sensor_msgs/msg/detail/node_message__rosidl_typesupport_introspection_c.h"
#include "stretch_sensor_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "stretch_sensor_msgs/msg/detail/node_message__functions.h"
#include "stretch_sensor_msgs/msg/detail/node_message__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `quaternion`
#include "geometry_msgs/msg/quaternion.h"
// Member `quaternion`
#include "geometry_msgs/msg/detail/quaternion__rosidl_typesupport_introspection_c.h"
// Member `euler_angles`
// Member `acceleration`
// Member `gyroscope`
#include "geometry_msgs/msg/vector3.h"
// Member `euler_angles`
// Member `acceleration`
// Member `gyroscope`
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_introspection_c.h"
// Member `strain_adc`
// Member `base_resistance`
// Member `resistance`
// Member `strain`
// Member `base_length`
// Member `length`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__NodeMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  stretch_sensor_msgs__msg__NodeMessage__init(message_memory);
}

void stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__NodeMessage_fini_function(void * message_memory)
{
  stretch_sensor_msgs__msg__NodeMessage__fini(message_memory);
}

size_t stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__size_function__NodeMessage__strain_adc(
  const void * untyped_member)
{
  const rosidl_runtime_c__int64__Sequence * member =
    (const rosidl_runtime_c__int64__Sequence *)(untyped_member);
  return member->size;
}

const void * stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_const_function__NodeMessage__strain_adc(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int64__Sequence * member =
    (const rosidl_runtime_c__int64__Sequence *)(untyped_member);
  return &member->data[index];
}

void * stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_function__NodeMessage__strain_adc(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int64__Sequence * member =
    (rosidl_runtime_c__int64__Sequence *)(untyped_member);
  return &member->data[index];
}

void stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__fetch_function__NodeMessage__strain_adc(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int64_t * item =
    ((const int64_t *)
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_const_function__NodeMessage__strain_adc(untyped_member, index));
  int64_t * value =
    (int64_t *)(untyped_value);
  *value = *item;
}

void stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__assign_function__NodeMessage__strain_adc(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int64_t * item =
    ((int64_t *)
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_function__NodeMessage__strain_adc(untyped_member, index));
  const int64_t * value =
    (const int64_t *)(untyped_value);
  *item = *value;
}

bool stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__resize_function__NodeMessage__strain_adc(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int64__Sequence * member =
    (rosidl_runtime_c__int64__Sequence *)(untyped_member);
  rosidl_runtime_c__int64__Sequence__fini(member);
  return rosidl_runtime_c__int64__Sequence__init(member, size);
}

size_t stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__size_function__NodeMessage__base_resistance(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_const_function__NodeMessage__base_resistance(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_function__NodeMessage__base_resistance(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__fetch_function__NodeMessage__base_resistance(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_const_function__NodeMessage__base_resistance(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__assign_function__NodeMessage__base_resistance(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_function__NodeMessage__base_resistance(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__resize_function__NodeMessage__base_resistance(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__size_function__NodeMessage__resistance(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_const_function__NodeMessage__resistance(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_function__NodeMessage__resistance(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__fetch_function__NodeMessage__resistance(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_const_function__NodeMessage__resistance(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__assign_function__NodeMessage__resistance(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_function__NodeMessage__resistance(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__resize_function__NodeMessage__resistance(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__size_function__NodeMessage__strain(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_const_function__NodeMessage__strain(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_function__NodeMessage__strain(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__fetch_function__NodeMessage__strain(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_const_function__NodeMessage__strain(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__assign_function__NodeMessage__strain(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_function__NodeMessage__strain(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__resize_function__NodeMessage__strain(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__size_function__NodeMessage__base_length(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_const_function__NodeMessage__base_length(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_function__NodeMessage__base_length(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__fetch_function__NodeMessage__base_length(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_const_function__NodeMessage__base_length(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__assign_function__NodeMessage__base_length(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_function__NodeMessage__base_length(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__resize_function__NodeMessage__base_length(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__size_function__NodeMessage__length(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_const_function__NodeMessage__length(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_function__NodeMessage__length(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__fetch_function__NodeMessage__length(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_const_function__NodeMessage__length(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__assign_function__NodeMessage__length(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_function__NodeMessage__length(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__resize_function__NodeMessage__length(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__NodeMessage_message_member_array[14] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stretch_sensor_msgs__msg__NodeMessage, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "quaternion",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stretch_sensor_msgs__msg__NodeMessage, quaternion),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "euler_angles",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stretch_sensor_msgs__msg__NodeMessage, euler_angles),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rotation_quality",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stretch_sensor_msgs__msg__NodeMessage, rotation_quality),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "acceleration",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stretch_sensor_msgs__msg__NodeMessage, acceleration),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gyroscope",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stretch_sensor_msgs__msg__NodeMessage, gyroscope),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "strain_adc",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stretch_sensor_msgs__msg__NodeMessage, strain_adc),  // bytes offset in struct
    NULL,  // default value
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__size_function__NodeMessage__strain_adc,  // size() function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_const_function__NodeMessage__strain_adc,  // get_const(index) function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_function__NodeMessage__strain_adc,  // get(index) function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__fetch_function__NodeMessage__strain_adc,  // fetch(index, &value) function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__assign_function__NodeMessage__strain_adc,  // assign(index, value) function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__resize_function__NodeMessage__strain_adc  // resize(index) function pointer
  },
  {
    "base_resistance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stretch_sensor_msgs__msg__NodeMessage, base_resistance),  // bytes offset in struct
    NULL,  // default value
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__size_function__NodeMessage__base_resistance,  // size() function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_const_function__NodeMessage__base_resistance,  // get_const(index) function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_function__NodeMessage__base_resistance,  // get(index) function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__fetch_function__NodeMessage__base_resistance,  // fetch(index, &value) function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__assign_function__NodeMessage__base_resistance,  // assign(index, value) function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__resize_function__NodeMessage__base_resistance  // resize(index) function pointer
  },
  {
    "resistance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stretch_sensor_msgs__msg__NodeMessage, resistance),  // bytes offset in struct
    NULL,  // default value
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__size_function__NodeMessage__resistance,  // size() function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_const_function__NodeMessage__resistance,  // get_const(index) function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_function__NodeMessage__resistance,  // get(index) function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__fetch_function__NodeMessage__resistance,  // fetch(index, &value) function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__assign_function__NodeMessage__resistance,  // assign(index, value) function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__resize_function__NodeMessage__resistance  // resize(index) function pointer
  },
  {
    "strain",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stretch_sensor_msgs__msg__NodeMessage, strain),  // bytes offset in struct
    NULL,  // default value
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__size_function__NodeMessage__strain,  // size() function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_const_function__NodeMessage__strain,  // get_const(index) function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_function__NodeMessage__strain,  // get(index) function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__fetch_function__NodeMessage__strain,  // fetch(index, &value) function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__assign_function__NodeMessage__strain,  // assign(index, value) function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__resize_function__NodeMessage__strain  // resize(index) function pointer
  },
  {
    "base_length",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stretch_sensor_msgs__msg__NodeMessage, base_length),  // bytes offset in struct
    NULL,  // default value
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__size_function__NodeMessage__base_length,  // size() function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_const_function__NodeMessage__base_length,  // get_const(index) function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_function__NodeMessage__base_length,  // get(index) function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__fetch_function__NodeMessage__base_length,  // fetch(index, &value) function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__assign_function__NodeMessage__base_length,  // assign(index, value) function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__resize_function__NodeMessage__base_length  // resize(index) function pointer
  },
  {
    "length",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stretch_sensor_msgs__msg__NodeMessage, length),  // bytes offset in struct
    NULL,  // default value
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__size_function__NodeMessage__length,  // size() function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_const_function__NodeMessage__length,  // get_const(index) function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__get_function__NodeMessage__length,  // get(index) function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__fetch_function__NodeMessage__length,  // fetch(index, &value) function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__assign_function__NodeMessage__length,  // assign(index, value) function pointer
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__resize_function__NodeMessage__length  // resize(index) function pointer
  },
  {
    "gain",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stretch_sensor_msgs__msg__NodeMessage, gain),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "frame",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stretch_sensor_msgs__msg__NodeMessage, frame),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__NodeMessage_message_members = {
  "stretch_sensor_msgs__msg",  // message namespace
  "NodeMessage",  // message name
  14,  // number of fields
  sizeof(stretch_sensor_msgs__msg__NodeMessage),
  stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__NodeMessage_message_member_array,  // message members
  stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__NodeMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__NodeMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__NodeMessage_message_type_support_handle = {
  0,
  &stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__NodeMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_stretch_sensor_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, stretch_sensor_msgs, msg, NodeMessage)() {
  stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__NodeMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__NodeMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Quaternion)();
  stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__NodeMessage_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__NodeMessage_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__NodeMessage_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  if (!stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__NodeMessage_message_type_support_handle.typesupport_identifier) {
    stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__NodeMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &stretch_sensor_msgs__msg__NodeMessage__rosidl_typesupport_introspection_c__NodeMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
