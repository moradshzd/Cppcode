#include <ros/ros.h>

int main (int argc , char **argv){
    ros::init(argc , argv, "cpp_node");
    ros::NodeHandle nh;
    ROS_INFO("Node has started");
    ros::Duration(1.0).sleep();
    ROS_INFO("exited");
}