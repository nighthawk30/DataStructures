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
CMAKE_SOURCE_DIR = C:\Users\Wit\CLionProjects\DataStructures\Project4_Animal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Wit\CLionProjects\DataStructures\Project4_Animal\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Project4_Animal.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Project4_Animal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project4_Animal.dir/flags.make

CMakeFiles/Project4_Animal.dir/animal.cpp.obj: CMakeFiles/Project4_Animal.dir/flags.make
CMakeFiles/Project4_Animal.dir/animal.cpp.obj: ../animal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Wit\CLionProjects\DataStructures\Project4_Animal\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project4_Animal.dir/animal.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Project4_Animal.dir\animal.cpp.obj -c C:\Users\Wit\CLionProjects\DataStructures\Project4_Animal\animal.cpp

CMakeFiles/Project4_Animal.dir/animal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project4_Animal.dir/animal.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Wit\CLionProjects\DataStructures\Project4_Animal\animal.cpp > CMakeFiles\Project4_Animal.dir\animal.cpp.i

CMakeFiles/Project4_Animal.dir/animal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project4_Animal.dir/animal.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Wit\CLionProjects\DataStructures\Project4_Animal\animal.cpp -o CMakeFiles\Project4_Animal.dir\animal.cpp.s

# Object files for target Project4_Animal
Project4_Animal_OBJECTS = \
"CMakeFiles/Project4_Animal.dir/animal.cpp.obj"

# External object files for target Project4_Animal
Project4_Animal_EXTERNAL_OBJECTS =

Project4_Animal.exe: CMakeFiles/Project4_Animal.dir/animal.cpp.obj
Project4_Animal.exe: CMakeFiles/Project4_Animal.dir/build.make
Project4_Animal.exe: CMakeFiles/Project4_Animal.dir/linklibs.rsp
Project4_Animal.exe: CMakeFiles/Project4_Animal.dir/objects1.rsp
Project4_Animal.exe: CMakeFiles/Project4_Animal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Wit\CLionProjects\DataStructures\Project4_Animal\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Project4_Animal.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Project4_Animal.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project4_Animal.dir/build: Project4_Animal.exe

.PHONY : CMakeFiles/Project4_Animal.dir/build

CMakeFiles/Project4_Animal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Project4_Animal.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Project4_Animal.dir/clean

CMakeFiles/Project4_Animal.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Wit\CLionProjects\DataStructures\Project4_Animal C:\Users\Wit\CLionProjects\DataStructures\Project4_Animal C:\Users\Wit\CLionProjects\DataStructures\Project4_Animal\cmake-build-debug C:\Users\Wit\CLionProjects\DataStructures\Project4_Animal\cmake-build-debug C:\Users\Wit\CLionProjects\DataStructures\Project4_Animal\cmake-build-debug\CMakeFiles\Project4_Animal.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Project4_Animal.dir/depend

