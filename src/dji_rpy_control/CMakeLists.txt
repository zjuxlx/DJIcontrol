cmake_minimum_required(VERSION 2.8.3)
project(dji_rpy_control)


# Add module path for <name>.cmake conf files
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
	sensor_msgs
        roscpp
        std_msgs
        geometry_msgs
        nav_msgs
        cv_bridge
        dji_sdk
        image_transport
        )

find_package(DJIOSDK REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)


set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
#下句话不能漏下，会没有执行文件
catkin_package(
        #  INCLUDE_DIRS include
        #  LIBRARIES dji_sdk_demo
        #  CATKIN_DEPENDS dji_sdk roscpp
        #  DEPENDS dji_sdk
)


include_directories(
        include
        ${catkin_INCLUDE_DIRS}
        ${EIGEN3_INCLUDE_DIR}
#	${OpenCV_INCLUDE_DIRS}
)

add_executable(dji_rpy_control
        src/djirpycontrol.cpp)
target_link_libraries(dji_rpy_control
        ${catkin_LIBRARIES}
        ${DJIOSDK_LIBRARIES}
        )
add_dependencies(dji_rpy_control ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS} dji_sdk_generate_messages_cpp)
