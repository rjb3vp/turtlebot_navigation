/** @file walker.cpp
* @brief the ROS node that controls the Turtlebot
*
Apache HTTP Server
Copyright 2019 The Apache Software Foundation.

This product includes software developed at
The Apache Software Foundation (http://www.apache.org/).

Portions of this software were developed at the National Center
for Supercomputing Applications (NCSA) at the University of
Illinois at Urbana-Champaign.

This software contains code derived from the RSA Data Security
Inc. MD5 Message-Digest Algorithm, including various
modifications by Spyglass Inc., Carnegie Mellon University, and
Bell Communications Research, Inc (Bellcore).

*/


#include <sstream>

#include "ros/ros.h"
#include "std_msgs/String.h"

#include "geometry_msgs/Twist.h"
#include "kobuki_msgs/BumperEvent.h"
#include "PathPlanner.hpp"



PathPlanner pathPlanner;




/**
* @brief Callback for each collision/un-collision event.
* @param msg reference to a pointer to the incoming message of the event
* @return none
*/
void reactToBump(const kobuki_msgs::BumperEvent::ConstPtr& msg) {
  if (msg->bumper == msg->CENTER) {
    if (msg->state == msg->RELEASED) {
      pathPlanner.registerFreeCenter();
    } else {
      pathPlanner.registerBlockedCenter();
    }
  } else if (msg->bumper == msg->RIGHT) {
    if (msg->state == msg->RELEASED) {
      pathPlanner.registerFreeRight();
    } else {
      pathPlanner.registerBlockedRight();
    }
  } else {
    if (msg->state == msg->RELEASED) {
      pathPlanner.registerFreeLeft();
    } else {
      pathPlanner.registerBlockedLeft();
    }
  }
}


/**
* @brief Main function for the node
* @param argc standard main input
* @param argv standard main input
* @return error as int
*/


int main(int argc, char **argv) {
  ros::init(argc, argv, "walker");

  ros::NodeHandle n;

  ros::Subscriber sub =
n.subscribe("/mobile_base/events/bumper", 1000, reactToBump);

  ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>
("/cmd_vel_mux/input/teleop", 1000);

  ros::Rate loop_rate(10);

  ROS_INFO_STREAM("Hello World!  Started up.");

  while (ros::ok()) {
    geometry_msgs::Twist msg;

    msg.linear.x = pathPlanner.getXVelocity();
    msg.linear.y = pathPlanner.getYVelocity();
    msg.linear.z = pathPlanner.getZVelocity();

    msg.angular.x = pathPlanner.getXTurn();
    msg.angular.y = pathPlanner.getYTurn();
    msg.angular.z = pathPlanner.getZTurn();
    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}
