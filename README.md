###Turtlebot Navigation


## Overview

Controlling software (one 'walker' node) to control the Turtlebot as a Roomba in Gazebo.

## Standard install via command-line
```


Change directory to an existing or new catkin_ws
Then do:

git clone --recursive https://github.com/rjb3vp/turtlebot_navigation.git
catkin_make
rospack profile
source devel/setup.bash


## Running Simulation From launchfile (optional rosbag)


To use the launchfile, first execute the standard install.  Then, in catkin_ws, run:

roslaunch walker mylaunch.launch
(to run with rosbag)

or

roslaunch walker mylaunch.launch use_rosbag:=false
(if you want to run without rosbag)


## Worlds Directory

Stores world files for use with Gazebo.



## Bag File Inspection
After logging to a bag file, execute:

rosbag info <bag file name>

You will see a printout showing all topics subscribed with rosbag (all except camera topics, if through launchfile)


## Bag File Playback

After logging to a bag file, execute:

roscore
rosrun <Any desired nodes.  Recommended not to use Gazebo with rosbag playback>
rosbag play <bag file name>

You should see similar operation to a full run, with the bag file recording porentially replacing another node.



## Assumptions/Dependencies
```
This project assumes an install of ROS Kinetic on Ubuntu 16.04 LTS with C++11, and Turtlebot 3.


