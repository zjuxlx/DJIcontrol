/** @file dji_try.h
 *  @version 3.3
 *  @date 2018.11.23
 *
 *  @brief
 *  try 1 take_off and landing 
 *
 *  @copyright 2018 DJI. All rights reserved.
 *  xlx 
 */
#ifndef DJI_TRY_H
#define DJI_TRY_H

// ROS includes
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


#include <tf/tf.h>
#include <sensor_msgs/Joy.h>
#include <iostream>
#include <fstream>
#include <math.h>


#define C_EARTH (double)6378137.0
#define C_PI (double)3.141592653589793
#define DEG2RAD(DEG) ((DEG) * ((C_PI) / (180.0)))

/*!
 * @brief a bare bone state machine to track the stage of the mission
 */


 



/**************回调函数声明*****************/


/**************M100控制函数声明*************/
bool obtain_control();
bool takeoff_land(int task);//Take_off使用
bool M100monitoredTakeoff();
bool M100monitoredLand();


void flight_status_callback(const std_msgs::UInt8::ConstPtr& msg);




#endif // DJI_TRY_H
