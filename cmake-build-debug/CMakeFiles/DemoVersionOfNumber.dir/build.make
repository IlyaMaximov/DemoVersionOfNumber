# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /snap/clion/103/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/103/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ilya/CLionProjects/DemoVersionOfNumber

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ilya/CLionProjects/DemoVersionOfNumber/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DemoVersionOfNumber.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DemoVersionOfNumber.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DemoVersionOfNumber.dir/flags.make

CMakeFiles/DemoVersionOfNumber.dir/main.cpp.o: CMakeFiles/DemoVersionOfNumber.dir/flags.make
CMakeFiles/DemoVersionOfNumber.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/CLionProjects/DemoVersionOfNumber/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DemoVersionOfNumber.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DemoVersionOfNumber.dir/main.cpp.o -c /home/ilya/CLionProjects/DemoVersionOfNumber/main.cpp

CMakeFiles/DemoVersionOfNumber.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DemoVersionOfNumber.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/CLionProjects/DemoVersionOfNumber/main.cpp > CMakeFiles/DemoVersionOfNumber.dir/main.cpp.i

CMakeFiles/DemoVersionOfNumber.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DemoVersionOfNumber.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/CLionProjects/DemoVersionOfNumber/main.cpp -o CMakeFiles/DemoVersionOfNumber.dir/main.cpp.s

CMakeFiles/DemoVersionOfNumber.dir/Graph.cpp.o: CMakeFiles/DemoVersionOfNumber.dir/flags.make
CMakeFiles/DemoVersionOfNumber.dir/Graph.cpp.o: ../Graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/CLionProjects/DemoVersionOfNumber/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DemoVersionOfNumber.dir/Graph.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DemoVersionOfNumber.dir/Graph.cpp.o -c /home/ilya/CLionProjects/DemoVersionOfNumber/Graph.cpp

CMakeFiles/DemoVersionOfNumber.dir/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DemoVersionOfNumber.dir/Graph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/CLionProjects/DemoVersionOfNumber/Graph.cpp > CMakeFiles/DemoVersionOfNumber.dir/Graph.cpp.i

CMakeFiles/DemoVersionOfNumber.dir/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DemoVersionOfNumber.dir/Graph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/CLionProjects/DemoVersionOfNumber/Graph.cpp -o CMakeFiles/DemoVersionOfNumber.dir/Graph.cpp.s

CMakeFiles/DemoVersionOfNumber.dir/Chart.cpp.o: CMakeFiles/DemoVersionOfNumber.dir/flags.make
CMakeFiles/DemoVersionOfNumber.dir/Chart.cpp.o: ../Chart.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/CLionProjects/DemoVersionOfNumber/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/DemoVersionOfNumber.dir/Chart.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DemoVersionOfNumber.dir/Chart.cpp.o -c /home/ilya/CLionProjects/DemoVersionOfNumber/Chart.cpp

CMakeFiles/DemoVersionOfNumber.dir/Chart.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DemoVersionOfNumber.dir/Chart.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/CLionProjects/DemoVersionOfNumber/Chart.cpp > CMakeFiles/DemoVersionOfNumber.dir/Chart.cpp.i

CMakeFiles/DemoVersionOfNumber.dir/Chart.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DemoVersionOfNumber.dir/Chart.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/CLionProjects/DemoVersionOfNumber/Chart.cpp -o CMakeFiles/DemoVersionOfNumber.dir/Chart.cpp.s

# Object files for target DemoVersionOfNumber
DemoVersionOfNumber_OBJECTS = \
"CMakeFiles/DemoVersionOfNumber.dir/main.cpp.o" \
"CMakeFiles/DemoVersionOfNumber.dir/Graph.cpp.o" \
"CMakeFiles/DemoVersionOfNumber.dir/Chart.cpp.o"

# External object files for target DemoVersionOfNumber
DemoVersionOfNumber_EXTERNAL_OBJECTS =

DemoVersionOfNumber: CMakeFiles/DemoVersionOfNumber.dir/main.cpp.o
DemoVersionOfNumber: CMakeFiles/DemoVersionOfNumber.dir/Graph.cpp.o
DemoVersionOfNumber: CMakeFiles/DemoVersionOfNumber.dir/Chart.cpp.o
DemoVersionOfNumber: CMakeFiles/DemoVersionOfNumber.dir/build.make
DemoVersionOfNumber: CMakeFiles/DemoVersionOfNumber.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ilya/CLionProjects/DemoVersionOfNumber/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable DemoVersionOfNumber"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DemoVersionOfNumber.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DemoVersionOfNumber.dir/build: DemoVersionOfNumber

.PHONY : CMakeFiles/DemoVersionOfNumber.dir/build

CMakeFiles/DemoVersionOfNumber.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DemoVersionOfNumber.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DemoVersionOfNumber.dir/clean

CMakeFiles/DemoVersionOfNumber.dir/depend:
	cd /home/ilya/CLionProjects/DemoVersionOfNumber/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ilya/CLionProjects/DemoVersionOfNumber /home/ilya/CLionProjects/DemoVersionOfNumber /home/ilya/CLionProjects/DemoVersionOfNumber/cmake-build-debug /home/ilya/CLionProjects/DemoVersionOfNumber/cmake-build-debug /home/ilya/CLionProjects/DemoVersionOfNumber/cmake-build-debug/CMakeFiles/DemoVersionOfNumber.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DemoVersionOfNumber.dir/depend

