#include "std_msgs/String.h"
#include "ros/ros.h"

void callback (const std_msgs::String &msg){
    ROS_INFO("i recived [%s]", msg.data.c_str());
}

int main (int argc,char **argv){
    ros::init(argc , argv, "listener");
    ros::NodeHandle nh;
    ros::Subscriber sub=nh.subscribe("chatter",1000, callback );
    ros::spin();

}
