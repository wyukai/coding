# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
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
CMAKE_BINARY_DIR = D:\person\code\coding\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\coding.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\coding.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\coding.dir\flags.make

CMakeFiles\coding.dir\knowledges\cpp_ref.cpp.obj: CMakeFiles\coding.dir\flags.make
CMakeFiles\coding.dir\knowledges\cpp_ref.cpp.obj: ..\knowledges\cpp_ref.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\person\code\coding\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/coding.dir/knowledges/cpp_ref.cpp.obj"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\coding.dir\knowledges\cpp_ref.cpp.obj /FdCMakeFiles\coding.dir\ /FS -c D:\person\code\coding\knowledges\cpp_ref.cpp
<<

CMakeFiles\coding.dir\knowledges\cpp_ref.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/coding.dir/knowledges/cpp_ref.cpp.i"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\coding.dir\knowledges\cpp_ref.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\person\code\coding\knowledges\cpp_ref.cpp
<<

CMakeFiles\coding.dir\knowledges\cpp_ref.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/coding.dir/knowledges/cpp_ref.cpp.s"
	C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\coding.dir\knowledges\cpp_ref.cpp.s /c D:\person\code\coding\knowledges\cpp_ref.cpp
<<

# Object files for target coding
coding_OBJECTS = \
"CMakeFiles\coding.dir\knowledges\cpp_ref.cpp.obj"

# External object files for target coding
coding_EXTERNAL_OBJECTS =

coding.exe: CMakeFiles\coding.dir\knowledges\cpp_ref.cpp.obj
coding.exe: CMakeFiles\coding.dir\build.make
coding.exe: CMakeFiles\coding.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\person\code\coding\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable coding.exe"
	"D:\software\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\coding.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\coding.dir\objects1.rsp @<<
 /out:coding.exe /implib:coding.lib /pdb:D:\person\code\coding\cmake-build-debug\coding.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\coding.dir\build: coding.exe

.PHONY : CMakeFiles\coding.dir\build

CMakeFiles\coding.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\coding.dir\cmake_clean.cmake
.PHONY : CMakeFiles\coding.dir\clean

CMakeFiles\coding.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\person\code\coding D:\person\code\coding D:\person\code\coding\cmake-build-debug D:\person\code\coding\cmake-build-debug D:\person\code\coding\cmake-build-debug\CMakeFiles\coding.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\coding.dir\depend

