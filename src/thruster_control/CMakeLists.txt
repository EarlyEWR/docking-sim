cmake_minimum_required(VERSION 3.5)
project(thruster_control)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

set(dependencies rclcpp std_msgs geometry_msgs)

rosidl_generate_interfaces(${PROJECT_NAME} "msg/ThrusterCommand.msg" DEPENDENCIES std_msgs)

include_directories(include)

add_library(${PROJECT_NAME}_nodes src/ThrusterControlNode.cpp)

ament_target_dependencies(${PROJECT_NAME}_nodes ${dependencies})
rosidl_target_interfaces(thruster_control_node ${PROJECT_NAME} "rosidl_typesupport_cpp")

install(TARGETS thruster_control_node DESTINATION lib/${PROJECT_NAME})
install(DIRECTORY config msg DESTINATION share/${PROJECT_NAME})

ament_export_dependencies(rosidl_default_runtime)
ament_package()