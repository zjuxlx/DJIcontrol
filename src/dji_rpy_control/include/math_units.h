/***************************************************************************************************************************
* math_utils.h
*
* Author: XLX
*
* Update Time: 2020.5.13
*
* Introduction:  math utils functions 数学工具函数
*
* 1、 ref tohttps://github.com/amov-lab/px4_command/blob/master/include/math_utils.h
***************************************************************************************************************************/
#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <iostream>
#include <math.h>
#include <Eigen/Geometry>
#include <Eigen/Core>

#define C_PI (double)3.141592653589793
#define DEG2RAD(DEG) ((DEG) * ((C_PI) / (180.0)))
#define RAD2DEG(RAD) ((RAD) * ((180.2) / (C_PI)))
#define GRAVITY (double)9.8



// 四元数转欧拉角
Eigen::Vector3d quaternion_to_rpy2(const Eigen::Quaterniond &q)
{
   	// YPR - ZYX  偏航、俯仰、翻滚
    	//"2" represents the z axis and "0" the x axis
        return q.toRotationMatrix().eulerAngles(2, 1, 0).reverse();
}

// 相对于物体自身的坐标系统（称为intrinsic rotations）
// 从(roll,pitch,yaw)创建四元数  by a 3-2-1 intrinsic Tait-Bryan rotation sequence
Eigen::Quaterniond quaternion_from_rpy(const Eigen::Vector3d &rpy)
{
        // YPR - ZYX
        return Eigen::Quaterniond(
                        Eigen::AngleAxisd(rpy.z(), Eigen::Vector3d::UnitZ()) *
                        Eigen::AngleAxisd(rpy.y(), Eigen::Vector3d::UnitY()) *
                        Eigen::AngleAxisd(rpy.x(), Eigen::Vector3d::UnitX())
                        );
}

// 将四元数转换至(roll,pitch,yaw)  by a 3-2-1 intrinsic Tait-Bryan rotation sequence
// https://en.wikipedia.org/wiki/Conversion_between_quaternions_and_Euler_angles
// q0 q1 q2 q3
// w x y z
// 输出为弧度制
Eigen::Vector3d quaternion_to_euler(const Eigen::Quaterniond &q)
{
    float quat[4];
    quat[0] = q.w();
    quat[1] = q.x();
    quat[2] = q.y();
    quat[3] = q.z();

    Eigen::Vector3d ans;
    ans[0] = atan2(2.0 * (quat[3] * quat[2] + quat[0] * quat[1]), 1.0 - 2.0 * (quat[1] * quat[1] + quat[2] * quat[2]));
    ans[1] = asin(2.0 * (quat[2] * quat[0] - quat[3] * quat[1]));
    ans[2] = atan2(2.0 * (quat[3] * quat[0] + quat[1] * quat[2]), 1.0 - 2.0 * (quat[2] * quat[2] + quat[3] * quat[3]));
    return ans;
}
// 将四元数转换至(roll,pitch,yaw)  by a 3-2-1 intrinsic Tait-Bryan rotation sequence
// https://en.wikipedia.org/wiki/Conversion_between_quaternions_and_Euler_angles
// q0 q1 q2 q3
// w x y z
// 输出为角度制
Eigen::Vector3d quaternion_to_euler_angle(const Eigen::Quaterniond &q)
{
    float quat[4];
    quat[0] = q.w();
    quat[1] = q.x();
    quat[2] = q.y();
    quat[3] = q.z();

    Eigen::Vector3d ans;
    ans[0] = RAD2DEG(atan2(2.0 * (quat[3] * quat[2] + quat[0] * quat[1]), 1.0 - 2.0 * (quat[1] * quat[1] + quat[2] * quat[2])));
    ans[1] = RAD2DEG(asin(2.0 * (quat[2] * quat[0] - quat[3] * quat[1])));
    ans[2] = RAD2DEG(atan2(2.0 * (quat[3] * quat[0] + quat[1] * quat[2]), 1.0 - 2.0 * (quat[2] * quat[2] + quat[3] * quat[3])));
    return ans;
}


//旋转矩阵转欧拉角
void rotation_to_euler(const Eigen::Matrix3d& dcm, Eigen::Vector3d& euler_angle)
{
    double phi_val = atan2(dcm(2, 1), dcm(2, 2));
    double theta_val = asin(-dcm(2, 0));
    double psi_val = atan2(dcm(1, 0), dcm(0, 0));
    double pi = M_PI;

    if (fabs(theta_val - pi / 2.0) < 1.0e-3) {
        phi_val = 0.0;
        psi_val = atan2(dcm(1, 2), dcm(0, 2));

    } else if (fabs(theta_val + pi / 2.0) <  1.0e-3) {
        phi_val = 0.0;
        psi_val = atan2(-dcm(1, 2), -dcm(0, 2));
    }

    euler_angle(0) = phi_val;
    euler_angle(1) = theta_val;
    euler_angle(2) = psi_val;
}


//constrain_function
float constrain_function(float data, float Max)
{
    if(abs(data)>Max)
    {
        return (data > 0) ? Max : -Max;
    }
    else
    {
        return data;
    }
}

//constrain_function2
float constrain_function2(float data, float Min,float Max)
{
    if(data > Max)
    {
        return Max;
    }
    else if (data < Min)
    {
        return Min;
    }else
    {
        return data;
    }
}

//sign_function
float sign_function(float data)
{
    if(data>0)
    {
        return 1.0;
    }
    else if(data<0)
    {
        return -1.0;
    }
    else if(data == 0)
    {
        return 0.0;
    }
}

// min function
float min(float data1,float data2)
{
    if(data1>=data2)
    {
        return data2;
    }
    else
    {
        return data1;
    }
}


#endif