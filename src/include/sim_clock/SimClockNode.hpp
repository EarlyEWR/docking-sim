#ifndef SIM_CLOCK__SIM_CLOCK_NODE_HPP_
#define SIM_CLOCK__SIM_CLOCK_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "rosgraph_msgs/msg/clock.hpp"

namespace sim_clock {

class SimClockNode : public rclcpp::Node {
public:
    SimClockNode();

private:
    void tick();

    rclcpp::Publisher<rosgraph_msgs::msg::Clock>::SharedPtr clock_pub_;
    rclcpp::TimerBase::SharedPtr time_;

    double sim_frequency_hz_{100.0};
    double realtime_factor_{1.0};
    double sim_time_sec_{0.0};
};

} // namespace sim_clock

#endif