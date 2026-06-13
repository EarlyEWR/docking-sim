#include "rosidl_typesupport_introspection_cpp/rclcpp"
#include "spacecraft_tf/SpacecraftTfNode.hpp"

int main(int argc, char * arv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<spacecraft_tf::SpacecraftTfNode>());
    rclcpp::shutdown();
    return 0;
}