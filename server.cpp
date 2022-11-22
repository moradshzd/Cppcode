#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h"


bool handle_service (biginner_tutorials::AddTwoInts::Request &req,biginner_tutorials::AddTwoInts::Response &res){
    int result=req.a+req.b;
    res.sum=result;
    ROS_INFO("result is %s", (int) result);
    return true;
}


int main (int argc,char **argv){
    ros::init(argc , argv, "cpp_server");
    ros::NodeHandle nh;

    ros::ServerService server=nh.advertiseService("/add_two_ints",handle_service);

    ros::spin();

}
