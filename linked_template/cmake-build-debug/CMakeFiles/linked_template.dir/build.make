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
CMAKE_SOURCE_DIR = C:\Users\Wit\CLionProjects\linked_template

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Wit\CLionProjects\linked_template\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/linked_template.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/linked_template.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/linked_template.dir/flags.make

CMakeFiles/linked_template.dir/main.cpp.obj: CMakeFiles/linked_template.dir/flags.make
CMakeFiles/linked_template.dir/main.cpp.obj: CMakeFiles/linked_template.dir/includes_CXX.rsp
CMakeFiles/linked_template.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Wit\CLionProjects\linked_template\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/linked_template.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\linked_template.dir\main.cpp.obj -c C:\Users\Wit\CLionProjects\linked_template\main.cpp

CMakeFiles/linked_template.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linked_template.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Wit\CLionProjects\linked_template\main.cpp > CMakeFiles\linked_template.dir\main.cpp.i

CMakeFiles/linked_template.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linked_template.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Wit\CLionProjects\linked_template\main.cpp -o CMakeFiles\linked_template.dir\main.cpp.s

# Object files for target linked_template
linked_template_OBJECTS = \
"CMakeFiles/linked_template.dir/main.cpp.obj"

# External object files for target linked_template
linked_template_EXTERNAL_OBJECTS =

linked_template.exe: CMakeFiles/linked_template.dir/main.cpp.obj
linked_template.exe: CMakeFiles/linked_template.dir/build.make
linked_template.exe: CMakeFiles/linked_template.dir/linklibs.rsp
linked_template.exe: CMakeFiles/linked_template.dir/objects1.rsp
linked_template.exe: CMakeFiles/linked_template.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Wit\CLionProjects\linked_template\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable linked_template.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\linked_template.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/linked_template.dir/build: linked_template.exe

.PHONY : CMakeFiles/linked_template.dir/build

CMakeFiles/linked_template.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\linked_template.dir\cmake_clean.cmake
.PHONY : CMakeFiles/linked_template.dir/clean

CMakeFiles/linked_template.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Wit\CLionProjects\linked_template C:\Users\Wit\CLionProjects\linked_template C:\Users\Wit\CLionProjects\linked_template\cmake-build-debug C:\Users\Wit\CLionProjects\linked_template\cmake-build-debug C:\Users\Wit\CLionProjects\linked_template\cmake-build-debug\CMakeFiles\linked_template.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/linked_template.dir/depend
