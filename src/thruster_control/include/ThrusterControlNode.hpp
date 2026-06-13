#ifndef THRUSTER_CONTROL__THRUSTER_CONTROL_NODE_HPP_
#define THRUSTER_CONTROL__THRUSTER_CONTROL_NODE_HPP_

#include <vector>
#include <array>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "thruster_control/msg/thruster_command.hpp"

namespace thruster_control {

struct ThrusterDef {
    int id;
    // 6-DOF influence: [fx, fy, fz, tx, ty, tz], each -1..1
    std::array<double, 6> influence;
};

class ThrusterControlNode : public rclcpp::Node {
public:
    ThrusterControlNode();

private:
    void on_cmd_vel(const geometry_msgs::msg::Twist::SharedPtr msg);

    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_sub_;
    rclcpp::Publisher<thruster_control::msg::ThrusterCommand>::SharedPtr cmd_pub_;

    std::vector<ThrusterDef> thrusters_;
    double max_thrust_n_{500.0};
    double duration_ms_{20.0};
};

} // namespace thruster_control

#endif