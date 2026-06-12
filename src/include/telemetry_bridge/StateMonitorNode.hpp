#ifndef TELEMETRY_BRIDGE__STATE_MONITOR_NODE_HPP_
#define TELEMETRY_BRIDGE__STATE_MONITOR_NODE_HPP_

#include <mutex>

#include "rclcpp/rclcpp.hpp"
#include "telemetry_bridge/LatencyMonitor.hpp"
#include "telemetry_bridge/msg/latency_stats.hpp"
#include "telemetry_bridge/msg/telemetry_state.hpp"

namespace telemetry_bridge {

class StateMonitorNode : public rclcpp::Node {
public:
  explicit StateMonitorNode(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());

  bool has_state() const;
  uint64_t last_sequence_id() const;
  uint64_t sequence_gap_count() const;
  uint64_t stale_packet_count() const;
  telemetry_bridge::msg::TelemetryState last_state() const;

  void process_state(const telemetry_bridge::msg::TelemetryState & msg);

private:
  void handle_state(const telemetry_bridge::msg::TelemetryState::SharedPtr msg);
  void publish_latency_stats();

  rclcpp::Subscription<telemetry_bridge::msg::TelemetryState>::SharedPtr state_sub_;
  rclcpp::Publisher<telemetry_bridge::msg::LatencyStats>::SharedPtr stats_pub_;
  rclcpp::TimerBase::SharedPtr stats_timer_;

  mutable std::mutex mutex_;
  LatencyMonitor latency_monitor_;
  telemetry_bridge::msg::TelemetryState last_state_;
  bool has_state_{false};
  uint64_t last_sequence_id_{0};
  uint64_t sequence_gap_count_{0};
  uint64_t stale_packet_count_{0};
};

}  // namespace telemetry_bridge

#endif