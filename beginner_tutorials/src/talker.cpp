#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main (int argc,char **argv){
    ros::init(argc , argv, "talker"); /* initialize the input arguments and specify the node name */

    ros::NodeHandle nh;               /* We use the NodeHandle as a reference for the node */

    ros::Publisher pub=nh.advertise<std_msgs::String>("chatter",1000);
    /* first, call the publisher and put an object named pub in it and create topic through the NodeHandle and
     *  advertise command, and we specify the type of our message, which is a string, and then we
     *  specify the topic name and the queue size.*/

    ros::Rate r(10);/* We use this command to make the frequency of 10 Hz perform this operation*/

    while(ros::ok()){/*Run the following commands until the ros is ok*/
        std_msgs::String msg;/* we create a String object called msg and this is the content of the topic*/
        msg.data="hello world ";/*This is data of the message */
        ROS_INFO("%s",msg.data.c_str());/*To display the message in ros, we convert the message to c_string*/
        pub.publish(msg);/*With this command, the message will be published in the topic*/
        r.sleep();
        /*  Because we did not use while in our code and the code is executed once, and if we want our command
         *  to be executed until we stop it, we use the spin command.*/
        ;
    }

}
