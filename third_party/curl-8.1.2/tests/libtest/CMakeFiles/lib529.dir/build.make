# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/ProjectMetier/third_party/curl-8.1.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/ProjectMetier/third_party/curl-8.1.2

# Include any dependencies generated for this target.
include tests/libtest/CMakeFiles/lib529.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/libtest/CMakeFiles/lib529.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/libtest/CMakeFiles/lib529.dir/progress.make

# Include the compile flags for this target's objects.
include tests/libtest/CMakeFiles/lib529.dir/flags.make

tests/libtest/CMakeFiles/lib529.dir/lib525.c.o: tests/libtest/CMakeFiles/lib529.dir/flags.make
tests/libtest/CMakeFiles/lib529.dir/lib525.c.o: tests/libtest/lib525.c
tests/libtest/CMakeFiles/lib529.dir/lib525.c.o: tests/libtest/CMakeFiles/lib529.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ProjectMetier/third_party/curl-8.1.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/libtest/CMakeFiles/lib529.dir/lib525.c.o"
	cd /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/libtest/CMakeFiles/lib529.dir/lib525.c.o -MF CMakeFiles/lib529.dir/lib525.c.o.d -o CMakeFiles/lib529.dir/lib525.c.o -c /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest/lib525.c

tests/libtest/CMakeFiles/lib529.dir/lib525.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib529.dir/lib525.c.i"
	cd /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest/lib525.c > CMakeFiles/lib529.dir/lib525.c.i

tests/libtest/CMakeFiles/lib529.dir/lib525.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib529.dir/lib525.c.s"
	cd /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest/lib525.c -o CMakeFiles/lib529.dir/lib525.c.s

tests/libtest/CMakeFiles/lib529.dir/__/__/lib/timediff.c.o: tests/libtest/CMakeFiles/lib529.dir/flags.make
tests/libtest/CMakeFiles/lib529.dir/__/__/lib/timediff.c.o: lib/timediff.c
tests/libtest/CMakeFiles/lib529.dir/__/__/lib/timediff.c.o: tests/libtest/CMakeFiles/lib529.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ProjectMetier/third_party/curl-8.1.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/libtest/CMakeFiles/lib529.dir/__/__/lib/timediff.c.o"
	cd /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/libtest/CMakeFiles/lib529.dir/__/__/lib/timediff.c.o -MF CMakeFiles/lib529.dir/__/__/lib/timediff.c.o.d -o CMakeFiles/lib529.dir/__/__/lib/timediff.c.o -c /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/lib/timediff.c

tests/libtest/CMakeFiles/lib529.dir/__/__/lib/timediff.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib529.dir/__/__/lib/timediff.c.i"
	cd /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/lib/timediff.c > CMakeFiles/lib529.dir/__/__/lib/timediff.c.i

tests/libtest/CMakeFiles/lib529.dir/__/__/lib/timediff.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib529.dir/__/__/lib/timediff.c.s"
	cd /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/lib/timediff.c -o CMakeFiles/lib529.dir/__/__/lib/timediff.c.s

tests/libtest/CMakeFiles/lib529.dir/first.c.o: tests/libtest/CMakeFiles/lib529.dir/flags.make
tests/libtest/CMakeFiles/lib529.dir/first.c.o: tests/libtest/first.c
tests/libtest/CMakeFiles/lib529.dir/first.c.o: tests/libtest/CMakeFiles/lib529.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ProjectMetier/third_party/curl-8.1.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object tests/libtest/CMakeFiles/lib529.dir/first.c.o"
	cd /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/libtest/CMakeFiles/lib529.dir/first.c.o -MF CMakeFiles/lib529.dir/first.c.o.d -o CMakeFiles/lib529.dir/first.c.o -c /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest/first.c

tests/libtest/CMakeFiles/lib529.dir/first.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib529.dir/first.c.i"
	cd /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest/first.c > CMakeFiles/lib529.dir/first.c.i

tests/libtest/CMakeFiles/lib529.dir/first.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib529.dir/first.c.s"
	cd /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest/first.c -o CMakeFiles/lib529.dir/first.c.s

tests/libtest/CMakeFiles/lib529.dir/testutil.c.o: tests/libtest/CMakeFiles/lib529.dir/flags.make
tests/libtest/CMakeFiles/lib529.dir/testutil.c.o: tests/libtest/testutil.c
tests/libtest/CMakeFiles/lib529.dir/testutil.c.o: tests/libtest/CMakeFiles/lib529.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ProjectMetier/third_party/curl-8.1.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object tests/libtest/CMakeFiles/lib529.dir/testutil.c.o"
	cd /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/libtest/CMakeFiles/lib529.dir/testutil.c.o -MF CMakeFiles/lib529.dir/testutil.c.o.d -o CMakeFiles/lib529.dir/testutil.c.o -c /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest/testutil.c

tests/libtest/CMakeFiles/lib529.dir/testutil.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib529.dir/testutil.c.i"
	cd /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest/testutil.c > CMakeFiles/lib529.dir/testutil.c.i

tests/libtest/CMakeFiles/lib529.dir/testutil.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib529.dir/testutil.c.s"
	cd /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest/testutil.c -o CMakeFiles/lib529.dir/testutil.c.s

tests/libtest/CMakeFiles/lib529.dir/__/__/lib/warnless.c.o: tests/libtest/CMakeFiles/lib529.dir/flags.make
tests/libtest/CMakeFiles/lib529.dir/__/__/lib/warnless.c.o: lib/warnless.c
tests/libtest/CMakeFiles/lib529.dir/__/__/lib/warnless.c.o: tests/libtest/CMakeFiles/lib529.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ProjectMetier/third_party/curl-8.1.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object tests/libtest/CMakeFiles/lib529.dir/__/__/lib/warnless.c.o"
	cd /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/libtest/CMakeFiles/lib529.dir/__/__/lib/warnless.c.o -MF CMakeFiles/lib529.dir/__/__/lib/warnless.c.o.d -o CMakeFiles/lib529.dir/__/__/lib/warnless.c.o -c /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/lib/warnless.c

tests/libtest/CMakeFiles/lib529.dir/__/__/lib/warnless.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib529.dir/__/__/lib/warnless.c.i"
	cd /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/lib/warnless.c > CMakeFiles/lib529.dir/__/__/lib/warnless.c.i

tests/libtest/CMakeFiles/lib529.dir/__/__/lib/warnless.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib529.dir/__/__/lib/warnless.c.s"
	cd /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/lib/warnless.c -o CMakeFiles/lib529.dir/__/__/lib/warnless.c.s

tests/libtest/CMakeFiles/lib529.dir/__/__/lib/curl_multibyte.c.o: tests/libtest/CMakeFiles/lib529.dir/flags.make
tests/libtest/CMakeFiles/lib529.dir/__/__/lib/curl_multibyte.c.o: lib/curl_multibyte.c
tests/libtest/CMakeFiles/lib529.dir/__/__/lib/curl_multibyte.c.o: tests/libtest/CMakeFiles/lib529.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/ProjectMetier/third_party/curl-8.1.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object tests/libtest/CMakeFiles/lib529.dir/__/__/lib/curl_multibyte.c.o"
	cd /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/libtest/CMakeFiles/lib529.dir/__/__/lib/curl_multibyte.c.o -MF CMakeFiles/lib529.dir/__/__/lib/curl_multibyte.c.o.d -o CMakeFiles/lib529.dir/__/__/lib/curl_multibyte.c.o -c /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/lib/curl_multibyte.c

tests/libtest/CMakeFiles/lib529.dir/__/__/lib/curl_multibyte.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib529.dir/__/__/lib/curl_multibyte.c.i"
	cd /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/lib/curl_multibyte.c > CMakeFiles/lib529.dir/__/__/lib/curl_multibyte.c.i

tests/libtest/CMakeFiles/lib529.dir/__/__/lib/curl_multibyte.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib529.dir/__/__/lib/curl_multibyte.c.s"
	cd /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/lib/curl_multibyte.c -o CMakeFiles/lib529.dir/__/__/lib/curl_multibyte.c.s

# Object files for target lib529
lib529_OBJECTS = \
"CMakeFiles/lib529.dir/lib525.c.o" \
"CMakeFiles/lib529.dir/__/__/lib/timediff.c.o" \
"CMakeFiles/lib529.dir/first.c.o" \
"CMakeFiles/lib529.dir/testutil.c.o" \
"CMakeFiles/lib529.dir/__/__/lib/warnless.c.o" \
"CMakeFiles/lib529.dir/__/__/lib/curl_multibyte.c.o"

# External object files for target lib529
lib529_EXTERNAL_OBJECTS =

tests/libtest/lib529: tests/libtest/CMakeFiles/lib529.dir/lib525.c.o
tests/libtest/lib529: tests/libtest/CMakeFiles/lib529.dir/__/__/lib/timediff.c.o
tests/libtest/lib529: tests/libtest/CMakeFiles/lib529.dir/first.c.o
tests/libtest/lib529: tests/libtest/CMakeFiles/lib529.dir/testutil.c.o
tests/libtest/lib529: tests/libtest/CMakeFiles/lib529.dir/__/__/lib/warnless.c.o
tests/libtest/lib529: tests/libtest/CMakeFiles/lib529.dir/__/__/lib/curl_multibyte.c.o
tests/libtest/lib529: tests/libtest/CMakeFiles/lib529.dir/build.make
tests/libtest/lib529: lib/libcurl.so.4.8.0
tests/libtest/lib529: /usr/lib/x86_64-linux-gnu/libssl.so
tests/libtest/lib529: /usr/lib/x86_64-linux-gnu/libcrypto.so
tests/libtest/lib529: /usr/lib/x86_64-linux-gnu/libz.so
tests/libtest/lib529: tests/libtest/CMakeFiles/lib529.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/ProjectMetier/third_party/curl-8.1.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable lib529"
	cd /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lib529.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/libtest/CMakeFiles/lib529.dir/build: tests/libtest/lib529
.PHONY : tests/libtest/CMakeFiles/lib529.dir/build

tests/libtest/CMakeFiles/lib529.dir/clean:
	cd /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest && $(CMAKE_COMMAND) -P CMakeFiles/lib529.dir/cmake_clean.cmake
.PHONY : tests/libtest/CMakeFiles/lib529.dir/clean

tests/libtest/CMakeFiles/lib529.dir/depend:
	cd /home/ubuntu/ProjectMetier/third_party/curl-8.1.2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/ProjectMetier/third_party/curl-8.1.2 /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest /home/ubuntu/ProjectMetier/third_party/curl-8.1.2 /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest /home/ubuntu/ProjectMetier/third_party/curl-8.1.2/tests/libtest/CMakeFiles/lib529.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/libtest/CMakeFiles/lib529.dir/depend

