# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "D:\software\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\software\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\person\code\coding

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\person\code\coding\cmake-build-debug-mingw

# Include any dependencies generated for this target.
include CMakeFiles/coding.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/coding.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/coding.dir/flags.make

CMakeFiles/coding.dir/tree/printTree.cpp.obj: CMakeFiles/coding.dir/flags.make
CMakeFiles/coding.dir/tree/printTree.cpp.obj: ../tree/printTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\person\code\coding\cmake-build-debug-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/coding.dir/tree/printTree.cpp.obj"
	D:\software\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\coding.dir\tree\printTree.cpp.obj -c D:\person\code\coding\tree\printTree.cpp

CMakeFiles/coding.dir/tree/printTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coding.dir/tree/printTree.cpp.i"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\person\code\coding\tree\printTree.cpp > CMakeFiles\coding.dir\tree\printTree.cpp.i

CMakeFiles/coding.dir/tree/printTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coding.dir/tree/printTree.cpp.s"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\person\code\coding\tree\printTree.cpp -o CMakeFiles\coding.dir\tree\printTree.cpp.s

# Object files for target coding
coding_OBJECTS = \
"CMakeFiles/coding.dir/tree/printTree.cpp.obj"

# External object files for target coding
coding_EXTERNAL_OBJECTS =

coding.exe: CMakeFiles/coding.dir/tree/printTree.cpp.obj
coding.exe: CMakeFiles/coding.dir/build.make
coding.exe: CMakeFiles/coding.dir/linklibs.rsp
coding.exe: CMakeFiles/coding.dir/objects1.rsp
coding.exe: CMakeFiles/coding.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\person\code\coding\cmake-build-debug-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable coding.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\coding.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/coding.dir/build: coding.exe

.PHONY : CMakeFiles/coding.dir/build

CMakeFiles/coding.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\coding.dir\cmake_clean.cmake
.PHONY : CMakeFiles/coding.dir/clean

CMakeFiles/coding.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\person\code\coding D:\person\code\coding D:\person\code\coding\cmake-build-debug-mingw D:\person\code\coding\cmake-build-debug-mingw D:\person\code\coding\cmake-build-debug-mingw\CMakeFiles\coding.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/coding.dir/depend

