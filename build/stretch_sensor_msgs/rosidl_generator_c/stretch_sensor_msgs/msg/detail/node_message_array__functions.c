// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from stretch_sensor_msgs:msg/NodeMessageArray.idl
// generated code does not contain a copyright notice
#include "stretch_sensor_msgs/msg/detail/node_message_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `node_data`
#include "stretch_sensor_msgs/msg/detail/node_message__functions.h"

bool
stretch_sensor_msgs__msg__NodeMessageArray__init(stretch_sensor_msgs__msg__NodeMessageArray * msg)
{
  if (!msg) {
    return false;
  }
  // node_data
  if (!stretch_sensor_msgs__msg__NodeMessage__Sequence__init(&msg->node_data, 0)) {
    stretch_sensor_msgs__msg__NodeMessageArray__fini(msg);
    return false;
  }
  return true;
}

void
stretch_sensor_msgs__msg__NodeMessageArray__fini(stretch_sensor_msgs__msg__NodeMessageArray * msg)
{
  if (!msg) {
    return;
  }
  // node_data
  stretch_sensor_msgs__msg__NodeMessage__Sequence__fini(&msg->node_data);
}

bool
stretch_sensor_msgs__msg__NodeMessageArray__are_equal(const stretch_sensor_msgs__msg__NodeMessageArray * lhs, const stretch_sensor_msgs__msg__NodeMessageArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // node_data
  if (!stretch_sensor_msgs__msg__NodeMessage__Sequence__are_equal(
      &(lhs->node_data), &(rhs->node_data)))
  {
    return false;
  }
  return true;
}

bool
stretch_sensor_msgs__msg__NodeMessageArray__copy(
  const stretch_sensor_msgs__msg__NodeMessageArray * input,
  stretch_sensor_msgs__msg__NodeMessageArray * output)
{
  if (!input || !output) {
    return false;
  }
  // node_data
  if (!stretch_sensor_msgs__msg__NodeMessage__Sequence__copy(
      &(input->node_data), &(output->node_data)))
  {
    return false;
  }
  return true;
}

stretch_sensor_msgs__msg__NodeMessageArray *
stretch_sensor_msgs__msg__NodeMessageArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stretch_sensor_msgs__msg__NodeMessageArray * msg = (stretch_sensor_msgs__msg__NodeMessageArray *)allocator.allocate(sizeof(stretch_sensor_msgs__msg__NodeMessageArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(stretch_sensor_msgs__msg__NodeMessageArray));
  bool success = stretch_sensor_msgs__msg__NodeMessageArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
stretch_sensor_msgs__msg__NodeMessageArray__destroy(stretch_sensor_msgs__msg__NodeMessageArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    stretch_sensor_msgs__msg__NodeMessageArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
stretch_sensor_msgs__msg__NodeMessageArray__Sequence__init(stretch_sensor_msgs__msg__NodeMessageArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stretch_sensor_msgs__msg__NodeMessageArray * data = NULL;

  if (size) {
    data = (stretch_sensor_msgs__msg__NodeMessageArray *)allocator.zero_allocate(size, sizeof(stretch_sensor_msgs__msg__NodeMessageArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = stretch_sensor_msgs__msg__NodeMessageArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        stretch_sensor_msgs__msg__NodeMessageArray__fini(&data[i - 1]);
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
stretch_sensor_msgs__msg__NodeMessageArray__Sequence__fini(stretch_sensor_msgs__msg__NodeMessageArray__Sequence * array)
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
      stretch_sensor_msgs__msg__NodeMessageArray__fini(&array->data[i]);
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

stretch_sensor_msgs__msg__NodeMessageArray__Sequence *
stretch_sensor_msgs__msg__NodeMessageArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stretch_sensor_msgs__msg__NodeMessageArray__Sequence * array = (stretch_sensor_msgs__msg__NodeMessageArray__Sequence *)allocator.allocate(sizeof(stretch_sensor_msgs__msg__NodeMessageArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = stretch_sensor_msgs__msg__NodeMessageArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
stretch_sensor_msgs__msg__NodeMessageArray__Sequence__destroy(stretch_sensor_msgs__msg__NodeMessageArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    stretch_sensor_msgs__msg__NodeMessageArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
stretch_sensor_msgs__msg__NodeMessageArray__Sequence__are_equal(const stretch_sensor_msgs__msg__NodeMessageArray__Sequence * lhs, const stretch_sensor_msgs__msg__NodeMessageArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!stretch_sensor_msgs__msg__NodeMessageArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
stretch_sensor_msgs__msg__NodeMessageArray__Sequence__copy(
  const stretch_sensor_msgs__msg__NodeMessageArray__Sequence * input,
  stretch_sensor_msgs__msg__NodeMessageArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(stretch_sensor_msgs__msg__NodeMessageArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    stretch_sensor_msgs__msg__NodeMessageArray * data =
      (stretch_sensor_msgs__msg__NodeMessageArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!stretch_sensor_msgs__msg__NodeMessageArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          stretch_sensor_msgs__msg__NodeMessageArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!stretch_sensor_msgs__msg__NodeMessageArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
