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
include getstatedjiraw/CMakeFiles/getstatedjiraw.dir/depend.make

# Include the progress variables for this target.
include getstatedjiraw/CMakeFiles/getstatedjiraw.dir/progress.make

# Include the compile flags for this target's objects.
include getstatedjiraw/CMakeFiles/getstatedjiraw.dir/flags.make

getstatedjiraw/CMakeFiles/getstatedjiraw.dir/src/getstatedjiraw.cpp.o: getstatedjiraw/CMakeFiles/getstatedjiraw.dir/flags.make
getstatedjiraw/CMakeFiles/getstatedjiraw.dir/src/getstatedjiraw.cpp.o: /home/xlx/catkin_ws_DJI/src/getstatedjiraw/src/getstatedjiraw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xlx/catkin_ws_DJI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object getstatedjiraw/CMakeFiles/getstatedjiraw.dir/src/getstatedjiraw.cpp.o"
	cd /home/xlx/catkin_ws_DJI/build/getstatedjiraw && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/getstatedjiraw.dir/src/getstatedjiraw.cpp.o -c /home/xlx/catkin_ws_DJI/src/getstatedjiraw/src/getstatedjiraw.cpp

getstatedjiraw/CMakeFiles/getstatedjiraw.dir/src/getstatedjiraw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/getstatedjiraw.dir/src/getstatedjiraw.cpp.i"
	cd /home/xlx/catkin_ws_DJI/build/getstatedjiraw && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xlx/catkin_ws_DJI/src/getstatedjiraw/src/getstatedjiraw.cpp > CMakeFiles/getstatedjiraw.dir/src/getstatedjiraw.cpp.i

getstatedjiraw/CMakeFiles/getstatedjiraw.dir/src/getstatedjiraw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/getstatedjiraw.dir/src/getstatedjiraw.cpp.s"
	cd /home/xlx/catkin_ws_DJI/build/getstatedjiraw && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xlx/catkin_ws_DJI/src/getstatedjiraw/src/getstatedjiraw.cpp -o CMakeFiles/getstatedjiraw.dir/src/getstatedjiraw.cpp.s

# Object files for target getstatedjiraw
getstatedjiraw_OBJECTS = \
"CMakeFiles/getstatedjiraw.dir/src/getstatedjiraw.cpp.o"

# External object files for target getstatedjiraw
getstatedjiraw_EXTERNAL_OBJECTS =

/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: getstatedjiraw/CMakeFiles/getstatedjiraw.dir/src/getstatedjiraw.cpp.o
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: getstatedjiraw/CMakeFiles/getstatedjiraw.dir/build.make
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /opt/ros/kinetic/lib/libcv_bridge.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_core3.so.3.3.1
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_imgproc3.so.3.3.1
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /opt/ros/kinetic/lib/x86_64-linux-gnu/libopencv_imgcodecs3.so.3.3.1
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /opt/ros/kinetic/lib/libimage_transport.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /opt/ros/kinetic/lib/libmessage_filters.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /opt/ros/kinetic/lib/libclass_loader.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /usr/lib/libPocoFoundation.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /usr/lib/x86_64-linux-gnu/libdl.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /opt/ros/kinetic/lib/libroscpp.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /opt/ros/kinetic/lib/librosconsole.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /opt/ros/kinetic/lib/libxmlrpcpp.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /opt/ros/kinetic/lib/libroslib.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /opt/ros/kinetic/lib/librospack.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /usr/lib/x86_64-linux-gnu/libpython2.7.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /usr/lib/x86_64-linux-gnu/libtinyxml.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /opt/ros/kinetic/lib/libroscpp_serialization.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /opt/ros/kinetic/lib/librostime.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /opt/ros/kinetic/lib/libcpp_common.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: /usr/local/lib/libdjiosdk-core.a
/home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw: getstatedjiraw/CMakeFiles/getstatedjiraw.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xlx/catkin_ws_DJI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw"
	cd /home/xlx/catkin_ws_DJI/build/getstatedjiraw && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/getstatedjiraw.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
getstatedjiraw/CMakeFiles/getstatedjiraw.dir/build: /home/xlx/catkin_ws_DJI/devel/lib/getstatedjiraw/getstatedjiraw

.PHONY : getstatedjiraw/CMakeFiles/getstatedjiraw.dir/build

getstatedjiraw/CMakeFiles/getstatedjiraw.dir/clean:
	cd /home/xlx/catkin_ws_DJI/build/getstatedjiraw && $(CMAKE_COMMAND) -P CMakeFiles/getstatedjiraw.dir/cmake_clean.cmake
.PHONY : getstatedjiraw/CMakeFiles/getstatedjiraw.dir/clean

getstatedjiraw/CMakeFiles/getstatedjiraw.dir/depend:
	cd /home/xlx/catkin_ws_DJI/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xlx/catkin_ws_DJI/src /home/xlx/catkin_ws_DJI/src/getstatedjiraw /home/xlx/catkin_ws_DJI/build /home/xlx/catkin_ws_DJI/build/getstatedjiraw /home/xlx/catkin_ws_DJI/build/getstatedjiraw/CMakeFiles/getstatedjiraw.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : getstatedjiraw/CMakeFiles/getstatedjiraw.dir/depend

