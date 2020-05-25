//
// Created by xlx on 2020/5/11.
//
#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <iostream>
#include <fstream>
#include <string>
#include <Eigen/Eigen>


#include "kbhitubuntu.h"
#include "math_units.h"
#include "SubState.h"


int main(int argc, char** argv)
{
    
    ros::init(argc,argv,"statesubscriber");

    // ros::NodeHandle nh("~");
    ros::NodeHandle nh;
    SubState SubStateObject(nh);

    //int i;
    //std::string filename = "/home/xlx/odometry.txt";
    //std::ofstream outFile(filename);

    while(ros::ok&&(!kbhit()))
    {
        ros::spinOnce();
        //outFile << SubStateObject.quad_state.det_time;
        //for(i=0;i<3;i++)
        //{
        // outFile << SubStateObject.quad_state.position[i];
        //}
        //outFile<<'\n';
        
    }
    //outFile.close();
    std::cout << "Subsrcibe state stop!" << std::endl;

    return 0;
}
