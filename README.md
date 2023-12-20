# Lab #6: Inverse Kinematics Service
## Step 1
Setup and enter the catkin workspace that you cloned the repository into (catkin_ws should be replaced with the name of your workspace).
> `source /opt/ros/noetic/setup.bash`
> `cd catkin_ws`
> `catkin_make`
> `source devel/setup.bash`

## Step 2
Run the program using the following command:
`roslaunch ik_service ik_service.launch`

## Step 3
To test if the program works, input the following command:
`rosrun ik_service ik_client_node`

The output of the above function should display "Call to ik_service returned [4] solutions"

## Useful Links
ARIAC 2019 Documentation Page:
[https://bitbucket.org/osrf/ariac/wiki/2019/Home]
