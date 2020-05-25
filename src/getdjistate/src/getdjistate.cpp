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
        quad_state.attitude = quaternion_to_euler(quat);
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
/**************M100控制函数声明*************/
bool obtain_control();
bool takeoff_land(int task);//Take_off使用
bool M100monitoredTakeoff();
bool M100monitoredLand();
void flight_status_callback(const std_msgs::UInt8::ConstPtr& msg);

uint8_t flight_status = 255;

ros::ServiceClient set_local_pos_reference;
ros::ServiceClient sdk_ctrl_authority_service;
ros::ServiceClient drone_task_service;
ros::ServiceClient query_version_service;


/*************主函数入口**********/
int main(int argc, char** argv)
{
    ros::init(argc,argv,"statesubscriberfromDJI");
    ros::NodeHandle nh;
    SubStatefromDJI SubStateObject(nh);
    /******** SubScribe message from dji_sdk_node *****/
    ros::Subscriber flightStatusSub = nh.subscribe("dji_sdk/flight_status", 10, &flight_status_callback);
/******** Basic services **********/
    sdk_ctrl_authority_service = nh.serviceClient<dji_sdk::SDKControlAuthority> ("dji_sdk/sdk_control_authority");
    drone_task_service         = nh.serviceClient<dji_sdk::DroneTaskControl>("dji_sdk/drone_task_control");
    query_version_service      = nh.serviceClient<dji_sdk::QueryDroneVersion>("dji_sdk/query_drone_version");
    set_local_pos_reference    = nh.serviceClient<dji_sdk::SetLocalPosRef> ("dji_sdk/set_local_pos_ref");

    ROS_INFO("INIT COMPLETE,NOW TRY TO OBTAIN CONTROL");

/*****************M100获得控制器与起飞*************************/
/*****************M100 Obtain Control And Takeoff*************************/
    bool obtain_control_result = obtain_control();
   // if(obtain_control_result)
   // {
    //    ROS_INFO("obtain control result success");
    //}
    bool M100monitoredTakeoff_result = M100monitoredTakeoff();
	if(!M100monitoredTakeoff_result)
	{
		ROS_INFO("Take off failed, break the code!!!");
		return 0;
	}
/*****************Working**********************/
    ros::Time start_time = ros::Time::now();
	ros::spinOnce();

    ROS_INFO("wait for 10sec");

    while (ros::Time::now() - start_time < ros::Duration(10))
    {
        ros::Duration(0.01).sleep();
        ros::spinOnce();
    }
    bool M100monitoredLand_result = M100monitoredLand();
    if(!M100monitoredLand_result)
    {//降落指令发送失败
	    ROS_WARN("land failed,keep origin pose");
	}

  return 0;


}



/*******函数定义*********/

void flight_status_callback(const std_msgs::UInt8::ConstPtr& msg)
{
  flight_status = msg->data;
}

bool takeoff_land(int task)
{
	dji_sdk::DroneTaskControl droneTaskControl;

	droneTaskControl.request.task = task;

	drone_task_service.call(droneTaskControl);

	if (!droneTaskControl.response.result)
	{
		ROS_ERROR("takeoff_land fail");
		return false;
	}

	return true;
}

bool obtain_control()
{
  dji_sdk::SDKControlAuthority authority;
  authority.request.control_enable=1;
  sdk_ctrl_authority_service.call(authority);

  if(!authority.response.result)
  {
    ROS_ERROR("obtain control failed");
    return false;
  }
  ROS_INFO("obtain control success");
  return true;
}

// DJI_M100 Takeoff check: if success return True
// Notice: NO check GPS because takeoff indoor 
bool M100monitoredTakeoff()
{
  ros::Time start_time = ros::Time::now();

  //这里有修改，删去了 float home_altitude = current_gps_position.altitude;
  if(!takeoff_land(dji_sdk::DroneTaskControl::Request::TASK_TAKEOFF))
  {
    ROS_INFO("take-off failed");
    return false;
  }
  ROS_INFO("droneTaskControl——takeoff success sent");

  ros::Duration(0.01).sleep();
  ros::spinOnce();
  // Step 1: If M100 is not in the air after 10 seconds, fail.
  ROS_INFO("wait for 10sec");
  while (ros::Time::now() - start_time < ros::Duration(10))
  {
    ros::Duration(0.01).sleep();
    ros::spinOnce();
  }

  if(flight_status != DJISDK::M100FlightStatus::M100_STATUS_IN_AIR ) 
      //这里有修改，删去了||current_gps_position.altitude - home_altitude < 1.0
  {
    ROS_ERROR("flight status is not M100_STATUS_IN_AIR or distance to ground<1m，take-off failed");
    return false;
  }
  else
  {
    start_time = ros::Time::now();
    ROS_INFO("flight status is M100_STATUS_IN_AIR or distance to ground>1m，take-off success");
    ros::spinOnce();
  }
  return true;
}

//dji jiangluo 
bool M100monitoredLand(){
	dji_sdk::DroneTaskControl droneTaskControl;
	droneTaskControl.request.task = 6;//6 shi jiangluo 
	drone_task_service.call(droneTaskControl);
	if(!droneTaskControl.response.result) {
		ROS_WARN("land failed");
	return false;
  }
  return true;
}
