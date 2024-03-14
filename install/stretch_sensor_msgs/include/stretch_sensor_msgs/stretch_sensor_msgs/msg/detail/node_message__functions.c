// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from stretch_sensor_msgs:msg/NodeMessage.idl
// generated code does not contain a copyright notice
#include "stretch_sensor_msgs/msg/detail/node_message__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `quaternion`
#include "geometry_msgs/msg/detail/quaternion__functions.h"
// Member `euler_angles`
// Member `acceleration`
// Member `gyroscope`
#include "geometry_msgs/msg/detail/vector3__functions.h"
// Member `strain_adc`
// Member `base_resistance`
// Member `resistance`
// Member `strain`
// Member `base_length`
// Member `length`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
stretch_sensor_msgs__msg__NodeMessage__init(stretch_sensor_msgs__msg__NodeMessage * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    stretch_sensor_msgs__msg__NodeMessage__fini(msg);
    return false;
  }
  // quaternion
  if (!geometry_msgs__msg__Quaternion__init(&msg->quaternion)) {
    stretch_sensor_msgs__msg__NodeMessage__fini(msg);
    return false;
  }
  // euler_angles
  if (!geometry_msgs__msg__Vector3__init(&msg->euler_angles)) {
    stretch_sensor_msgs__msg__NodeMessage__fini(msg);
    return false;
  }
  // rotation_quality
  // acceleration
  if (!geometry_msgs__msg__Vector3__init(&msg->acceleration)) {
    stretch_sensor_msgs__msg__NodeMessage__fini(msg);
    return false;
  }
  // gyroscope
  if (!geometry_msgs__msg__Vector3__init(&msg->gyroscope)) {
    stretch_sensor_msgs__msg__NodeMessage__fini(msg);
    return false;
  }
  // strain_adc
  if (!rosidl_runtime_c__int64__Sequence__init(&msg->strain_adc, 0)) {
    stretch_sensor_msgs__msg__NodeMessage__fini(msg);
    return false;
  }
  // base_resistance
  if (!rosidl_runtime_c__double__Sequence__init(&msg->base_resistance, 0)) {
    stretch_sensor_msgs__msg__NodeMessage__fini(msg);
    return false;
  }
  // resistance
  if (!rosidl_runtime_c__double__Sequence__init(&msg->resistance, 0)) {
    stretch_sensor_msgs__msg__NodeMessage__fini(msg);
    return false;
  }
  // strain
  if (!rosidl_runtime_c__double__Sequence__init(&msg->strain, 0)) {
    stretch_sensor_msgs__msg__NodeMessage__fini(msg);
    return false;
  }
  // base_length
  if (!rosidl_runtime_c__double__Sequence__init(&msg->base_length, 0)) {
    stretch_sensor_msgs__msg__NodeMessage__fini(msg);
    return false;
  }
  // length
  if (!rosidl_runtime_c__double__Sequence__init(&msg->length, 0)) {
    stretch_sensor_msgs__msg__NodeMessage__fini(msg);
    return false;
  }
  // gain
  // frame
  return true;
}

void
stretch_sensor_msgs__msg__NodeMessage__fini(stretch_sensor_msgs__msg__NodeMessage * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // quaternion
  geometry_msgs__msg__Quaternion__fini(&msg->quaternion);
  // euler_angles
  geometry_msgs__msg__Vector3__fini(&msg->euler_angles);
  // rotation_quality
  // acceleration
  geometry_msgs__msg__Vector3__fini(&msg->acceleration);
  // gyroscope
  geometry_msgs__msg__Vector3__fini(&msg->gyroscope);
  // strain_adc
  rosidl_runtime_c__int64__Sequence__fini(&msg->strain_adc);
  // base_resistance
  rosidl_runtime_c__double__Sequence__fini(&msg->base_resistance);
  // resistance
  rosidl_runtime_c__double__Sequence__fini(&msg->resistance);
  // strain
  rosidl_runtime_c__double__Sequence__fini(&msg->strain);
  // base_length
  rosidl_runtime_c__double__Sequence__fini(&msg->base_length);
  // length
  rosidl_runtime_c__double__Sequence__fini(&msg->length);
  // gain
  // frame
}

bool
stretch_sensor_msgs__msg__NodeMessage__are_equal(const stretch_sensor_msgs__msg__NodeMessage * lhs, const stretch_sensor_msgs__msg__NodeMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // quaternion
  if (!geometry_msgs__msg__Quaternion__are_equal(
      &(lhs->quaternion), &(rhs->quaternion)))
  {
    return false;
  }
  // euler_angles
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->euler_angles), &(rhs->euler_angles)))
  {
    return false;
  }
  // rotation_quality
  if (lhs->rotation_quality != rhs->rotation_quality) {
    return false;
  }
  // acceleration
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->acceleration), &(rhs->acceleration)))
  {
    return false;
  }
  // gyroscope
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->gyroscope), &(rhs->gyroscope)))
  {
    return false;
  }
  // strain_adc
  if (!rosidl_runtime_c__int64__Sequence__are_equal(
      &(lhs->strain_adc), &(rhs->strain_adc)))
  {
    return false;
  }
  // base_resistance
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->base_resistance), &(rhs->base_resistance)))
  {
    return false;
  }
  // resistance
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->resistance), &(rhs->resistance)))
  {
    return false;
  }
  // strain
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->strain), &(rhs->strain)))
  {
    return false;
  }
  // base_length
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->base_length), &(rhs->base_length)))
  {
    return false;
  }
  // length
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->length), &(rhs->length)))
  {
    return false;
  }
  // gain
  if (lhs->gain != rhs->gain) {
    return false;
  }
  // frame
  if (lhs->frame != rhs->frame) {
    return false;
  }
  return true;
}

bool
stretch_sensor_msgs__msg__NodeMessage__copy(
  const stretch_sensor_msgs__msg__NodeMessage * input,
  stretch_sensor_msgs__msg__NodeMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // quaternion
  if (!geometry_msgs__msg__Quaternion__copy(
      &(input->quaternion), &(output->quaternion)))
  {
    return false;
  }
  // euler_angles
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->euler_angles), &(output->euler_angles)))
  {
    return false;
  }
  // rotation_quality
  output->rotation_quality = input->rotation_quality;
  // acceleration
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->acceleration), &(output->acceleration)))
  {
    return false;
  }
  // gyroscope
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->gyroscope), &(output->gyroscope)))
  {
    return false;
  }
  // strain_adc
  if (!rosidl_runtime_c__int64__Sequence__copy(
      &(input->strain_adc), &(output->strain_adc)))
  {
    return false;
  }
  // base_resistance
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->base_resistance), &(output->base_resistance)))
  {
    return false;
  }
  // resistance
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->resistance), &(output->resistance)))
  {
    return false;
  }
  // strain
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->strain), &(output->strain)))
  {
    return false;
  }
  // base_length
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->base_length), &(output->base_length)))
  {
    return false;
  }
  // length
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->length), &(output->length)))
  {
    return false;
  }
  // gain
  output->gain = input->gain;
  // frame
  output->frame = input->frame;
  return true;
}

stretch_sensor_msgs__msg__NodeMessage *
stretch_sensor_msgs__msg__NodeMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stretch_sensor_msgs__msg__NodeMessage * msg = (stretch_sensor_msgs__msg__NodeMessage *)allocator.allocate(sizeof(stretch_sensor_msgs__msg__NodeMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(stretch_sensor_msgs__msg__NodeMessage));
  bool success = stretch_sensor_msgs__msg__NodeMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
stretch_sensor_msgs__msg__NodeMessage__destroy(stretch_sensor_msgs__msg__NodeMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    stretch_sensor_msgs__msg__NodeMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
stretch_sensor_msgs__msg__NodeMessage__Sequence__init(stretch_sensor_msgs__msg__NodeMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stretch_sensor_msgs__msg__NodeMessage * data = NULL;

  if (size) {
    data = (stretch_sensor_msgs__msg__NodeMessage *)allocator.zero_allocate(size, sizeof(stretch_sensor_msgs__msg__NodeMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = stretch_sensor_msgs__msg__NodeMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        stretch_sensor_msgs__msg__NodeMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
stretch_sensor_msgs__msg__NodeMessage__Sequence__fini(stretch_sensor_msgs__msg__NodeMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      stretch_sensor_msgs__msg__NodeMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

stretch_sensor_msgs__msg__NodeMessage__Sequence *
stretch_sensor_msgs__msg__NodeMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stretch_sensor_msgs__msg__NodeMessage__Sequence * array = (stretch_sensor_msgs__msg__NodeMessage__Sequence *)allocator.allocate(sizeof(stretch_sensor_msgs__msg__NodeMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = stretch_sensor_msgs__msg__NodeMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
stretch_sensor_msgs__msg__NodeMessage__Sequence__destroy(stretch_sensor_msgs__msg__NodeMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    stretch_sensor_msgs__msg__NodeMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
stretch_sensor_msgs__msg__NodeMessage__Sequence__are_equal(const stretch_sensor_msgs__msg__NodeMessage__Sequence * lhs, const stretch_sensor_msgs__msg__NodeMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!stretch_sensor_msgs__msg__NodeMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
stretch_sensor_msgs__msg__NodeMessage__Sequence__copy(
  const stretch_sensor_msgs__msg__NodeMessage__Sequence * input,
  stretch_sensor_msgs__msg__NodeMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(stretch_sensor_msgs__msg__NodeMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    stretch_sensor_msgs__msg__NodeMessage * data =
      (stretch_sensor_msgs__msg__NodeMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!stretch_sensor_msgs__msg__NodeMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          stretch_sensor_msgs__msg__NodeMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!stretch_sensor_msgs__msg__NodeMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
