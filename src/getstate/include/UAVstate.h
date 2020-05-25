#pragma once

#include <ros/ros.h>
#include <Eigen/Eigen>

class UAVstate
{
public:
    ros::Duration det_time;
    ros::Time start_time;
    ros::Time Now_time;
    Eigen::Vector3d position = {0,0,0};
    Eigen::Vector3d velocity = {0,0,0};
    Eigen::Vector3d attitude = {0,0,0};
    Eigen::Quaterniond attitude_q = {0,0,0,0};
    float attitude_rate[3] = {0,0,0} ;
    UAVstate(){
        ros::Time timezzz(0);
        start_time = timezzz;
    }
    ~UAVstate(){}
};