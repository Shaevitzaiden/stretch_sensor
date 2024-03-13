// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from stretch_sensor_msgs:msg/NodeMessageArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "stretch_sensor_msgs/msg/detail/node_message_array__rosidl_typesupport_introspection_c.h"
#include "stretch_sensor_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "stretch_sensor_msgs/msg/detail/node_message_array__functions.h"
#include "stretch_sensor_msgs/msg/detail/node_message_array__struct.h"


// Include directives for member types
// Member `node_data`
#include "stretch_sensor_msgs/msg/node_message.h"
// Member `node_data`
#include "stretch_sensor_msgs/msg/detail/node_message__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__NodeMessageArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  stretch_sensor_msgs__msg__NodeMessageArray__init(message_memory);
}

void stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__NodeMessageArray_fini_function(void * message_memory)
{
  stretch_sensor_msgs__msg__NodeMessageArray__fini(message_memory);
}

size_t stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__size_function__NodeMessageArray__node_data(
  const void * untyped_member)
{
  const stretch_sensor_msgs__msg__NodeMessage__Sequence * member =
    (const stretch_sensor_msgs__msg__NodeMessage__Sequence *)(untyped_member);
  return member->size;
}

const void * stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__get_const_function__NodeMessageArray__node_data(
  const void * untyped_member, size_t index)
{
  const stretch_sensor_msgs__msg__NodeMessage__Sequence * member =
    (const stretch_sensor_msgs__msg__NodeMessage__Sequence *)(untyped_member);
  return &member->data[index];
}

void * stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__get_function__NodeMessageArray__node_data(
  void * untyped_member, size_t index)
{
  stretch_sensor_msgs__msg__NodeMessage__Sequence * member =
    (stretch_sensor_msgs__msg__NodeMessage__Sequence *)(untyped_member);
  return &member->data[index];
}

void stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__fetch_function__NodeMessageArray__node_data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const stretch_sensor_msgs__msg__NodeMessage * item =
    ((const stretch_sensor_msgs__msg__NodeMessage *)
    stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__get_const_function__NodeMessageArray__node_data(untyped_member, index));
  stretch_sensor_msgs__msg__NodeMessage * value =
    (stretch_sensor_msgs__msg__NodeMessage *)(untyped_value);
  *value = *item;
}

void stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__assign_function__NodeMessageArray__node_data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  stretch_sensor_msgs__msg__NodeMessage * item =
    ((stretch_sensor_msgs__msg__NodeMessage *)
    stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__get_function__NodeMessageArray__node_data(untyped_member, index));
  const stretch_sensor_msgs__msg__NodeMessage * value =
    (const stretch_sensor_msgs__msg__NodeMessage *)(untyped_value);
  *item = *value;
}

bool stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__resize_function__NodeMessageArray__node_data(
  void * untyped_member, size_t size)
{
  stretch_sensor_msgs__msg__NodeMessage__Sequence * member =
    (stretch_sensor_msgs__msg__NodeMessage__Sequence *)(untyped_member);
  stretch_sensor_msgs__msg__NodeMessage__Sequence__fini(member);
  return stretch_sensor_msgs__msg__NodeMessage__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__NodeMessageArray_message_member_array[1] = {
  {
    "node_data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stretch_sensor_msgs__msg__NodeMessageArray, node_data),  // bytes offset in struct
    NULL,  // default value
    stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__size_function__NodeMessageArray__node_data,  // size() function pointer
    stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__get_const_function__NodeMessageArray__node_data,  // get_const(index) function pointer
    stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__get_function__NodeMessageArray__node_data,  // get(index) function pointer
    stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__fetch_function__NodeMessageArray__node_data,  // fetch(index, &value) function pointer
    stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__assign_function__NodeMessageArray__node_data,  // assign(index, value) function pointer
    stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__resize_function__NodeMessageArray__node_data  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__NodeMessageArray_message_members = {
  "stretch_sensor_msgs__msg",  // message namespace
  "NodeMessageArray",  // message name
  1,  // number of fields
  sizeof(stretch_sensor_msgs__msg__NodeMessageArray),
  stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__NodeMessageArray_message_member_array,  // message members
  stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__NodeMessageArray_init_function,  // function to initialize message memory (memory has to be allocated)
  stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__NodeMessageArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__NodeMessageArray_message_type_support_handle = {
  0,
  &stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__NodeMessageArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_stretch_sensor_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, stretch_sensor_msgs, msg, NodeMessageArray)() {
  stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__NodeMessageArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, stretch_sensor_msgs, msg, NodeMessage)();
  if (!stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__NodeMessageArray_message_type_support_handle.typesupport_identifier) {
    stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__NodeMessageArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &stretch_sensor_msgs__msg__NodeMessageArray__rosidl_typesupport_introspection_c__NodeMessageArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
