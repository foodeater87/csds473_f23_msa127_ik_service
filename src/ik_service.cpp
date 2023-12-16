#include "ros/ros.h"
#include "ik_service/PoseIK.h"
#include "ur_kinematics/ur_kin.h"

bool pose_ik(ik_service::PoseIK::Request &req,
        ik_service::PoseIK::Response &res)
{
  ROS_INFO("The pose_ik service was called.");
  double q_sols[8][6];
  double X_POS = req.part_pose.position.x;
  double Y_POS = req.part_pose.position.y;
  double Z_POS = req.part_pose.position.z;
  double T[4][4] = {{0.0, -1.0, 0.0, X_POS}, \
                        {0.0, 0.0, 1.0, Y_POS}, \
                        {-1.0, 0.0, 0.0 , Z_POS}, \
                        {0.0, 0.0, 0.0, 1.0}};
  int num_sol;
  num_sol = ur_kinematics::inverse(&T[0][0], &q_sols[0][0], 0.0);
  res.num_sols = num_sol;
  for (int i = 0; i < 8; i++){
    for (int j = 0;j < 6; j++){
      res.joint_solutions[i].joint_angles[j] = q_sols[i][j];
    }
  }
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "pose_ik_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("pose_ik", pose_ik);
  ROS_INFO("Ready");
  ros::spin();

  return 0;
}
