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
CMAKE_COMMAND = "/Volumes/Sandisk Xtreme External SSD/Jetbrains Tools/apps/CLion/ch-1/193.5233.144/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Volumes/Sandisk Xtreme External SSD/Jetbrains Tools/apps/CLion/ch-1/193.5233.144/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Volumes/Sandisk Xtreme External SSD/CS2124 Projects/rec13"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Volumes/Sandisk Xtreme External SSD/CS2124 Projects/rec13/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/rec13.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rec13.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rec13.dir/flags.make

CMakeFiles/rec13.dir/rec13.cpp.o: CMakeFiles/rec13.dir/flags.make
CMakeFiles/rec13.dir/rec13.cpp.o: ../rec13.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Volumes/Sandisk Xtreme External SSD/CS2124 Projects/rec13/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rec13.dir/rec13.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rec13.dir/rec13.cpp.o -c "/Volumes/Sandisk Xtreme External SSD/CS2124 Projects/rec13/rec13.cpp"

CMakeFiles/rec13.dir/rec13.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rec13.dir/rec13.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Volumes/Sandisk Xtreme External SSD/CS2124 Projects/rec13/rec13.cpp" > CMakeFiles/rec13.dir/rec13.cpp.i

CMakeFiles/rec13.dir/rec13.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rec13.dir/rec13.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Volumes/Sandisk Xtreme External SSD/CS2124 Projects/rec13/rec13.cpp" -o CMakeFiles/rec13.dir/rec13.cpp.s

# Object files for target rec13
rec13_OBJECTS = \
"CMakeFiles/rec13.dir/rec13.cpp.o"

# External object files for target rec13
rec13_EXTERNAL_OBJECTS =

rec13: CMakeFiles/rec13.dir/rec13.cpp.o
rec13: CMakeFiles/rec13.dir/build.make
rec13: CMakeFiles/rec13.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Volumes/Sandisk Xtreme External SSD/CS2124 Projects/rec13/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rec13"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rec13.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rec13.dir/build: rec13

.PHONY : CMakeFiles/rec13.dir/build

CMakeFiles/rec13.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rec13.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rec13.dir/clean

CMakeFiles/rec13.dir/depend:
	cd "/Volumes/Sandisk Xtreme External SSD/CS2124 Projects/rec13/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Volumes/Sandisk Xtreme External SSD/CS2124 Projects/rec13" "/Volumes/Sandisk Xtreme External SSD/CS2124 Projects/rec13" "/Volumes/Sandisk Xtreme External SSD/CS2124 Projects/rec13/cmake-build-debug" "/Volumes/Sandisk Xtreme External SSD/CS2124 Projects/rec13/cmake-build-debug" "/Volumes/Sandisk Xtreme External SSD/CS2124 Projects/rec13/cmake-build-debug/CMakeFiles/rec13.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/rec13.dir/depend

