# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/cmake-3.14.6/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.14.6/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xlx/catkin_ws_DJI/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xlx/catkin_ws_DJI/build

# Include any dependencies generated for this target.
include Onboard-SDK-ROS-3.7/dji_sdk_demo/CMakeFiles/demo_camera_gimbal.dir/depend.make

# Include the progress variables for this target.
include Onboard-SDK-ROS-3.7/dji_sdk_demo/CMakeFiles/demo_camera_gimbal.dir/progress.make

# Include the compile flags for this target's objects.
include Onboard-SDK-ROS-3.7/dji_sdk_demo/CMakeFiles/demo_camera_gimbal.dir/flags.make

Onboard-SDK-ROS-3.7/dji_sdk_demo/CMakeFiles/demo_camera_gimbal.dir/src/demo_camera_gimbal.cpp.o: Onboard-SDK-ROS-3.7/dji_sdk_demo/CMakeFiles/demo_camera_gimbal.dir/flags.make
Onboard-SDK-ROS-3.7/dji_sdk_demo/CMakeFiles/demo_camera_gimbal.dir/src/demo_camera_gimbal.cpp.o: /home/xlx/catkin_ws_DJI/src/Onboard-SDK-ROS-3.7/dji_sdk_demo/src/demo_camera_gimbal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xlx/catkin_ws_DJI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Onboard-SDK-ROS-3.7/dji_sdk_demo/CMakeFiles/demo_camera_gimbal.dir/src/demo_camera_gimbal.cpp.o"
	cd /home/xlx/catkin_ws_DJI/build/Onboard-SDK-ROS-3.7/dji_sdk_demo && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demo_camera_gimbal.dir/src/demo_camera_gimbal.cpp.o -c /home/xlx/catkin_ws_DJI/src/Onboard-SDK-ROS-3.7/dji_sdk_demo/src/demo_camera_gimbal.cpp

Onboard-SDK-ROS-3.7/dji_sdk_demo/CMakeFiles/demo_camera_gimbal.dir/src/demo_camera_gimbal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo_camera_gimbal.dir/src/demo_camera_gimbal.cpp.i"
	cd /home/xlx/catkin_ws_DJI/build/Onboard-SDK-ROS-3.7/dji_sdk_demo && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xlx/catkin_ws_DJI/src/Onboard-SDK-ROS-3.7/dji_sdk_demo/src/demo_camera_gimbal.cpp > CMakeFiles/demo_camera_gimbal.dir/src/demo_camera_gimbal.cpp.i

Onboard-SDK-ROS-3.7/dji_sdk_demo/CMakeFiles/demo_camera_gimbal.dir/src/demo_camera_gimbal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo_camera_gimbal.dir/src/demo_camera_gimbal.cpp.s"
	cd /home/xlx/catkin_ws_DJI/build/Onboard-SDK-ROS-3.7/dji_sdk_demo && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xlx/catkin_ws_DJI/src/Onboard-SDK-ROS-3.7/dji_sdk_demo/src/demo_camera_gimbal.cpp -o CMakeFiles/demo_camera_gimbal.dir/src/demo_camera_gimbal.cpp.s

# Object files for target demo_camera_gimbal
demo_camera_gimbal_OBJECTS = \
"CMakeFiles/demo_camera_gimbal.dir/src/demo_camera_gimbal.cpp.o"

# External object files for target demo_camera_gimbal
demo_camera_gimbal_EXTERNAL_OBJECTS =

/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: Onboard-SDK-ROS-3.7/dji_sdk_demo/CMakeFiles/demo_camera_gimbal.dir/src/demo_camera_gimbal.cpp.o
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: Onboard-SDK-ROS-3.7/dji_sdk_demo/CMakeFiles/demo_camera_gimbal.dir/build.make
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /opt/ros/kinetic/lib/libimage_transport.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /opt/ros/kinetic/lib/libmessage_filters.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /opt/ros/kinetic/lib/libclass_loader.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /usr/lib/libPocoFoundation.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /usr/lib/x86_64-linux-gnu/libdl.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /opt/ros/kinetic/lib/libroscpp.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /opt/ros/kinetic/lib/librosconsole.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /opt/ros/kinetic/lib/libxmlrpcpp.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /opt/ros/kinetic/lib/libroslib.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /opt/ros/kinetic/lib/librospack.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /usr/lib/x86_64-linux-gnu/libpython2.7.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /usr/lib/x86_64-linux-gnu/libtinyxml.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /opt/ros/kinetic/lib/libroscpp_serialization.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /opt/ros/kinetic/lib/librostime.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /opt/ros/kinetic/lib/libcpp_common.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: /usr/local/lib/libdjiosdk-core.a
/home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal: Onboard-SDK-ROS-3.7/dji_sdk_demo/CMakeFiles/demo_camera_gimbal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xlx/catkin_ws_DJI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal"
	cd /home/xlx/catkin_ws_DJI/build/Onboard-SDK-ROS-3.7/dji_sdk_demo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo_camera_gimbal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Onboard-SDK-ROS-3.7/dji_sdk_demo/CMakeFiles/demo_camera_gimbal.dir/build: /home/xlx/catkin_ws_DJI/devel/lib/dji_sdk_demo/demo_camera_gimbal

.PHONY : Onboard-SDK-ROS-3.7/dji_sdk_demo/CMakeFiles/demo_camera_gimbal.dir/build

Onboard-SDK-ROS-3.7/dji_sdk_demo/CMakeFiles/demo_camera_gimbal.dir/clean:
	cd /home/xlx/catkin_ws_DJI/build/Onboard-SDK-ROS-3.7/dji_sdk_demo && $(CMAKE_COMMAND) -P CMakeFiles/demo_camera_gimbal.dir/cmake_clean.cmake
.PHONY : Onboard-SDK-ROS-3.7/dji_sdk_demo/CMakeFiles/demo_camera_gimbal.dir/clean

Onboard-SDK-ROS-3.7/dji_sdk_demo/CMakeFiles/demo_camera_gimbal.dir/depend:
	cd /home/xlx/catkin_ws_DJI/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xlx/catkin_ws_DJI/src /home/xlx/catkin_ws_DJI/src/Onboard-SDK-ROS-3.7/dji_sdk_demo /home/xlx/catkin_ws_DJI/build /home/xlx/catkin_ws_DJI/build/Onboard-SDK-ROS-3.7/dji_sdk_demo /home/xlx/catkin_ws_DJI/build/Onboard-SDK-ROS-3.7/dji_sdk_demo/CMakeFiles/demo_camera_gimbal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Onboard-SDK-ROS-3.7/dji_sdk_demo/CMakeFiles/demo_camera_gimbal.dir/depend

