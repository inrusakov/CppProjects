# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\xiaomi\Desktop\Work\2 course\Algorithms\3 module\6 Contest\DoubleLinkedList"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\xiaomi\Desktop\Work\2 course\Algorithms\3 module\6 Contest\DoubleLinkedList\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\DoubleLinkedList.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\DoubleLinkedList.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\DoubleLinkedList.dir\flags.make

CMakeFiles\DoubleLinkedList.dir\main.cpp.obj: CMakeFiles\DoubleLinkedList.dir\flags.make
CMakeFiles\DoubleLinkedList.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\xiaomi\Desktop\Work\2 course\Algorithms\3 module\6 Contest\DoubleLinkedList\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DoubleLinkedList.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\DoubleLinkedList.dir\main.cpp.obj /FdCMakeFiles\DoubleLinkedList.dir\ /FS -c "C:\Users\xiaomi\Desktop\Work\2 course\Algorithms\3 module\6 Contest\DoubleLinkedList\main.cpp"
<<

CMakeFiles\DoubleLinkedList.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DoubleLinkedList.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\DoubleLinkedList.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\xiaomi\Desktop\Work\2 course\Algorithms\3 module\6 Contest\DoubleLinkedList\main.cpp"
<<

CMakeFiles\DoubleLinkedList.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DoubleLinkedList.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\DoubleLinkedList.dir\main.cpp.s /c "C:\Users\xiaomi\Desktop\Work\2 course\Algorithms\3 module\6 Contest\DoubleLinkedList\main.cpp"
<<

# Object files for target DoubleLinkedList
DoubleLinkedList_OBJECTS = \
"CMakeFiles\DoubleLinkedList.dir\main.cpp.obj"

# External object files for target DoubleLinkedList
DoubleLinkedList_EXTERNAL_OBJECTS =

DoubleLinkedList.exe: CMakeFiles\DoubleLinkedList.dir\main.cpp.obj
DoubleLinkedList.exe: CMakeFiles\DoubleLinkedList.dir\build.make
DoubleLinkedList.exe: CMakeFiles\DoubleLinkedList.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\xiaomi\Desktop\Work\2 course\Algorithms\3 module\6 Contest\DoubleLinkedList\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DoubleLinkedList.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\DoubleLinkedList.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\DoubleLinkedList.dir\objects1.rsp @<<
 /out:DoubleLinkedList.exe /implib:DoubleLinkedList.lib /pdb:"C:\Users\xiaomi\Desktop\Work\2 course\Algorithms\3 module\6 Contest\DoubleLinkedList\cmake-build-debug\DoubleLinkedList.pdb" /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\DoubleLinkedList.dir\build: DoubleLinkedList.exe
.PHONY : CMakeFiles\DoubleLinkedList.dir\build

CMakeFiles\DoubleLinkedList.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DoubleLinkedList.dir\cmake_clean.cmake
.PHONY : CMakeFiles\DoubleLinkedList.dir\clean

CMakeFiles\DoubleLinkedList.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\xiaomi\Desktop\Work\2 course\Algorithms\3 module\6 Contest\DoubleLinkedList" "C:\Users\xiaomi\Desktop\Work\2 course\Algorithms\3 module\6 Contest\DoubleLinkedList" "C:\Users\xiaomi\Desktop\Work\2 course\Algorithms\3 module\6 Contest\DoubleLinkedList\cmake-build-debug" "C:\Users\xiaomi\Desktop\Work\2 course\Algorithms\3 module\6 Contest\DoubleLinkedList\cmake-build-debug" "C:\Users\xiaomi\Desktop\Work\2 course\Algorithms\3 module\6 Contest\DoubleLinkedList\cmake-build-debug\CMakeFiles\DoubleLinkedList.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\DoubleLinkedList.dir\depend

