std_msgs/Header header
int32[] thruster_ids # indices of thrusters that fire this cycle
float64[] thrust_levels # normalized power 0.0...1.0 per thruster
float64 duration_ms # how long to fire them

