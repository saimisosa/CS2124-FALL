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
CMAKE_COMMAND = "/Volumes/Sandisk Extreme SSD Media/Apps/CLion/ch-0/193.6015.37/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Volumes/Sandisk Extreme SSD Media/Apps/CLion/ch-0/193.6015.37/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/exam2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/exam2/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/exam2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/exam2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exam2.dir/flags.make

CMakeFiles/exam2.dir/main.cpp.o: CMakeFiles/exam2.dir/flags.make
CMakeFiles/exam2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/exam2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/exam2.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/exam2.dir/main.cpp.o -c "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/exam2/main.cpp"

CMakeFiles/exam2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exam2.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/exam2/main.cpp" > CMakeFiles/exam2.dir/main.cpp.i

CMakeFiles/exam2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exam2.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/exam2/main.cpp" -o CMakeFiles/exam2.dir/main.cpp.s

# Object files for target exam2
exam2_OBJECTS = \
"CMakeFiles/exam2.dir/main.cpp.o"

# External object files for target exam2
exam2_EXTERNAL_OBJECTS =

exam2: CMakeFiles/exam2.dir/main.cpp.o
exam2: CMakeFiles/exam2.dir/build.make
exam2: CMakeFiles/exam2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/exam2/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable exam2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/exam2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exam2.dir/build: exam2

.PHONY : CMakeFiles/exam2.dir/build

CMakeFiles/exam2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/exam2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/exam2.dir/clean

CMakeFiles/exam2.dir/depend:
	cd "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/exam2/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/exam2" "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/exam2" "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/exam2/cmake-build-debug" "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/exam2/cmake-build-debug" "/Volumes/Sandisk Extreme SSD Media/CS2124 Projects/exam2/cmake-build-debug/CMakeFiles/exam2.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/exam2.dir/depend

