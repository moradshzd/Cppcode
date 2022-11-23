#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h"





int main (int argc,char **argv){
    ros::init(argc , argv, "cpp_client");
    ros::NodeHandle nh;
    ros::ServiceClient client=nh.ServiceClient<beginner_tutorials::AddTwoInts>("/add_two_ints");
    beginner_tutorials::AddTwoInts srv;
    srv.request.a=3;
    srv.request.b=5;

    if (client.call(srv))  {
        ROS_INFO("server answered : %d",(int) srv.response.sum) ;
        }
            else {
            ROS_WARN("failed");
}
           }

