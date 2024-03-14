// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from stretch_sensor_msgs:msg/NodeMessageArray.idl
// generated code does not contain a copyright notice

#ifndef STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE_ARRAY__FUNCTIONS_H_
#define STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "stretch_sensor_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "stretch_sensor_msgs/msg/detail/node_message_array__struct.h"

/// Initialize msg/NodeMessageArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * stretch_sensor_msgs__msg__NodeMessageArray
 * )) before or use
 * stretch_sensor_msgs__msg__NodeMessageArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_stretch_sensor_msgs
bool
stretch_sensor_msgs__msg__NodeMessageArray__init(stretch_sensor_msgs__msg__NodeMessageArray * msg);

/// Finalize msg/NodeMessageArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_stretch_sensor_msgs
void
stretch_sensor_msgs__msg__NodeMessageArray__fini(stretch_sensor_msgs__msg__NodeMessageArray * msg);

/// Create msg/NodeMessageArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * stretch_sensor_msgs__msg__NodeMessageArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_stretch_sensor_msgs
stretch_sensor_msgs__msg__NodeMessageArray *
stretch_sensor_msgs__msg__NodeMessageArray__create();

/// Destroy msg/NodeMessageArray message.
/**
 * It calls
 * stretch_sensor_msgs__msg__NodeMessageArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_stretch_sensor_msgs
void
stretch_sensor_msgs__msg__NodeMessageArray__destroy(stretch_sensor_msgs__msg__NodeMessageArray * msg);

/// Check for msg/NodeMessageArray message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_stretch_sensor_msgs
bool
stretch_sensor_msgs__msg__NodeMessageArray__are_equal(const stretch_sensor_msgs__msg__NodeMessageArray * lhs, const stretch_sensor_msgs__msg__NodeMessageArray * rhs);

/// Copy a msg/NodeMessageArray message.
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
stretch_sensor_msgs__msg__NodeMessageArray__copy(
  const stretch_sensor_msgs__msg__NodeMessageArray * input,
  stretch_sensor_msgs__msg__NodeMessageArray * output);

/// Initialize array of msg/NodeMessageArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * stretch_sensor_msgs__msg__NodeMessageArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_stretch_sensor_msgs
bool
stretch_sensor_msgs__msg__NodeMessageArray__Sequence__init(stretch_sensor_msgs__msg__NodeMessageArray__Sequence * array, size_t size);

/// Finalize array of msg/NodeMessageArray messages.
/**
 * It calls
 * stretch_sensor_msgs__msg__NodeMessageArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_stretch_sensor_msgs
void
stretch_sensor_msgs__msg__NodeMessageArray__Sequence__fini(stretch_sensor_msgs__msg__NodeMessageArray__Sequence * array);

/// Create array of msg/NodeMessageArray messages.
/**
 * It allocates the memory for the array and calls
 * stretch_sensor_msgs__msg__NodeMessageArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_stretch_sensor_msgs
stretch_sensor_msgs__msg__NodeMessageArray__Sequence *
stretch_sensor_msgs__msg__NodeMessageArray__Sequence__create(size_t size);

/// Destroy array of msg/NodeMessageArray messages.
/**
 * It calls
 * stretch_sensor_msgs__msg__NodeMessageArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_stretch_sensor_msgs
void
stretch_sensor_msgs__msg__NodeMessageArray__Sequence__destroy(stretch_sensor_msgs__msg__NodeMessageArray__Sequence * array);

/// Check for msg/NodeMessageArray message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_stretch_sensor_msgs
bool
stretch_sensor_msgs__msg__NodeMessageArray__Sequence__are_equal(const stretch_sensor_msgs__msg__NodeMessageArray__Sequence * lhs, const stretch_sensor_msgs__msg__NodeMessageArray__Sequence * rhs);

/// Copy an array of msg/NodeMessageArray messages.
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
stretch_sensor_msgs__msg__NodeMessageArray__Sequence__copy(
  const stretch_sensor_msgs__msg__NodeMessageArray__Sequence * input,
  stretch_sensor_msgs__msg__NodeMessageArray__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // STRETCH_SENSOR_MSGS__MSG__DETAIL__NODE_MESSAGE_ARRAY__FUNCTIONS_H_
