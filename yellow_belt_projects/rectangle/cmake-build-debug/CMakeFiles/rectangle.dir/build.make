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
CMAKE_COMMAND = "C:\Users\lisav\AppData\Local\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\lisav\AppData\Local\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\dev\learning\C++\yellow_belt_projects\rectangle

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\dev\learning\C++\yellow_belt_projects\rectangle\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/rectangle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rectangle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rectangle.dir/flags.make

CMakeFiles/rectangle.dir/main.cpp.obj: CMakeFiles/rectangle.dir/flags.make
CMakeFiles/rectangle.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\dev\learning\C++\yellow_belt_projects\rectangle\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rectangle.dir/main.cpp.obj"
	C:\dev\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\rectangle.dir\main.cpp.obj -c C:\dev\learning\C++\yellow_belt_projects\rectangle\main.cpp

CMakeFiles/rectangle.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rectangle.dir/main.cpp.i"
	C:\dev\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\dev\learning\C++\yellow_belt_projects\rectangle\main.cpp > CMakeFiles\rectangle.dir\main.cpp.i

CMakeFiles/rectangle.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rectangle.dir/main.cpp.s"
	C:\dev\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\dev\learning\C++\yellow_belt_projects\rectangle\main.cpp -o CMakeFiles\rectangle.dir\main.cpp.s

CMakeFiles/rectangle.dir/rectangle.cpp.obj: CMakeFiles/rectangle.dir/flags.make
CMakeFiles/rectangle.dir/rectangle.cpp.obj: ../rectangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\dev\learning\C++\yellow_belt_projects\rectangle\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/rectangle.dir/rectangle.cpp.obj"
	C:\dev\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\rectangle.dir\rectangle.cpp.obj -c C:\dev\learning\C++\yellow_belt_projects\rectangle\rectangle.cpp

CMakeFiles/rectangle.dir/rectangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rectangle.dir/rectangle.cpp.i"
	C:\dev\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\dev\learning\C++\yellow_belt_projects\rectangle\rectangle.cpp > CMakeFiles\rectangle.dir\rectangle.cpp.i

CMakeFiles/rectangle.dir/rectangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rectangle.dir/rectangle.cpp.s"
	C:\dev\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\dev\learning\C++\yellow_belt_projects\rectangle\rectangle.cpp -o CMakeFiles\rectangle.dir\rectangle.cpp.s

# Object files for target rectangle
rectangle_OBJECTS = \
"CMakeFiles/rectangle.dir/main.cpp.obj" \
"CMakeFiles/rectangle.dir/rectangle.cpp.obj"

# External object files for target rectangle
rectangle_EXTERNAL_OBJECTS =

rectangle.exe: CMakeFiles/rectangle.dir/main.cpp.obj
rectangle.exe: CMakeFiles/rectangle.dir/rectangle.cpp.obj
rectangle.exe: CMakeFiles/rectangle.dir/build.make
rectangle.exe: CMakeFiles/rectangle.dir/linklibs.rsp
rectangle.exe: CMakeFiles/rectangle.dir/objects1.rsp
rectangle.exe: CMakeFiles/rectangle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\dev\learning\C++\yellow_belt_projects\rectangle\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable rectangle.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\rectangle.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rectangle.dir/build: rectangle.exe

.PHONY : CMakeFiles/rectangle.dir/build

CMakeFiles/rectangle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\rectangle.dir\cmake_clean.cmake
.PHONY : CMakeFiles/rectangle.dir/clean

CMakeFiles/rectangle.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\dev\learning\C++\yellow_belt_projects\rectangle C:\dev\learning\C++\yellow_belt_projects\rectangle C:\dev\learning\C++\yellow_belt_projects\rectangle\cmake-build-debug C:\dev\learning\C++\yellow_belt_projects\rectangle\cmake-build-debug C:\dev\learning\C++\yellow_belt_projects\rectangle\cmake-build-debug\CMakeFiles\rectangle.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rectangle.dir/depend

