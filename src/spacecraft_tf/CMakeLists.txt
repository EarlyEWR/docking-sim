cmake_minimum_required(VERSION 3.5)
project(spacecraft_tf)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(telemetry_bridge REQUIRED)

set(dependencies rclcpp tf2_ros geometry_msgs telemetry_bridge)

include_directories(include)

add_library(${PROJECT_NAME}_nodes src/SpacecraftTfNode.cpp)
ament_target_dependencies(${PROJECT_NAME}_nodes ${dependencies})

add_executable(spacecraft_tf_node src/main.cpp)
target_link_libraries(spacecraft_tf_node ${PROJECT_NAME}_nodes)
ament_target_dependencies(spacecraft_tf_node ${dependencies})

install(TARGETS spacecraft_tf_node DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY config DESTINATION share/${PROJECT_NAME})

ament_package()
