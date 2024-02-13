// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from stretch_sensor_msgs:msg/Coords.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "stretch_sensor_msgs/msg/detail/coords__rosidl_typesupport_introspection_c.h"
#include "stretch_sensor_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "stretch_sensor_msgs/msg/detail/coords__functions.h"
#include "stretch_sensor_msgs/msg/detail/coords__struct.h"


// Include directives for member types
// Member `coord`
#include "geometry_msgs/msg/point.h"
// Member `coord`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void stretch_sensor_msgs__msg__Coords__rosidl_typesupport_introspection_c__Coords_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  stretch_sensor_msgs__msg__Coords__init(message_memory);
}

void stretch_sensor_msgs__msg__Coords__rosidl_typesupport_introspection_c__Coords_fini_function(void * message_memory)
{
  stretch_sensor_msgs__msg__Coords__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember stretch_sensor_msgs__msg__Coords__rosidl_typesupport_introspection_c__Coords_message_member_array[1] = {
  {
    "coord",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stretch_sensor_msgs__msg__Coords, coord),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers stretch_sensor_msgs__msg__Coords__rosidl_typesupport_introspection_c__Coords_message_members = {
  "stretch_sensor_msgs__msg",  // message namespace
  "Coords",  // message name
  1,  // number of fields
  sizeof(stretch_sensor_msgs__msg__Coords),
  stretch_sensor_msgs__msg__Coords__rosidl_typesupport_introspection_c__Coords_message_member_array,  // message members
  stretch_sensor_msgs__msg__Coords__rosidl_typesupport_introspection_c__Coords_init_function,  // function to initialize message memory (memory has to be allocated)
  stretch_sensor_msgs__msg__Coords__rosidl_typesupport_introspection_c__Coords_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t stretch_sensor_msgs__msg__Coords__rosidl_typesupport_introspection_c__Coords_message_type_support_handle = {
  0,
  &stretch_sensor_msgs__msg__Coords__rosidl_typesupport_introspection_c__Coords_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_stretch_sensor_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, stretch_sensor_msgs, msg, Coords)() {
  stretch_sensor_msgs__msg__Coords__rosidl_typesupport_introspection_c__Coords_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!stretch_sensor_msgs__msg__Coords__rosidl_typesupport_introspection_c__Coords_message_type_support_handle.typesupport_identifier) {
    stretch_sensor_msgs__msg__Coords__rosidl_typesupport_introspection_c__Coords_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &stretch_sensor_msgs__msg__Coords__rosidl_typesupport_introspection_c__Coords_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
