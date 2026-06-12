#include <memory>
#include <vector>

#include <gtest/gtest.h>

#include "rclcpp/rclcpp.hpp"
#include "telemetry_bridge/StateMonitorNode.hpp"

TEST(StateMonitorTest, DetectsGapsAndStalePackets)
{
    auto context = std::make_shared<rclcpp::Context>();
    std::vector<const char *> argv_storage = {"monitor_test"};
    context->init(static_cast<int>(argv_storage.size()), argv_storage.data());

    auto options = rclcpp::NodeOptions().context(context);
    auto node = std::make_shared<telemetry_bridge::StateMonitorNode>(options);

    telemetry_bridge::msg::TelemetryState m1;
    m1.header.stamp = node->now();
    m1.sequence_id = 1;
    m1.x = 1.0;

    telemetry_bridge::msg::TelemetryState m3;
    m3.header.stamp = node->now();
    m3.sequence_id = 3;
    m3.x = 3.0;

    telemetry_bridge::msg::TelemetryState m2;
    m2.header.stamp = node->now();
    m2.sequence_id = 2;
    m2.x = 2.0;

    node->process_state(m1);
    node->process_state(m3);
    node->process_state(m2);

    ASSERT_TRUE(node->has_state());
    ASSERT_EQ(node->last_sequence_id(), 3u);
    ASSERT_EQ(node->sequence_gap_count(), 1u);
    ASSERT_EQ(node->stale_packet_count(), 1u);
    ASSERT_DOUBLE_EQ(node->last_state().x, 3.0);

    context->shutdown("monitor test complete");
}