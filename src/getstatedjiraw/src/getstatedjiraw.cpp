//
// Created by xlx on 2020/5/11.
//
#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Quaternion.h> 
#include <iostream>
#include "dji_sdk/dji_sdk.h"
#include <std_msgs/UInt8.h>
#include <dji_sdk/DroneTaskControl.h>
#include <dji_sdk/SDKControlAuthority.h>
#include <dji_sdk/QueryDroneVersion.h>
#include <dji_sdk/SetLocalPosRef.h>
#include <tf/tf.h>
#include <math.h>
#include "math_units.h"
#include <Eigen/Eigen>
#include <sensor_msgs/Imu.h>


class UAVstatefromDJI
{
public:
    //Eigen::Vector3d gps_position;
    Eigen::Vector3d velocity;
    Eigen::Vector3d acceleration;
    Eigen::Vector3d attitude;
    Eigen::Quaterniond attitude_q;
    Eigen::Vector3d angular_velocity ;
    UAVstatefromDJI(){}
    ~UAVstatefromDJI(){}
};

class SubStatefromDJI
{
public:
    UAVstatefromDJI quad_state;

    SubStatefromDJI(ros::NodeHandle nh)
    //state_nh("~")
    {
	state_nh = nh;
        velocitySub = state_nh.subscribe("/dji_sdk/velocity",10,&SubStatefromDJI::velocity_callback,this);
        attitudeSub = state_nh.subscribe("/dji_sdk/attitude",10,&SubStatefromDJI::attitude_callback,this);
        ImuSub = state_nh.subscribe("/dji_sdk/imu",10,&SubStatefromDJI::Imu_callback,this);
       // GPS_PositionSub = state_nh.subscribe("/dji_sdk/gps_position",10,&SubStatefromDJI::gps_position_callback,this);
    }
    ~SubStatefromDJI(){}
private:
    ros::NodeHandle state_nh;

    ros::Subscriber attitudeSub;
    ros::Subscriber velocitySub;
    ros::Subscriber ImuSub;
    //ros::Subscriber GPS_PositionSub;


    void toEulerAngle(Eigen::Quaterniond quat)
    {
        quad_state.attitude = quaternion_to_euler_angle(quat);
        std::cout <<"attitude:"<<quad_state.attitude<<std::endl;
    }
    void attitude_callback(const geometry_msgs::QuaternionStamped::ConstPtr& msg)
    {
        geometry_msgs::Quaternion q_msg = msg->quaternion;
        quad_state.attitude_q.w() =q_msg.w;
        quad_state.attitude_q.x() =q_msg.x;        
	    quad_state.attitude_q.y() =q_msg.y;
        quad_state.attitude_q.z() =q_msg.z;
        this->toEulerAngle(quad_state.attitude_q);
    }
    void velocity_callback(const geometry_msgs::Vector3Stamped::ConstPtr& msg)    
    {
        quad_state.velocity[0] = msg->vector.x;
        quad_state.velocity[1] = msg->vector.y;
        quad_state.velocity[2] = msg->vector.z;

	//std::cout <<quad_state.velocity <<std::endl;
    }
    void Imu_callback(const sensor_msgs::Imu::ConstPtr& msg)    
    {

        quad_state.angular_velocity[0] = msg->angular_velocity.x;
        quad_state.angular_velocity[1] = msg->angular_velocity.y;
        quad_state.angular_velocity[2] = msg->angular_velocity.z;

        quad_state.acceleration[0] = msg->linear_acceleration.x;
        quad_state.acceleration[1] = msg->linear_acceleration.y;
        quad_state.acceleration[2] = msg->linear_acceleration.z -GRAVITY;

	//std::cout <<"acceleration"<<quad_state.acceleration <<std::endl;

    }
   // void gps_position_callback();

   
};


/*************主函数入口**********/
int main(int argc, char** argv)
{
    ros::init(argc,argv,"statesubscriber");
    ros::NodeHandle nh;
    SubStatefromDJI SubStateObject(nh);
    ros::spin();
    return 0;
}
