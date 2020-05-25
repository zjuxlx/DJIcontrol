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
#include <sensor_msgs/Joy.h>



class UAVstatefromDJI
{
public:
    // 是否完成任务标示
    bool finishmission = 0; 
    //mission = 0 :悬停；
    //mission = 1 :给定点跟踪;
    //misiion = 2 :视觉跟踪;
    int missionflag = 1; 

    Eigen::Vector3d gps_local_position;//在仿真中使用
    //Eigen::Vector3d slam_position;//在实验中使用
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
        //仿真使用
        localPositionSub = state_nh.subscribe("dji_sdk/local_position", 10, &SubStatefromDJI::local_position_callback,this);
    }
    ~SubStatefromDJI(){}
private:
    ros::NodeHandle state_nh;

    ros::Subscriber attitudeSub;
    ros::Subscriber velocitySub;
    ros::Subscriber ImuSub;
    //仿真使用
    ros::Subscriber localPositionSub;


    void toEulerAngle(Eigen::Quaterniond quat)
    {
        quad_state.attitude = quaternion_to_euler(quat);
        //std::cout <<"attitude:"<<quad_state.attitude<<std::endl;
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
    void local_position_callback(const geometry_msgs::PointStamped::ConstPtr& msg)
    {
        quad_state.gps_local_position[0] = msg->point.x;
        quad_state.gps_local_position[1] = msg->point.y;
        quad_state.gps_local_position[2] = msg->point.z;

    }


   
};
/**************M100控制函数声明*************/
bool obtain_control();
bool takeoff_land(int task);//Take_off使用
bool M100monitoredTakeoff();
bool M100monitoredLand();
void flight_status_callback(const std_msgs::UInt8::ConstPtr& msg);
//void setTarget(float x, float y, float z, float yaw);//目标位置和偏航角
bool set_local_position();

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

/****** 命令发布*************/
    ros::Publisher ctrlVelYawratePub;
    ros::Publisher ctrlPosYawPub;
    ctrlVelYawratePub = nh.advertise<sensor_msgs::Joy>("dji_sdk/flight_control_setpoint_ENUvelocity_yawrate", 10);
    ctrlPosYawPub = nh.advertise<sensor_msgs::Joy>("dji_sdk/flight_control_setpoint_ENUposition_yaw", 10);
    

/*****************M100获得控制器与起飞*************************/
/*****************M100 Obtain Control And Takeoff*************************/
    ROS_INFO("INIT COMPLETE,NOW TRY TO OBTAIN CONTROL");
    bool obtain_control_result = obtain_control();
   // if(obtain_control_result)
   // {
    //    ROS_INFO("obtain control result success");
    //}

/****** 仿真时检测 *******实验中请删除***/
    if (!set_local_position())
    {
      ROS_ERROR("GPS health insufficient - No local frame reference for height. Exiting.");
      return 1;
    }
/****** 仿真时检测 *******/


    bool M100monitoredTakeoff_result = M100monitoredTakeoff();
	if(!M100monitoredTakeoff_result)
	{
		ROS_INFO("Take off failed, break the code!!!");
		return 0;
	}
/*****************Working**********************/
    // ros::Time start_time = ros::Time::now();
	// ros::spinOnce();

    // ROS_INFO("wait for 10sec");

    // while (ros::Time::now() - start_time < ros::Duration(10))
    // {
    //     ros::Duration(0.01).sleep();
    //     ros::spinOnce();
    // }
    double xCmd, yCmd, zCmd;

float target_offset_x;
float target_offset_y;
float target_offset_z;
float target_yaw;
    ros::Rate loop_rate(20);
    ros::Time start_time = ros::Time::now();
    bool timeout = 0;

    while(ros::ok() && (!SubStateObject.quad_state.finishmission) && (!timeout))
    {
        ros::spinOnce();
        ros::Time Now_time = ros::Time::now();
        if (SubStateObject.quad_state.missionflag == 0)
        {
            //悬停任务
            //ROS_INFO("mission is Loiter");            
            sensor_msgs::Joy controlVelYaw;
            controlVelYaw.axes.push_back(0);
			controlVelYaw.axes.push_back(0);
			controlVelYaw.axes.push_back(0);
			controlVelYaw.axes.push_back(0);
			ctrlVelYawratePub.publish(controlVelYaw);
            
        }
        if (SubStateObject.quad_state.missionflag == 1)
        {
            //setTarget(10, 15, 25, 2);
	    target_offset_x = 10;
	    target_offset_y = 15;
	    target_offset_z = 10;
	    target_yaw = 2;

            xCmd = target_offset_x - SubStateObject.quad_state.gps_local_position[0];
            yCmd = target_offset_y - SubStateObject.quad_state.gps_local_position[1];
            zCmd = target_offset_z - SubStateObject.quad_state.gps_local_position[2];

            sensor_msgs::Joy controlPosYaw;
            controlPosYaw.axes.push_back(xCmd);
            controlPosYaw.axes.push_back(yCmd);
            controlPosYaw.axes.push_back(zCmd);
            controlPosYaw.axes.push_back(target_yaw);
            ctrlPosYawPub.publish(controlPosYaw);

            if (((std::abs(xCmd)) < 0.1) && ((std::abs(yCmd)) < 0.1) &&(SubStateObject.quad_state.gps_local_position[2] > (target_offset_z - 0.1)) && (SubStateObject.quad_state.gps_local_position[2] < (target_offset_z + 0.1))) 
            {
                 SubStateObject.quad_state.finishmission = 1;
                 ROS_INFO("target complete");
            }

        }  
        //任务时间限定超时退出
        // if (Now_time - start_time >= ros::Duration(10))
        // {
        //     timeout =1;
        // } 
        //控制发布命令频率
        loop_rate.sleep();
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


//void setTarget(float x, float y, float z, float yaw)
//{
//  target_offset_x = x;
//  target_offset_y = y;
//  target_offset_z = z;
//  target_yaw      = yaw;
//}


bool set_local_position()
{
  dji_sdk::SetLocalPosRef localPosReferenceSetter;
  set_local_pos_reference.call(localPosReferenceSetter);

  return (bool)localPosReferenceSetter.response.result;
}
