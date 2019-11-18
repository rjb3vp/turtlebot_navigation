#include "PathPlanner.hpp"
#include <sstream>
#include "ros/ros.h"
#include <stdio.h>


bool isBlocked = false;
float speed = 4.0;
float turnSpeed = 4.0;

PathPlanner::PathPlanner() {
isBlocked = false;
ROS_INFO_STREAM("Path planner created.");
printf("Created\n");
}

void PathPlanner::registerBlocked() {
isBlocked = true;
}

void PathPlanner::registerFree() {
isBlocked = false;
}


float PathPlanner::getXVelocity() {
if (isBlocked) {
return 0.0;
} else {
return speed;
}
}

float PathPlanner::getYVelocity() {
return 0.0;
}

float PathPlanner::getZVelocity() {
return 0.0;
}

float PathPlanner::getXTurn() {
return 0.0;
}

float PathPlanner::getYTurn() {
return 0.0;
}

float PathPlanner::getZTurn() {
if (isBlocked) {
return turnSpeed;
} else {
return 0.0;
}
}


