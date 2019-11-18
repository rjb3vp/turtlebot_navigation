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

///mobile_base/events/bumper

//#include <math.h>
//#include <tf/transform_broadcaster.h>
#include <sstream>
//#include <cstdlib>
#include "ros/ros.h"
#include "std_msgs/String.h"

#include "geometry_msgs/Twist.h"
#include "kobuki_msgs/BumperEvent.h"
#include "PathPlanner.hpp"
//#include "std_srvs/Empty.h"
//#include "beginner_tutorials/SetRandomRange.h"


int randomRange = 100;
int randomMean = 50;


PathPlanner pathPlanner;

void reactToBump(const kobuki_msgs::BumperEvent::ConstPtr& msg) {


if(msg->bumper == msg->CENTER) {
if(msg->state == msg->RELEASED) {
pathPlanner.registerFreeCenter();
} else {
pathPlanner.registerBlockedCenter();
}
}

else if(msg->bumper == msg->RIGHT) {
if(msg->state == msg->RELEASED) {
pathPlanner.registerFreeRight();
} else {
pathPlanner.registerBlockedRight();
}
}
 else {

if(msg->state == msg->RELEASED) {
pathPlanner.registerFreeLeft();
} else {
pathPlanner.registerBlockedLeft();
}
}



}


/**

* @brief Sets the range and mean for random number generation.

* @param req incoming request object with params to copy

* @param res outgoing result to show if errors occurred in this method

* @return bool to show whether this function executed or not

*/

/*
bool setParams(beginner_tutorials::SetRandomRange::Request  &req,
         beginner_tutorials::SetRandomRange::Response &res) {
  if (req.mean == 0) {
    ROS_WARN(
"Mean value of 0 is technically permitted, but probably a mistake.");
    ROS_INFO_STREAM("Mean updated to " << req.mean << " with range of "
<< req.range);

    res.error = false;
    randomRange = req.range;
    randomMean = req.mean;
  } else if (req.mean < 0) {
    ROS_ERROR_STREAM("Mean cannot be " << req.mean << " which is < 0");
    res.error = true;
  } else {
    ROS_INFO_STREAM("Mean updated to " << req.mean
<< " with range of " << req.range);
    res.error = false;
    randomRange = req.range;
    randomMean = req.mean;
  }

  return true;
}
*/



/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv) {
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "walker");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;

  /**
   * The advertise() function is how you tell ROS that you want to
   * publish on a given topic name. This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing. After this advertise() call is made, the master
   * node will notify anyone who is trying to subscribe to this topic name,
   * and they will in turn negotiate a peer-to-peer connection with this
   * node.  advertise() returns a Publisher object which allows you to
   * publish messages on that topic through a call to publish().  Once
   * all copies of the returned Publisher object are destroyed, the topic
   * will be automatically unadvertised.
   *
   * The second parameter to advertise() is the size of the message queue
   * used for publishing messages.  If messages are published more quickly
   * than we can send them, the number here specifies how many messages to
   * buffer up before throwing some away.
   */


  //ros::ServiceServer service = n.advertiseService("random_data", setParams);
  //ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

//ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

  ros::Subscriber sub = n.subscribe("/mobile_base/events/bumper", 1000, reactToBump);

  ros::Publisher chatter_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 1000);

  ros::Rate loop_rate(10);

  ROS_INFO_STREAM("Hello3!");
  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
  int count = 0;
  while (ros::ok()) {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */


//#include "std_msgs/String.h"

geometry_msgs::Twist msg;

msg.linear.x = pathPlanner.getXVelocity();//0.4;
msg.linear.y = pathPlanner.getYVelocity();//0.0;
msg.linear.z = pathPlanner.getZVelocity();//0.0;

msg.angular.x = pathPlanner.getXTurn();//0.0;
msg.angular.y = pathPlanner.getYTurn();//0.0;
msg.angular.z = pathPlanner.getZTurn();//0.0;
chatter_pub.publish(msg);


/*

    std_msgs::String msg;

    std::stringstream ss;


    if (randomRange < -1) {
      ROS_FATAL_STREAM("Impossible range of " << randomRange
<< " detected, failure imminent.");
    }

    int baseNumber = floor(randomRange / 2);

    ROS_DEBUG_STREAM("Calculated base number is " << baseNumber);

    int output = (rand() % randomRange) + (randomMean + floor(randomRange / 2));
    ss << "Our random value is=" << output;
    msg.data = ss.str();


    ROS_DEBUG("HELP");
    ROS_INFO_STREAM("Data: " << msg.data.c_str());
*/

    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */
    //chatter_pub.publish(msg);

    // Adapted from
    // wiki.ros.org/tf/Tutorials/Writing%20a%20tf%20broadcaster%20%28C%2B%2B%29
    //tf::TransformBroadcaster br;
    //tf::Transform transform;
    // Handle translation here first
    //transform.setOrigin(tf::Vector3(0.0 + output, 20.0, 0.0));

    // Handle rotation here
    //tf::Quaternion q;
    //q.setRPY(0, 0, 45);

    // trivial change to see dynamics
    //transform.setRotation(q);

    //br.sendTransform(tf::StampedTransform(transform, ros::Time::now(),
//"world", "talk"));






    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
