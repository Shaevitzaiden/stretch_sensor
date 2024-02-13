// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from stretch_sensor_msgs:msg/Coords.idl
// generated code does not contain a copyright notice
#include "stretch_sensor_msgs/msg/detail/coords__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `coord`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
stretch_sensor_msgs__msg__Coords__init(stretch_sensor_msgs__msg__Coords * msg)
{
  if (!msg) {
    return false;
  }
  // coord
  if (!geometry_msgs__msg__Point__init(&msg->coord)) {
    stretch_sensor_msgs__msg__Coords__fini(msg);
    return false;
  }
  return true;
}

void
stretch_sensor_msgs__msg__Coords__fini(stretch_sensor_msgs__msg__Coords * msg)
{
  if (!msg) {
    return;
  }
  // coord
  geometry_msgs__msg__Point__fini(&msg->coord);
}

bool
stretch_sensor_msgs__msg__Coords__are_equal(const stretch_sensor_msgs__msg__Coords * lhs, const stretch_sensor_msgs__msg__Coords * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // coord
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->coord), &(rhs->coord)))
  {
    return false;
  }
  return true;
}

bool
stretch_sensor_msgs__msg__Coords__copy(
  const stretch_sensor_msgs__msg__Coords * input,
  stretch_sensor_msgs__msg__Coords * output)
{
  if (!input || !output) {
    return false;
  }
  // coord
  if (!geometry_msgs__msg__Point__copy(
      &(input->coord), &(output->coord)))
  {
    return false;
  }
  return true;
}

stretch_sensor_msgs__msg__Coords *
stretch_sensor_msgs__msg__Coords__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stretch_sensor_msgs__msg__Coords * msg = (stretch_sensor_msgs__msg__Coords *)allocator.allocate(sizeof(stretch_sensor_msgs__msg__Coords), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(stretch_sensor_msgs__msg__Coords));
  bool success = stretch_sensor_msgs__msg__Coords__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
stretch_sensor_msgs__msg__Coords__destroy(stretch_sensor_msgs__msg__Coords * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    stretch_sensor_msgs__msg__Coords__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
stretch_sensor_msgs__msg__Coords__Sequence__init(stretch_sensor_msgs__msg__Coords__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stretch_sensor_msgs__msg__Coords * data = NULL;

  if (size) {
    data = (stretch_sensor_msgs__msg__Coords *)allocator.zero_allocate(size, sizeof(stretch_sensor_msgs__msg__Coords), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = stretch_sensor_msgs__msg__Coords__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        stretch_sensor_msgs__msg__Coords__fini(&data[i - 1]);
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
stretch_sensor_msgs__msg__Coords__Sequence__fini(stretch_sensor_msgs__msg__Coords__Sequence * array)
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
      stretch_sensor_msgs__msg__Coords__fini(&array->data[i]);
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

stretch_sensor_msgs__msg__Coords__Sequence *
stretch_sensor_msgs__msg__Coords__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stretch_sensor_msgs__msg__Coords__Sequence * array = (stretch_sensor_msgs__msg__Coords__Sequence *)allocator.allocate(sizeof(stretch_sensor_msgs__msg__Coords__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = stretch_sensor_msgs__msg__Coords__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
stretch_sensor_msgs__msg__Coords__Sequence__destroy(stretch_sensor_msgs__msg__Coords__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    stretch_sensor_msgs__msg__Coords__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
stretch_sensor_msgs__msg__Coords__Sequence__are_equal(const stretch_sensor_msgs__msg__Coords__Sequence * lhs, const stretch_sensor_msgs__msg__Coords__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!stretch_sensor_msgs__msg__Coords__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
stretch_sensor_msgs__msg__Coords__Sequence__copy(
  const stretch_sensor_msgs__msg__Coords__Sequence * input,
  stretch_sensor_msgs__msg__Coords__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(stretch_sensor_msgs__msg__Coords);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    stretch_sensor_msgs__msg__Coords * data =
      (stretch_sensor_msgs__msg__Coords *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!stretch_sensor_msgs__msg__Coords__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          stretch_sensor_msgs__msg__Coords__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!stretch_sensor_msgs__msg__Coords__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
