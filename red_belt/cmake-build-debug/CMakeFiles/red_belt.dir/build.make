# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\coding\learning\C++\red_belt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\coding\learning\C++\red_belt\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/red_belt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/red_belt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/red_belt.dir/flags.make

CMakeFiles/red_belt.dir/priority_collection_2_2.cpp.obj: CMakeFiles/red_belt.dir/flags.make
CMakeFiles/red_belt.dir/priority_collection_2_2.cpp.obj: ../priority_collection_2_2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\coding\learning\C++\red_belt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/red_belt.dir/priority_collection_2_2.cpp.obj"
	C:\coding\mingw-w64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\red_belt.dir\priority_collection_2_2.cpp.obj -c C:\coding\learning\C++\red_belt\priority_collection_2_2.cpp

CMakeFiles/red_belt.dir/priority_collection_2_2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/red_belt.dir/priority_collection_2_2.cpp.i"
	C:\coding\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\coding\learning\C++\red_belt\priority_collection_2_2.cpp > CMakeFiles\red_belt.dir\priority_collection_2_2.cpp.i

CMakeFiles/red_belt.dir/priority_collection_2_2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/red_belt.dir/priority_collection_2_2.cpp.s"
	C:\coding\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\coding\learning\C++\red_belt\priority_collection_2_2.cpp -o CMakeFiles\red_belt.dir\priority_collection_2_2.cpp.s

# Object files for target red_belt
red_belt_OBJECTS = \
"CMakeFiles/red_belt.dir/priority_collection_2_2.cpp.obj"

# External object files for target red_belt
red_belt_EXTERNAL_OBJECTS =

red_belt.exe: CMakeFiles/red_belt.dir/priority_collection_2_2.cpp.obj
red_belt.exe: CMakeFiles/red_belt.dir/build.make
red_belt.exe: CMakeFiles/red_belt.dir/linklibs.rsp
red_belt.exe: CMakeFiles/red_belt.dir/objects1.rsp
red_belt.exe: CMakeFiles/red_belt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\coding\learning\C++\red_belt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable red_belt.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\red_belt.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/red_belt.dir/build: red_belt.exe

.PHONY : CMakeFiles/red_belt.dir/build

CMakeFiles/red_belt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\red_belt.dir\cmake_clean.cmake
.PHONY : CMakeFiles/red_belt.dir/clean

CMakeFiles/red_belt.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\coding\learning\C++\red_belt C:\coding\learning\C++\red_belt C:\coding\learning\C++\red_belt\cmake-build-debug C:\coding\learning\C++\red_belt\cmake-build-debug C:\coding\learning\C++\red_belt\cmake-build-debug\CMakeFiles\red_belt.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/red_belt.dir/depend

