# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Wit\CLionProjects\Lab4c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Wit\CLionProjects\Lab4c\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab4c.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab4c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab4c.dir/flags.make

CMakeFiles/Lab4c.dir/partc.cpp.obj: CMakeFiles/Lab4c.dir/flags.make
CMakeFiles/Lab4c.dir/partc.cpp.obj: ../partc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Wit\CLionProjects\Lab4c\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab4c.dir/partc.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab4c.dir\partc.cpp.obj -c C:\Users\Wit\CLionProjects\Lab4c\partc.cpp

CMakeFiles/Lab4c.dir/partc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab4c.dir/partc.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Wit\CLionProjects\Lab4c\partc.cpp > CMakeFiles\Lab4c.dir\partc.cpp.i

CMakeFiles/Lab4c.dir/partc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab4c.dir/partc.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Wit\CLionProjects\Lab4c\partc.cpp -o CMakeFiles\Lab4c.dir\partc.cpp.s

# Object files for target Lab4c
Lab4c_OBJECTS = \
"CMakeFiles/Lab4c.dir/partc.cpp.obj"

# External object files for target Lab4c
Lab4c_EXTERNAL_OBJECTS =

Lab4c.exe: CMakeFiles/Lab4c.dir/partc.cpp.obj
Lab4c.exe: CMakeFiles/Lab4c.dir/build.make
Lab4c.exe: CMakeFiles/Lab4c.dir/linklibs.rsp
Lab4c.exe: CMakeFiles/Lab4c.dir/objects1.rsp
Lab4c.exe: CMakeFiles/Lab4c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Wit\CLionProjects\Lab4c\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lab4c.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lab4c.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab4c.dir/build: Lab4c.exe

.PHONY : CMakeFiles/Lab4c.dir/build

CMakeFiles/Lab4c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lab4c.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lab4c.dir/clean

CMakeFiles/Lab4c.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Wit\CLionProjects\Lab4c C:\Users\Wit\CLionProjects\Lab4c C:\Users\Wit\CLionProjects\Lab4c\cmake-build-debug C:\Users\Wit\CLionProjects\Lab4c\cmake-build-debug C:\Users\Wit\CLionProjects\Lab4c\cmake-build-debug\CMakeFiles\Lab4c.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab4c.dir/depend

