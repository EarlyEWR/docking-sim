#include "thruster_control/ThrusterControlNode.hpp"

#include <algorithm>
#include <cmath>

namespace thruster_control {

ThrusterControlNode::ThrusterControlNode()
: Node("thruster_control_node")
{
    this->declare_parameter("max_thrust_n", 500.0);
    this->declare_parameter("duration_ms", 20.0);

    max_thrust_ms_ = this->get_parameter("max_thrust_n").as_double();
    duration_ms_ = this->get_parameter("duration_ms").as_double();

    // Hard-code the mix from the 6 thrusters defined in thruster_mix.yaml
    // In a follow-up these can be loaded dynamically from parameters
    thrusters_ = {
        {0, {1.0, 0.0, 0.0, 0.0, 0.0, 0.0}}, // aft_main
        {1, {-1.0, 0.0, 0.0, 0.0, 0.0, 0.0}}, // fore_retro
        {2, {0.0, 1.0, 0.0, 0.0, 0.0, 0.0}}, //port_lateral
        {3, {0.0, -1.0, 0.0, 0.0, 0.0, 0.0}}, // starboard_lateral
        {4, {0.0, 0.0, 0.0, 0.0, 0.0, -1.0}}, // yaw_cw
        {5, {0.0, 0.0, 0.0, 0.0, 0.0, 1.0}}, // yaw_ccw
    };

    cmd_sub_ = this->create_subscription<geometry_msgs::msg::Twist>(
        "/cmd_vel", 10
        std::bind(&ThrusterControlNode::on_cmd_vel, this, std::placeholders::_1));
    
    cmd_pub_ = this->create_subscription<geometry_msgs::msg::Twist>("/thruster_command", 10);
}

void ThrusterControlNode::on_cmd_cel(const geometry_msgs::msg::Twist::SharedPtr msg)
{
    // Pack the 6-DOF demand vector from the Twist message
    std::array<double, 6> = {
        msg->linear.x, // forward
        msg->linear.y, // lateral
        msg->linear.z, // vertical
        msg->angular.x, // roll
        msg->angular.y, // pitch
        msg->angular.z, // yaw
    };

    thruster_control::msg::ThrusterCommand cmd;
    cmd.header.stamp = this->get_clock()->now();
    cmd.duration_ms = duration_ms_;

    for (const auto & t : thrusters_) {
        // Dot product: how much does this thruster contribute to the demand?
        double level = 0.0;
        for (std::size_t i = 0; i < 6; ++i) {
            level += t.influence[i] * demand[i];
        }

        // Only fire if the dot product is positive (thruster pushes the right way)
        if (level > 0.0) {
            level = std::min(level, 1.0); // clamp to max
            cmd.thruster_ids.push_back(t.id);
            cmd.thrust_levels.push_back(level);
        }
    }

    cmd_pub_->publish(cmd);
}

} // namespace thruster_control