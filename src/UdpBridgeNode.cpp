#include "telemetry_bridge/UdpBridgeNode.hpp"

#include <functional>

 namespace telemetry_bridge {

UdpBridgeNode::UdpBridgeNode()
: Node("udp_bridge_node")
{
    this->declare_parameter("udp_port", 8091);
    this->declare_parameter("target_ip", "127.0.0.1");
    this->declare_parameter("qos_depth", 10);

    udp_port_ = this->get_parameter("udp_port").as_int();
    target_ip_ = this->get_parameter("target_ip").as_string();
    qos_depth_ = this->get_parameter("qos_depth").as_int();

    outgoing_sub_ = this->create_subscription<telemetry_bridge::msg::TelemetryState>(
        "telemetry/outgoing",
        qos_depth_,
        std::bind(&UdpBridgeNode::handle_outgoing_state, this, std::placeholders::_1));
    
        incoming_pub_ = this->create_publisher<telemetry_bridge::msg::TelemetryState>(
            "telemetry/incoming",
            qos_depth_);
}

UdpBridgeNode::~UdpBridgeNode()
{
    running_ = false;
    if (receiver_thread_.joinable()) {
        receiver_thread_.join();
    }
}

void UdpBridgeNode::handle_outgoing_state(const telemetry_bridge::msg::TelemetryState::SharedPtr msg)
{
    (void)msg;
}

void UdpBridgeNode::receive_loop(){}

std::vector<uint8_t> UdpBridgeNode::serialize_state(const telemetry_bridge::msg::TelemetryState & msg) const
{
    (void)msg;
    return {};
}

bool UdpBridgeNode::deserialize_state(
    const uint8_t * data,
    std::size_t size,
    telemetry_bridge::msg::TelemetryState & out_msg) const
{
    (void)data;
    (void)size;
    (void)out_msg;
    return false;
}

} // namespace telemetry_bridge