#include "rclcpp/rclcpp.hpp"
#include "thruster_control/ThrusterControlNode.hpp"

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<thruster_control::ThrusterControlNode>());
    rclcpp::shutdown();
    return 0;
}