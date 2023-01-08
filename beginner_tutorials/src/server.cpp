#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h"


bool handle_service (biginner_tutorials::AddTwoInts::Request &req,biginner_tutorials::AddTwoInts::Response &res)
{
    /*  The output of this callback function is true or false, and the inputs of this function are the
     *  variables of the AddTwoInts.srv file, which are set from the client.*/
    int result=req.a+req.b;// We put the value of a and b that were assigned from the client into req and their sum in result
    res.sum=result;// We put the value of result in res.sum
    ROS_INFO("result is %s", (int) result);// display result on terminal
    return true;
}


int main (int argc,char **argv)
{
    ros::init(argc , argv, "server");   //initialize the input arguments and specify the node name
    ros::NodeHandle nh;                     //We use the NodeHandle as a reference for the node

    ros::ServiceServer server=nh.advertiseService("/add_two_ints",handle_service);
    /*  Our goal is to create a server and through the advertiseService command we call a callback function
     *  in which we call the srv file so that we can perform the desired operation on the input arguments.*/

    ros::spin();
    /*  Because we did not use while in our code and the code is executed once, and if we want our command
     *  to be executed until we stop it, we use the spin command.*/

}
