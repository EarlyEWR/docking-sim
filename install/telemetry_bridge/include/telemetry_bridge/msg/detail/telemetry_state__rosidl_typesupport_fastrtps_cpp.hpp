// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from telemetry_bridge:msg/TelemetryState.idl
// generated code does not contain a copyright notice

#ifndef TELEMETRY_BRIDGE__MSG__DETAIL__TELEMETRY_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define TELEMETRY_BRIDGE__MSG__DETAIL__TELEMETRY_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "telemetry_bridge/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "telemetry_bridge/msg/detail/telemetry_state__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace telemetry_bridge
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_telemetry_bridge
cdr_serialize(
  const telemetry_bridge::msg::TelemetryState & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_telemetry_bridge
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  telemetry_bridge::msg::TelemetryState & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_telemetry_bridge
get_serialized_size(
  const telemetry_bridge::msg::TelemetryState & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_telemetry_bridge
max_serialized_size_TelemetryState(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace telemetry_bridge

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_telemetry_bridge
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, telemetry_bridge, msg, TelemetryState)();

#ifdef __cplusplus
}
#endif

#endif  // TELEMETRY_BRIDGE__MSG__DETAIL__TELEMETRY_STATE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
