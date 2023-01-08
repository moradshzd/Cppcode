
#include <ros/ros.h>

int main (int argc , char **argv){
    ros::init(argc , argv, "cpp_node");// initialize the input arguments and specify the node name
    ros::NodeHandle nh; //We use the NodeHandle as a reference for the node 
    ROS_INFO("Node has started");//this command print "Node has started"
    ros::Duration(1.0).sleep();// pause time with Duration and sleep command
    ROS_INFO("exited");
}




