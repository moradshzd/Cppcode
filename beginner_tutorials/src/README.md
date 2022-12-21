# beginner_tutorials
According to your words, I prepared some nodes
* cpp_node
* talker
* listener
* server
* cliient
## cpp_node


### introduction
it is a simple node and after running it shows on terminal that it has started working and after 1 second it shows on terminal that it is finished.


### code
```
#include <ros/ros.h>

int main (int argc , char **argv){ 
    ros::init(argc , argv, "cpp_node");
    ros::NodeHandle nh; 
    ROS_INFO("Node has started");
    ros::Duration(1.0).sleep();
    ROS_INFO("exited");
}
```

## talker
### introduction
it is a node that sends a message to another node by using a topic
### code
```
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
```
We wrote a node that publishes the message with a frequency of 10 Hz in the chatter topic and displays it in the terminal.

## listener

### introduction
We created a node that connects to the chatter topic and executes the callback function once for each message it receives from the chatter topic.
### introduction
```
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
```
## server
### introduction
In this type, we want to check another type of data communication, which is called service. The difference between a topic and a service is that topics are one-way, but services are two-way, and when we send a request to a node, we have to wait for its response. 
### introduction



```
#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h"


bool handle_service (biginner_tutorials::AddTwoInts::Request &req,biginner_tutorials::AddTwoInts::Response &res){
    int result=req.a+req.b;
    res.sum=result;
    ROS_INFO("result is %s", (int) result);
    return true;
}


int main (int argc,char **argv){
    ros::init(argc , argv, "server");   
    ros::NodeHandle nh;                     

    ros::ServiceServer server=nh.advertiseService("/add_two_ints",handle_service);
    ros::spin();


}

```

## client
### introduction
Our goal is to create a client that sends a request to the server and receives a response

```
#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h"


int main (int argc,char **argv){ 
    ros::init(argc , argv, "client");
    ros::NodeHandle nh;
    ros::ServiceClient client=nh.serviceClient<beginner_tutorials::AddTwoInts>("/add_two_ints");
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
```

