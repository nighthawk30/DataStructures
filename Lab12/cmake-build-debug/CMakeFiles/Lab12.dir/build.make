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
CMAKE_SOURCE_DIR = C:\Users\Wit\CLionProjects\Lab12

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Wit\CLionProjects\Lab12\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab12.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab12.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab12.dir/flags.make

CMakeFiles/Lab12.dir/tests.cpp.obj: CMakeFiles/Lab12.dir/flags.make
CMakeFiles/Lab12.dir/tests.cpp.obj: CMakeFiles/Lab12.dir/includes_CXX.rsp
CMakeFiles/Lab12.dir/tests.cpp.obj: ../tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Wit\CLionProjects\Lab12\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab12.dir/tests.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab12.dir\tests.cpp.obj -c C:\Users\Wit\CLionProjects\Lab12\tests.cpp

CMakeFiles/Lab12.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab12.dir/tests.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Wit\CLionProjects\Lab12\tests.cpp > CMakeFiles\Lab12.dir\tests.cpp.i

CMakeFiles/Lab12.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab12.dir/tests.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Wit\CLionProjects\Lab12\tests.cpp -o CMakeFiles\Lab12.dir\tests.cpp.s

CMakeFiles/Lab12.dir/unix_clock.cpp.obj: CMakeFiles/Lab12.dir/flags.make
CMakeFiles/Lab12.dir/unix_clock.cpp.obj: CMakeFiles/Lab12.dir/includes_CXX.rsp
CMakeFiles/Lab12.dir/unix_clock.cpp.obj: ../unix_clock.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Wit\CLionProjects\Lab12\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lab12.dir/unix_clock.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab12.dir\unix_clock.cpp.obj -c C:\Users\Wit\CLionProjects\Lab12\unix_clock.cpp

CMakeFiles/Lab12.dir/unix_clock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab12.dir/unix_clock.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Wit\CLionProjects\Lab12\unix_clock.cpp > CMakeFiles\Lab12.dir\unix_clock.cpp.i

CMakeFiles/Lab12.dir/unix_clock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab12.dir/unix_clock.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Wit\CLionProjects\Lab12\unix_clock.cpp -o CMakeFiles\Lab12.dir\unix_clock.cpp.s

# Object files for target Lab12
Lab12_OBJECTS = \
"CMakeFiles/Lab12.dir/tests.cpp.obj" \
"CMakeFiles/Lab12.dir/unix_clock.cpp.obj"

# External object files for target Lab12
Lab12_EXTERNAL_OBJECTS =

Lab12.exe: CMakeFiles/Lab12.dir/tests.cpp.obj
Lab12.exe: CMakeFiles/Lab12.dir/unix_clock.cpp.obj
Lab12.exe: CMakeFiles/Lab12.dir/build.make
Lab12.exe: CMakeFiles/Lab12.dir/linklibs.rsp
Lab12.exe: CMakeFiles/Lab12.dir/objects1.rsp
Lab12.exe: CMakeFiles/Lab12.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Wit\CLionProjects\Lab12\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Lab12.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lab12.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab12.dir/build: Lab12.exe

.PHONY : CMakeFiles/Lab12.dir/build

CMakeFiles/Lab12.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lab12.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lab12.dir/clean

CMakeFiles/Lab12.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Wit\CLionProjects\Lab12 C:\Users\Wit\CLionProjects\Lab12 C:\Users\Wit\CLionProjects\Lab12\cmake-build-debug C:\Users\Wit\CLionProjects\Lab12\cmake-build-debug C:\Users\Wit\CLionProjects\Lab12\cmake-build-debug\CMakeFiles\Lab12.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab12.dir/depend

