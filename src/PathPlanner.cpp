#include "PathPlanner.hpp"
#include <sstream>
#include "ros/ros.h"
#include <stdio.h>


bool isBlocked = false;

PathPlanner::PathPlanner() {
isBlocked = false;
ROS_INFO_STREAM("Path planner created.");
printf("Created\n");
}

void PathPlanner::registerBlocked() {

}

void PathPlanner::registerFree() {

}


float PathPlanner::getXVelocity() {
return 0.0;
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
return 0.0;
}


