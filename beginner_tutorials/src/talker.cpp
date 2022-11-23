#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main (int argc,char **argv){
    ros::init(argc , argv, "talker");
    ros::NodeHandle nh;
    ros::Publisher pub=nh.advertise<std_msgs::String>("chatter",1000);

    ros::Rate r(10);

    while(ros::ok()){
        std_msgs::String msg;
        msg.data="hello world ";
        ROS_INFO("%s",msg.data.c_str());
        pub.publish(msg);
        r.sleep();
        ;
    }

}
