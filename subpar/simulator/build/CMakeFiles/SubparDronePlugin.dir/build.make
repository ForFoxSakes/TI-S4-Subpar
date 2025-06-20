# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/TI-S4-Subpar/subpar/simulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/TI-S4-Subpar/subpar/simulator/build

# Include any dependencies generated for this target.
include CMakeFiles/SubparDronePlugin.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SubparDronePlugin.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SubparDronePlugin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SubparDronePlugin.dir/flags.make

CMakeFiles/SubparDronePlugin.dir/plugins/SubparDronePlugin.cc.o: CMakeFiles/SubparDronePlugin.dir/flags.make
CMakeFiles/SubparDronePlugin.dir/plugins/SubparDronePlugin.cc.o: ../plugins/SubparDronePlugin.cc
CMakeFiles/SubparDronePlugin.dir/plugins/SubparDronePlugin.cc.o: CMakeFiles/SubparDronePlugin.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/TI-S4-Subpar/subpar/simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SubparDronePlugin.dir/plugins/SubparDronePlugin.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SubparDronePlugin.dir/plugins/SubparDronePlugin.cc.o -MF CMakeFiles/SubparDronePlugin.dir/plugins/SubparDronePlugin.cc.o.d -o CMakeFiles/SubparDronePlugin.dir/plugins/SubparDronePlugin.cc.o -c /workspaces/TI-S4-Subpar/subpar/simulator/plugins/SubparDronePlugin.cc

CMakeFiles/SubparDronePlugin.dir/plugins/SubparDronePlugin.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SubparDronePlugin.dir/plugins/SubparDronePlugin.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/TI-S4-Subpar/subpar/simulator/plugins/SubparDronePlugin.cc > CMakeFiles/SubparDronePlugin.dir/plugins/SubparDronePlugin.cc.i

CMakeFiles/SubparDronePlugin.dir/plugins/SubparDronePlugin.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SubparDronePlugin.dir/plugins/SubparDronePlugin.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/TI-S4-Subpar/subpar/simulator/plugins/SubparDronePlugin.cc -o CMakeFiles/SubparDronePlugin.dir/plugins/SubparDronePlugin.cc.s

# Object files for target SubparDronePlugin
SubparDronePlugin_OBJECTS = \
"CMakeFiles/SubparDronePlugin.dir/plugins/SubparDronePlugin.cc.o"

# External object files for target SubparDronePlugin
SubparDronePlugin_EXTERNAL_OBJECTS =

libSubparDronePlugin.so: CMakeFiles/SubparDronePlugin.dir/plugins/SubparDronePlugin.cc.o
libSubparDronePlugin.so: CMakeFiles/SubparDronePlugin.dir/build.make
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libgz-sim9.so.9.1.0
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libgz-fuel_tools10.so.10.1.0
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libgz-gui9.so.9.0.1
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libgz-plugin3-loader.so.3.1.0
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libQt5QuickControls2.so.5.15.3
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libQt5Quick.so.5.15.3
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libQt5QmlModels.so.5.15.3
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libQt5Qml.so.5.15.3
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.3
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.3
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.3
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libgz-physics8.so.8.1.0
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libgz-plugin3.so.3.1.0
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libgz-rendering9.so.9.2.0
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libgz-common6-profiler.so.6.1.0
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libgz-common6-events.so.6.1.0
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libgz-common6-av.so.6.1.0
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libswscale.so
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libswscale.so
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libavdevice.so
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libavdevice.so
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libavformat.so
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libavformat.so
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libavcodec.so
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libavcodec.so
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libavutil.so
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libavutil.so
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libgz-common6-io.so.6.1.0
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libgz-common6-testing.so.6.1.0
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libgz-common6-geospatial.so.6.1.0
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libgz-common6-graphics.so.6.1.0
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libgz-common6.so.6.1.0
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libgz-utils3-log.so.3.1.1
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libspdlog.so.1.9.2
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libfmt.so.8.1.1
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libgz-transport14-parameters.so.14.1.0
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libgz-transport14.so.14.1.0
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libgz-msgs11.so.11.1.0
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libuuid.so
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libuuid.so
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libsdformat15.so.15.3.0
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libgz-math8.so.8.2.0
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libgz-utils3.so.3.1.1
libSubparDronePlugin.so: /usr/lib/x86_64-linux-gnu/libprotobuf.so
libSubparDronePlugin.so: CMakeFiles/SubparDronePlugin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/TI-S4-Subpar/subpar/simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libSubparDronePlugin.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SubparDronePlugin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SubparDronePlugin.dir/build: libSubparDronePlugin.so
.PHONY : CMakeFiles/SubparDronePlugin.dir/build

CMakeFiles/SubparDronePlugin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SubparDronePlugin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SubparDronePlugin.dir/clean

CMakeFiles/SubparDronePlugin.dir/depend:
	cd /workspaces/TI-S4-Subpar/subpar/simulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/TI-S4-Subpar/subpar/simulator /workspaces/TI-S4-Subpar/subpar/simulator /workspaces/TI-S4-Subpar/subpar/simulator/build /workspaces/TI-S4-Subpar/subpar/simulator/build /workspaces/TI-S4-Subpar/subpar/simulator/build/CMakeFiles/SubparDronePlugin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SubparDronePlugin.dir/depend

