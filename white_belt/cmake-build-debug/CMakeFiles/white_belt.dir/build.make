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
CMAKE_SOURCE_DIR = C:\coding\learning\C++\white_belt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\coding\learning\C++\white_belt\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/white_belt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/white_belt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/white_belt.dir/flags.make

CMakeFiles/white_belt.dir/project_template.cpp.obj: CMakeFiles/white_belt.dir/flags.make
CMakeFiles/white_belt.dir/project_template.cpp.obj: ../project_template.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\coding\learning\C++\white_belt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/white_belt.dir/project_template.cpp.obj"
	C:\coding\mingw-w64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\white_belt.dir\project_template.cpp.obj -c C:\coding\learning\C++\white_belt\project_template.cpp

CMakeFiles/white_belt.dir/project_template.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/white_belt.dir/project_template.cpp.i"
	C:\coding\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\coding\learning\C++\white_belt\project_template.cpp > CMakeFiles\white_belt.dir\project_template.cpp.i

CMakeFiles/white_belt.dir/project_template.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/white_belt.dir/project_template.cpp.s"
	C:\coding\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\coding\learning\C++\white_belt\project_template.cpp -o CMakeFiles\white_belt.dir\project_template.cpp.s

# Object files for target white_belt
white_belt_OBJECTS = \
"CMakeFiles/white_belt.dir/project_template.cpp.obj"

# External object files for target white_belt
white_belt_EXTERNAL_OBJECTS =

white_belt.exe: CMakeFiles/white_belt.dir/project_template.cpp.obj
white_belt.exe: CMakeFiles/white_belt.dir/build.make
white_belt.exe: CMakeFiles/white_belt.dir/linklibs.rsp
white_belt.exe: CMakeFiles/white_belt.dir/objects1.rsp
white_belt.exe: CMakeFiles/white_belt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\coding\learning\C++\white_belt\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable white_belt.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\white_belt.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/white_belt.dir/build: white_belt.exe

.PHONY : CMakeFiles/white_belt.dir/build

CMakeFiles/white_belt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\white_belt.dir\cmake_clean.cmake
.PHONY : CMakeFiles/white_belt.dir/clean

CMakeFiles/white_belt.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\coding\learning\C++\white_belt C:\coding\learning\C++\white_belt C:\coding\learning\C++\white_belt\cmake-build-debug C:\coding\learning\C++\white_belt\cmake-build-debug C:\coding\learning\C++\white_belt\cmake-build-debug\CMakeFiles\white_belt.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/white_belt.dir/depend
