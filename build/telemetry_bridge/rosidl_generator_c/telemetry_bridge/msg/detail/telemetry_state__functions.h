// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from telemetry_bridge:msg/TelemetryState.idl
// generated code does not contain a copyright notice

#ifndef TELEMETRY_BRIDGE__MSG__DETAIL__TELEMETRY_STATE__FUNCTIONS_H_
#define TELEMETRY_BRIDGE__MSG__DETAIL__TELEMETRY_STATE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "telemetry_bridge/msg/rosidl_generator_c__visibility_control.h"

#include "telemetry_bridge/msg/detail/telemetry_state__struct.h"

/// Initialize msg/TelemetryState message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * telemetry_bridge__msg__TelemetryState
 * )) before or use
 * telemetry_bridge__msg__TelemetryState__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_telemetry_bridge
bool
telemetry_bridge__msg__TelemetryState__init(telemetry_bridge__msg__TelemetryState * msg);

/// Finalize msg/TelemetryState message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_telemetry_bridge
void
telemetry_bridge__msg__TelemetryState__fini(telemetry_bridge__msg__TelemetryState * msg);

/// Create msg/TelemetryState message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * telemetry_bridge__msg__TelemetryState__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_telemetry_bridge
telemetry_bridge__msg__TelemetryState *
telemetry_bridge__msg__TelemetryState__create();

/// Destroy msg/TelemetryState message.
/**
 * It calls
 * telemetry_bridge__msg__TelemetryState__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_telemetry_bridge
void
telemetry_bridge__msg__TelemetryState__destroy(telemetry_bridge__msg__TelemetryState * msg);

/// Check for msg/TelemetryState message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_telemetry_bridge
bool
telemetry_bridge__msg__TelemetryState__are_equal(const telemetry_bridge__msg__TelemetryState * lhs, const telemetry_bridge__msg__TelemetryState * rhs);

/// Copy a msg/TelemetryState message.
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
ROSIDL_GENERATOR_C_PUBLIC_telemetry_bridge
bool
telemetry_bridge__msg__TelemetryState__copy(
  const telemetry_bridge__msg__TelemetryState * input,
  telemetry_bridge__msg__TelemetryState * output);

/// Initialize array of msg/TelemetryState messages.
/**
 * It allocates the memory for the number of elements and calls
 * telemetry_bridge__msg__TelemetryState__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_telemetry_bridge
bool
telemetry_bridge__msg__TelemetryState__Sequence__init(telemetry_bridge__msg__TelemetryState__Sequence * array, size_t size);

/// Finalize array of msg/TelemetryState messages.
/**
 * It calls
 * telemetry_bridge__msg__TelemetryState__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_telemetry_bridge
void
telemetry_bridge__msg__TelemetryState__Sequence__fini(telemetry_bridge__msg__TelemetryState__Sequence * array);

/// Create array of msg/TelemetryState messages.
/**
 * It allocates the memory for the array and calls
 * telemetry_bridge__msg__TelemetryState__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_telemetry_bridge
telemetry_bridge__msg__TelemetryState__Sequence *
telemetry_bridge__msg__TelemetryState__Sequence__create(size_t size);

/// Destroy array of msg/TelemetryState messages.
/**
 * It calls
 * telemetry_bridge__msg__TelemetryState__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_telemetry_bridge
void
telemetry_bridge__msg__TelemetryState__Sequence__destroy(telemetry_bridge__msg__TelemetryState__Sequence * array);

/// Check for msg/TelemetryState message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_telemetry_bridge
bool
telemetry_bridge__msg__TelemetryState__Sequence__are_equal(const telemetry_bridge__msg__TelemetryState__Sequence * lhs, const telemetry_bridge__msg__TelemetryState__Sequence * rhs);

/// Copy an array of msg/TelemetryState messages.
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
ROSIDL_GENERATOR_C_PUBLIC_telemetry_bridge
bool
telemetry_bridge__msg__TelemetryState__Sequence__copy(
  const telemetry_bridge__msg__TelemetryState__Sequence * input,
  telemetry_bridge__msg__TelemetryState__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TELEMETRY_BRIDGE__MSG__DETAIL__TELEMETRY_STATE__FUNCTIONS_H_
