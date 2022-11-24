#include "std_msgs/String.h"
#include "ros/ros.h"

void callback (const std_msgs::String &msg){      /*The goal is to get the content of the msg and display it*/
    ROS_INFO("i recived [%s]", msg.data.c_str());
    /* We created a node that connects to the chatter topic and executes the callback function once for each
     * message it receives from the chatter topic.*/
}

int main (int argc,char **argv){
    ros::init(argc , argv, "listener");/* initialize the input arguments and specify the node name */
    ros::NodeHandle nh; /* We use the NodeHandle as a reference for the node */

    ros::Subscriber sub=nh.subscribe("chatter",1000, callback );
    /*  call the subscriber and put an object named pub in it we call the topic through the NodeHandle and
     *  subscribe command and then use callback function for using the msg or data of topic */


    ros::spin();
    /*  Wherever we use (callback function), we use spin so that node can be executed repeatedly.*/

}
