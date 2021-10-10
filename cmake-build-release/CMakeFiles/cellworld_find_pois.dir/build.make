# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Research/robot/cellworld_tools

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Research/robot/cellworld_tools/cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/cellworld_find_pois.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cellworld_find_pois.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cellworld_find_pois.dir/flags.make

CMakeFiles/cellworld_find_pois.dir/src/tools/find_pois.cpp.o: CMakeFiles/cellworld_find_pois.dir/flags.make
CMakeFiles/cellworld_find_pois.dir/src/tools/find_pois.cpp.o: ../src/tools/find_pois.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Research/robot/cellworld_tools/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cellworld_find_pois.dir/src/tools/find_pois.cpp.o"
	/usr/bin/g++-10  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cellworld_find_pois.dir/src/tools/find_pois.cpp.o -c /mnt/c/Research/robot/cellworld_tools/src/tools/find_pois.cpp

CMakeFiles/cellworld_find_pois.dir/src/tools/find_pois.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cellworld_find_pois.dir/src/tools/find_pois.cpp.i"
	/usr/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Research/robot/cellworld_tools/src/tools/find_pois.cpp > CMakeFiles/cellworld_find_pois.dir/src/tools/find_pois.cpp.i

CMakeFiles/cellworld_find_pois.dir/src/tools/find_pois.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cellworld_find_pois.dir/src/tools/find_pois.cpp.s"
	/usr/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Research/robot/cellworld_tools/src/tools/find_pois.cpp -o CMakeFiles/cellworld_find_pois.dir/src/tools/find_pois.cpp.s

# Object files for target cellworld_find_pois
cellworld_find_pois_OBJECTS = \
"CMakeFiles/cellworld_find_pois.dir/src/tools/find_pois.cpp.o"

# External object files for target cellworld_find_pois
cellworld_find_pois_EXTERNAL_OBJECTS =

cellworld_find_pois: CMakeFiles/cellworld_find_pois.dir/src/tools/find_pois.cpp.o
cellworld_find_pois: CMakeFiles/cellworld_find_pois.dir/build.make
cellworld_find_pois: libcellworld_tools.a
cellworld_find_pois: /usr/local/lib/libcellworld.a
cellworld_find_pois: /usr/local/lib/libjson-cpp.a
cellworld_find_pois: /usr/lib/x86_64-linux-gnu/libcurl.so
cellworld_find_pois: CMakeFiles/cellworld_find_pois.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Research/robot/cellworld_tools/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cellworld_find_pois"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cellworld_find_pois.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cellworld_find_pois.dir/build: cellworld_find_pois

.PHONY : CMakeFiles/cellworld_find_pois.dir/build

CMakeFiles/cellworld_find_pois.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cellworld_find_pois.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cellworld_find_pois.dir/clean

CMakeFiles/cellworld_find_pois.dir/depend:
	cd /mnt/c/Research/robot/cellworld_tools/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Research/robot/cellworld_tools /mnt/c/Research/robot/cellworld_tools /mnt/c/Research/robot/cellworld_tools/cmake-build-release /mnt/c/Research/robot/cellworld_tools/cmake-build-release /mnt/c/Research/robot/cellworld_tools/cmake-build-release/CMakeFiles/cellworld_find_pois.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cellworld_find_pois.dir/depend

