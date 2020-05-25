//
// Created by xlx on 2020/5/11.
//
#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Quaternion.h> 
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "math_units.h"
#include <Eigen/Eigen>
#include <time.h>
#include "kbhitubuntu.h"



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

class SubState
{
public:
    UAVstate quad_state;

    SubState()
    {
        OdometrySub = state_nh.subscribe("vins_estimator/odometry",1000,&SubState::SubOdometryCallback,this);
    }
    ~SubState(){}
private:
    ros::NodeHandle state_nh;

    ros::Subscriber OdometrySub;

    void SubOdometryCallback(const nav_msgs::OdometryConstPtr& msg)
    {
        if(quad_state.start_time.toSec() ==0)
        {
            quad_state.start_time = msg->header.stamp;
            quad_state.Now_time = msg->header.stamp;
        }
        else
        {
            quad_state.Now_time = msg->header.stamp;
            quad_state.det_time = msg->header.stamp - quad_state.start_time;
        }
        std::cout << quad_state.det_time <<std::endl;

        quad_state.position[0] = msg->pose.pose.position.x;
        quad_state.position[1] = msg->pose.pose.position.y;
        quad_state.position[2] = msg->pose.pose.position.z;

        quad_state.velocity[0] = msg->twist.twist.linear.x;
        quad_state.velocity[1] = msg->twist.twist.linear.y;
        quad_state.velocity[2] = msg->twist.twist.linear.z;

        quad_state.attitude_rate[0] = msg->twist.twist.angular.x;
        quad_state.attitude_rate[1] = msg->twist.twist.angular.y;
        quad_state.attitude_rate[2] = msg->twist.twist.angular.z;

	Eigen::AngleAxisd rotation_vector1(-C_PI/2, Eigen::Vector3d(1,0,0));	
	//Eigen::Matrix3d rotation_matrix1 = rotation_vector1.toRotationMatrix();
	Eigen::Quaterniond quaternion1(rotation_vector1);

	geometry_msgs::Quaternion q_msg = msg->pose.pose.orientation;

        quad_state.attitude_q.w() =q_msg.w;
        quad_state.attitude_q.x() =q_msg.x;        
	    quad_state.attitude_q.y() =q_msg.y;
        quad_state.attitude_q.z() =q_msg.z;

	    quad_state.attitude_q = quad_state.attitude_q*quaternion1;

        quad_state.attitude = quaternion_to_euler_angle(quad_state.attitude_q);
    //    std::cout << "quad_state:attitude = " <<quad_state.attitude <<std::endl;
        std::cout << "quad_state:position = " <<quad_state.position <<std::endl;
    //	std::cout<< "quad_state:position:x: "<<quad_state.position[0]<<" y:  "<<quad_state.position[1]<<" z:  "<<quad_state.position[2]<<std::endl;
	//std::cout<< "quad_state:velocity:x: "<<quad_state.velocity[0]<<" y:  "<<quad_state.velocity[1]<<" z:  "<<quad_state.velocity[2]<<std::endl;
        //std::cout <<"quad_state : attitude_q[w x y z]:["<<quad_state.attitude_q.w<<quad_state.attitude_q.x<<quad_state.attitude_q.y<<quad_state.attitude_q.z<<std::endl;
    }   
};



int main(int argc, char** argv)
{
    int i;
    std::string filename = "/home/xlx/odometry.txt";
    ros::init(argc,argv,"statesubscriber");
    SubState SubStateObject;
    std::ofstream outFile(filename);

    while(ros::ok&&(!kbhit()))
    {
        ros::spinOnce();
        outFile << SubStateObject.quad_state.det_time;
        for(i=0;i<3;i++)
        {
         outFile << SubStateObject.quad_state.position[i];
        }
        outFile<<'\n';
        
    }
    outFile.close();

    return 0;
}
