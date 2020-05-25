#include <ros/ros.h>
#include <geometry_msgs/QuaternionStamped.h>
#include <geometry_msgs/Vector3Stamped.h>
#include <sensor_msgs/NavSatFix.h>
#include <std_msgs/UInt8.h>

#include <geometry_msgs/PointStamped.h>
#include <geometry_msgs/PoseStamped.h>

#include <std_msgs/Float32.h>
#include <sensor_msgs/Joy.h>

// DJI SDK includes
#include <dji_sdk/DroneTaskControl.h>
#include <dji_sdk/SDKControlAuthority.h>
#include <dji_sdk/QueryDroneVersion.h>
#include <dji_sdk/SetLocalPosRef.h>
#include "dji_sdk/dji_sdk.h"



#include <tf/tf.h>
#include <sensor_msgs/Joy.h>
#include <iostream>
#include <fstream>
#include <math.h>

#define C_EARTH (double)6378137.0
#define C_PI (double)3.141592653589793
#define DEG2RAD(DEG) ((DEG) * ((C_PI) / (180.0)))

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


int main(int argc, char** argv)
{
/******** ROS Initialization*************/
    ros::init(argc,argv,"dji_takeoff_noGPS_node");
    ros::NodeHandle nh;
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
    if(obtain_control_result)
    {
        ROS_INFO("obtain control result success");
    }
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