# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1.5\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1.5\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Asif\Desktop\Crypto\SteganographyImage

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Asif\Desktop\Crypto\SteganographyImage\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/qdbmpBitmap.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/qdbmpBitmap.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/qdbmpBitmap.dir/flags.make

CMakeFiles/qdbmpBitmap.dir/main.c.obj: CMakeFiles/qdbmpBitmap.dir/flags.make
CMakeFiles/qdbmpBitmap.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Asif\Desktop\Crypto\SteganographyImage\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/qdbmpBitmap.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\qdbmpBitmap.dir\main.c.obj   -c C:\Users\Asif\Desktop\Crypto\SteganographyImage\main.c

CMakeFiles/qdbmpBitmap.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/qdbmpBitmap.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Asif\Desktop\Crypto\SteganographyImage\main.c > CMakeFiles\qdbmpBitmap.dir\main.c.i

CMakeFiles/qdbmpBitmap.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/qdbmpBitmap.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Asif\Desktop\Crypto\SteganographyImage\main.c -o CMakeFiles\qdbmpBitmap.dir\main.c.s

CMakeFiles/qdbmpBitmap.dir/main.c.obj.requires:

.PHONY : CMakeFiles/qdbmpBitmap.dir/main.c.obj.requires

CMakeFiles/qdbmpBitmap.dir/main.c.obj.provides: CMakeFiles/qdbmpBitmap.dir/main.c.obj.requires
	$(MAKE) -f CMakeFiles\qdbmpBitmap.dir\build.make CMakeFiles/qdbmpBitmap.dir/main.c.obj.provides.build
.PHONY : CMakeFiles/qdbmpBitmap.dir/main.c.obj.provides

CMakeFiles/qdbmpBitmap.dir/main.c.obj.provides.build: CMakeFiles/qdbmpBitmap.dir/main.c.obj


CMakeFiles/qdbmpBitmap.dir/qdbmp.c.obj: CMakeFiles/qdbmpBitmap.dir/flags.make
CMakeFiles/qdbmpBitmap.dir/qdbmp.c.obj: ../qdbmp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Asif\Desktop\Crypto\SteganographyImage\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/qdbmpBitmap.dir/qdbmp.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\qdbmpBitmap.dir\qdbmp.c.obj   -c C:\Users\Asif\Desktop\Crypto\SteganographyImage\qdbmp.c

CMakeFiles/qdbmpBitmap.dir/qdbmp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/qdbmpBitmap.dir/qdbmp.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Asif\Desktop\Crypto\SteganographyImage\qdbmp.c > CMakeFiles\qdbmpBitmap.dir\qdbmp.c.i

CMakeFiles/qdbmpBitmap.dir/qdbmp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/qdbmpBitmap.dir/qdbmp.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Asif\Desktop\Crypto\SteganographyImage\qdbmp.c -o CMakeFiles\qdbmpBitmap.dir\qdbmp.c.s

CMakeFiles/qdbmpBitmap.dir/qdbmp.c.obj.requires:

.PHONY : CMakeFiles/qdbmpBitmap.dir/qdbmp.c.obj.requires

CMakeFiles/qdbmpBitmap.dir/qdbmp.c.obj.provides: CMakeFiles/qdbmpBitmap.dir/qdbmp.c.obj.requires
	$(MAKE) -f CMakeFiles\qdbmpBitmap.dir\build.make CMakeFiles/qdbmpBitmap.dir/qdbmp.c.obj.provides.build
.PHONY : CMakeFiles/qdbmpBitmap.dir/qdbmp.c.obj.provides

CMakeFiles/qdbmpBitmap.dir/qdbmp.c.obj.provides.build: CMakeFiles/qdbmpBitmap.dir/qdbmp.c.obj


# Object files for target qdbmpBitmap
qdbmpBitmap_OBJECTS = \
"CMakeFiles/qdbmpBitmap.dir/main.c.obj" \
"CMakeFiles/qdbmpBitmap.dir/qdbmp.c.obj"

# External object files for target qdbmpBitmap
qdbmpBitmap_EXTERNAL_OBJECTS =

qdbmpBitmap.exe: CMakeFiles/qdbmpBitmap.dir/main.c.obj
qdbmpBitmap.exe: CMakeFiles/qdbmpBitmap.dir/qdbmp.c.obj
qdbmpBitmap.exe: CMakeFiles/qdbmpBitmap.dir/build.make
qdbmpBitmap.exe: CMakeFiles/qdbmpBitmap.dir/linklibs.rsp
qdbmpBitmap.exe: CMakeFiles/qdbmpBitmap.dir/objects1.rsp
qdbmpBitmap.exe: CMakeFiles/qdbmpBitmap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Asif\Desktop\Crypto\SteganographyImage\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable qdbmpBitmap.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\qdbmpBitmap.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/qdbmpBitmap.dir/build: qdbmpBitmap.exe

.PHONY : CMakeFiles/qdbmpBitmap.dir/build

CMakeFiles/qdbmpBitmap.dir/requires: CMakeFiles/qdbmpBitmap.dir/main.c.obj.requires
CMakeFiles/qdbmpBitmap.dir/requires: CMakeFiles/qdbmpBitmap.dir/qdbmp.c.obj.requires

.PHONY : CMakeFiles/qdbmpBitmap.dir/requires

CMakeFiles/qdbmpBitmap.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\qdbmpBitmap.dir\cmake_clean.cmake
.PHONY : CMakeFiles/qdbmpBitmap.dir/clean

CMakeFiles/qdbmpBitmap.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Asif\Desktop\Crypto\SteganographyImage C:\Users\Asif\Desktop\Crypto\SteganographyImage C:\Users\Asif\Desktop\Crypto\SteganographyImage\cmake-build-debug C:\Users\Asif\Desktop\Crypto\SteganographyImage\cmake-build-debug C:\Users\Asif\Desktop\Crypto\SteganographyImage\cmake-build-debug\CMakeFiles\qdbmpBitmap.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/qdbmpBitmap.dir/depend
