/** @file PathPlanner.cpp
* @brief the class that controls the Turtlebot through the walker.
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

#include "PathPlanner.hpp"
#include <sstream>
#include "ros/ros.h"



bool isBlockedCenter = false;
bool isBlockedLeft = false;
bool isBlockedRight = false;
float speed = 0.1;//4.0;
float turnSpeed = 0.5;//4.0;
int bumperLimit = 40;//23;
int bumperBuffer = 0;

/*
* @brief Basic constructor
* @return Instance of the object
*/
PathPlanner::PathPlanner() {
isBlockedCenter = false;
isBlockedLeft = false;
isBlockedRight = false;
ROS_INFO_STREAM("Path planner created.");

}

/*
* @brief Called to register center bumper being blocked
* @return none
*/
void PathPlanner::registerBlockedCenter() {
isBlockedCenter = true;
//ros::Duration(5.0).sleep();
bumperBuffer = bumperLimit;
ROS_INFO_STREAM("" << isBlockedLeft << " " << isBlockedCenter << " " << isBlockedRight);
}

/*
* @brief Called to register center bumper being freed
* @return none
*/
void PathPlanner::registerFreeCenter() {
isBlockedCenter = false;
ROS_INFO_STREAM("" << isBlockedLeft << " " << isBlockedCenter << " " << isBlockedRight);
}

/*
* @brief Called to register right bumper being blocked
* @return none
*/
void PathPlanner::registerBlockedRight() {
//isBlockedRight = true;
//bumperBuffer = bumperLimit;
//ROS_INFO_STREAM("" << isBlockedLeft << " " << isBlockedCenter << " " << isBlockedRight);
}

/*
* @brief Called to register right bumper being freed
* @return none
*/
void PathPlanner::registerFreeRight() {
//isBlockedRight = false;
//ROS_INFO_STREAM("" << isBlockedLeft << " " << isBlockedCenter << " " << isBlockedRight);
}


/*
* @brief Called to register left bumper being blocked
* @return none
*/
void PathPlanner::registerBlockedLeft() {
//isBlockedLeft = true;
//bumperBuffer = bumperLimit;
//ROS_INFO_STREAM("" << isBlockedLeft << " " << isBlockedCenter << " " << isBlockedRight);
}

/*
* @brief Called to register left bumper being freed
* @return none
*/
void PathPlanner::registerFreeLeft() {
//isBlockedLeft = false;
//ROS_INFO_STREAM("" << isBlockedLeft << " " << isBlockedCenter << " " << isBlockedRight);
}



/*
* @brief Called to check what the X velocity component should be
* @return float desired velocity to send to the Turtlebot
*/
float PathPlanner::getXVelocity() {
ROS_INFO_STREAM("Buffer is " << bumperBuffer);
ROS_INFO_STREAM("" << isBlockedLeft << " " << isBlockedCenter << " " << isBlockedRight);
if (!isBlockedCenter && !isBlockedRight && !isBlockedLeft) {
bumperBuffer--;
} else {

return -1.0 * speed;
}

if (bumperBuffer > 0) {//(isBlockedCenter || isBlockedRight || isBlockedLeft) {


return -1.0 * speed;
} else {
return speed;
}


}


/*
* @brief Called to check what the Y velocity component should be
* @return float desired velocity to send to the Turtlebot
*/
float PathPlanner::getYVelocity() {
return 0.0;
}

/*
* @brief Called to check what the Z velocity component should be
* @return float desired velocity to send to the Turtlebot
*/
float PathPlanner::getZVelocity() {
return 0.0;
}

/*
* @brief Called to check what the X turn speed should be
* @return float desired velocity to send to the Turtlebot
*/
float PathPlanner::getXTurn() {
return 0.0;
}
/*
* @brief Called to check what the Y turn speed should be
* @return float desired velocity to send to the Turtlebot
*/
float PathPlanner::getYTurn() {
return 0.0;
}
/*
* @brief Called to check what the Z turn speed should be
* @return float desired velocity to send to the Turtlebot
*/
float PathPlanner::getZTurn() {
if (bumperBuffer > 0) {//if (isBlockedCenter || isBlockedRight || isBlockedLeft) {
//bumperBuffer--;
return turnSpeed;
} else {
return 0.0;
}
}


