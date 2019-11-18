/** @file PathPlanner.hpp
* @brief the ROS class definition that controls the Turtlebot
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

#ifndef PATH_PLANNER
#define PATH_PLANNER

class PathPlanner
{
public:
PathPlanner();
void registerBlockedCenter();

void registerFreeCenter();


void registerBlockedRight();

void registerFreeRight();

void registerBlockedLeft();

void registerFreeLeft();
float getXVelocity();
float getYVelocity();
float getZVelocity();

  float getXTurn();
  float getYTurn();
  float getZTurn();
};
#endif
