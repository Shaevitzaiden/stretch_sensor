// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from stretch_sensor_msgs:msg/NodeMessage.idl
// generated code does not contain a copyright notice

#ifndef STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE__FUNCTIONS_H_
#define STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "stretch_sensor_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "stretch_sensor_msgs/msg/detail/node_message__struct.h"

/// Initialize msg/NodeMessage message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * stretch_sensor_msgs__msg__NodeMessage
 * )) before or use
 * stretch_sensor_msgs__msg__NodeMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_stretch_sensor_msgs
bool
stretch_sensor_msgs__msg__NodeMessage__init(stretch_sensor_msgs__msg__NodeMessage * msg);

/// Finalize msg/NodeMessage message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_stretch_sensor_msgs
void
stretch_sensor_msgs__msg__NodeMessage__fini(stretch_sensor_msgs__msg__NodeMessage * msg);

/// Create msg/NodeMessage message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * stretch_sensor_msgs__msg__NodeMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_stretch_sensor_msgs
stretch_sensor_msgs__msg__NodeMessage *
stretch_sensor_msgs__msg__NodeMessage__create();

/// Destroy msg/NodeMessage message.
/**
 * It calls
 * stretch_sensor_msgs__msg__NodeMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_stretch_sensor_msgs
void
stretch_sensor_msgs__msg__NodeMessage__destroy(stretch_sensor_msgs__msg__NodeMessage * msg);

/// Check for msg/NodeMessage message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_stretch_sensor_msgs
bool
stretch_sensor_msgs__msg__NodeMessage__are_equal(const stretch_sensor_msgs__msg__NodeMessage * lhs, const stretch_sensor_msgs__msg__NodeMessage * rhs);

/// Copy a msg/NodeMessage message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_stretch_sensor_msgs
bool
stretch_sensor_msgs__msg__NodeMessage__copy(
  const stretch_sensor_msgs__msg__NodeMessage * input,
  stretch_sensor_msgs__msg__NodeMessage * output);

/// Initialize array of msg/NodeMessage messages.
/**
 * It allocates the memory for the number of elements and calls
 * stretch_sensor_msgs__msg__NodeMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_stretch_sensor_msgs
bool
stretch_sensor_msgs__msg__NodeMessage__Sequence__init(stretch_sensor_msgs__msg__NodeMessage__Sequence * array, size_t size);

/// Finalize array of msg/NodeMessage messages.
/**
 * It calls
 * stretch_sensor_msgs__msg__NodeMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_stretch_sensor_msgs
void
stretch_sensor_msgs__msg__NodeMessage__Sequence__fini(stretch_sensor_msgs__msg__NodeMessage__Sequence * array);

/// Create array of msg/NodeMessage messages.
/**
 * It allocates the memory for the array and calls
 * stretch_sensor_msgs__msg__NodeMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_stretch_sensor_msgs
stretch_sensor_msgs__msg__NodeMessage__Sequence *
stretch_sensor_msgs__msg__NodeMessage__Sequence__create(size_t size);

/// Destroy array of msg/NodeMessage messages.
/**
 * It calls
 * stretch_sensor_msgs__msg__NodeMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_stretch_sensor_msgs
void
stretch_sensor_msgs__msg__NodeMessage__Sequence__destroy(stretch_sensor_msgs__msg__NodeMessage__Sequence * array);

/// Check for msg/NodeMessage message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_stretch_sensor_msgs
bool
stretch_sensor_msgs__msg__NodeMessage__Sequence__are_equal(const stretch_sensor_msgs__msg__NodeMessage__Sequence * lhs, const stretch_sensor_msgs__msg__NodeMessage__Sequence * rhs);

/// Copy an array of msg/NodeMessage messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_stretch_sensor_msgs
bool
stretch_sensor_msgs__msg__NodeMessage__Sequence__copy(
  const stretch_sensor_msgs__msg__NodeMessage__Sequence * input,
  stretch_sensor_msgs__msg__NodeMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE__FUNCTIONS_H_
