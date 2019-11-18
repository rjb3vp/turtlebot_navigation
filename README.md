## Overview

Controlling software (one 'walker' node) to control the turtlebot as a Roomba in Gazebo.

## Standard install via command-line
```


Change directory to an existing or new catkin_ws
Then do:

git clone --recursive https://github.com/rjb3vp/turtlebot_navigation.git
catkin_make
rospack profile
source devel/setup.bash


## Run From launchfile (optional rosbag)


To use the launchfile, first execute the standard install.  Then, in catkin_ws, run:

roslaunch walker mylaunch.launch





roslaunch turtlebot_gazebo my_turtlebot_world.launch





## Worlds Directory

Stores world files for use with Gazebo.







roslaunch beginner_tutorials example.launch <optional starting mean argument startMean, as an int>
<optional use_rosbag flag, a boolean>

Example for a starting mean of 3 with no rosbag usage:
roslaunch beginner_tutorials example.launch startMean:=3 use_rosbag:=0

```

## Bag File Inspection
After logging to a bag file, execute:

rosbag info <bag file name>

You will see a printout showing all topics subscribed with rosbag (all, if through launchfile)


## Bag File Playback

After logging to a bag file, execute:

roscore
rosrun beginner_tutorials listener
rosbag play <bag file name>

You should see similar operation to a full run, with the bag file recording replacing the talker node.


## Testing (rostest)
After installing, execute:

roscore
catkin_make run_tests

This should automatically make and run the gtest suite.

## TF Inspection
After installation, execute:

Run program: 

roscore
rosrun beginner_tutorials talker

rosrun tf view_frames

Then view the resultant pdf with your preferred reader.

## Services
The random number service allows a client to set the range and mean that talker uses to generate random numbers.
While talker is already running, one can run:

rosservice call /talker/random_data <Mean> <Range>

where mean and range are 64 bit integers.
It will return an error if errors exist.


## Assumptions/Dependencies
```
This project assumes an install of ROS Kinetic on Ubuntu 16.04 LTS with C++11


