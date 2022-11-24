#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h"





int main (int argc,char **argv){
    ros::init(argc , argv, "cpp_client");/* initialize the input arguments and specify the node name */
    ros::NodeHandle nh;/* We use the NodeHandle as a reference for the node */
    ros::ServiceClient client=nh.ServiceClient<beginner_tutorials::AddTwoInts>("/add_two_ints");
    /*  Our goal is to create a client through the ServiceClient command, whose task is to send a request
     *  to the /add_two_ints server and receive the response.*/
    beginner_tutorials::AddTwoInts srv;
    /*We call the AddTwoInts service from the beginner_tutorials package and put it in the srv object*/
    srv.req.a=3;
    srv.req.b=5;

    if (client.call(srv))  {/**/
        ROS_INFO("server answered : %d",(int) srv.res.sum) ;
        }
            else {
            ROS_WARN("failed");
}
           }

