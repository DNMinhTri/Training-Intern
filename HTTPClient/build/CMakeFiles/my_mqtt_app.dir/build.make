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
CMAKE_SOURCE_DIR = /home/tri/Downloads/HTTPClient

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tri/Downloads/HTTPClient/build

# Include any dependencies generated for this target.
include CMakeFiles/my_mqtt_app.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/my_mqtt_app.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/my_mqtt_app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_mqtt_app.dir/flags.make

CMakeFiles/my_mqtt_app.dir/main.cpp.o: CMakeFiles/my_mqtt_app.dir/flags.make
CMakeFiles/my_mqtt_app.dir/main.cpp.o: ../main.cpp
CMakeFiles/my_mqtt_app.dir/main.cpp.o: CMakeFiles/my_mqtt_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tri/Downloads/HTTPClient/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_mqtt_app.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/my_mqtt_app.dir/main.cpp.o -MF CMakeFiles/my_mqtt_app.dir/main.cpp.o.d -o CMakeFiles/my_mqtt_app.dir/main.cpp.o -c /home/tri/Downloads/HTTPClient/main.cpp

CMakeFiles/my_mqtt_app.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_mqtt_app.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tri/Downloads/HTTPClient/main.cpp > CMakeFiles/my_mqtt_app.dir/main.cpp.i

CMakeFiles/my_mqtt_app.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_mqtt_app.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tri/Downloads/HTTPClient/main.cpp -o CMakeFiles/my_mqtt_app.dir/main.cpp.s

CMakeFiles/my_mqtt_app.dir/network_lib/HttpClient.cpp.o: CMakeFiles/my_mqtt_app.dir/flags.make
CMakeFiles/my_mqtt_app.dir/network_lib/HttpClient.cpp.o: ../network_lib/HttpClient.cpp
CMakeFiles/my_mqtt_app.dir/network_lib/HttpClient.cpp.o: CMakeFiles/my_mqtt_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tri/Downloads/HTTPClient/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/my_mqtt_app.dir/network_lib/HttpClient.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/my_mqtt_app.dir/network_lib/HttpClient.cpp.o -MF CMakeFiles/my_mqtt_app.dir/network_lib/HttpClient.cpp.o.d -o CMakeFiles/my_mqtt_app.dir/network_lib/HttpClient.cpp.o -c /home/tri/Downloads/HTTPClient/network_lib/HttpClient.cpp

CMakeFiles/my_mqtt_app.dir/network_lib/HttpClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_mqtt_app.dir/network_lib/HttpClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tri/Downloads/HTTPClient/network_lib/HttpClient.cpp > CMakeFiles/my_mqtt_app.dir/network_lib/HttpClient.cpp.i

CMakeFiles/my_mqtt_app.dir/network_lib/HttpClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_mqtt_app.dir/network_lib/HttpClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tri/Downloads/HTTPClient/network_lib/HttpClient.cpp -o CMakeFiles/my_mqtt_app.dir/network_lib/HttpClient.cpp.s

# Object files for target my_mqtt_app
my_mqtt_app_OBJECTS = \
"CMakeFiles/my_mqtt_app.dir/main.cpp.o" \
"CMakeFiles/my_mqtt_app.dir/network_lib/HttpClient.cpp.o"

# External object files for target my_mqtt_app
my_mqtt_app_EXTERNAL_OBJECTS =

bin/my_mqtt_app: CMakeFiles/my_mqtt_app.dir/main.cpp.o
bin/my_mqtt_app: CMakeFiles/my_mqtt_app.dir/network_lib/HttpClient.cpp.o
bin/my_mqtt_app: CMakeFiles/my_mqtt_app.dir/build.make
bin/my_mqtt_app: /usr/lib/x86_64-linux-gnu/libcrypto.so
bin/my_mqtt_app: /usr/lib/x86_64-linux-gnu/libssl.so
bin/my_mqtt_app: /usr/lib/x86_64-linux-gnu/libcrypto.so
bin/my_mqtt_app: CMakeFiles/my_mqtt_app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tri/Downloads/HTTPClient/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable bin/my_mqtt_app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_mqtt_app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_mqtt_app.dir/build: bin/my_mqtt_app
.PHONY : CMakeFiles/my_mqtt_app.dir/build

CMakeFiles/my_mqtt_app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_mqtt_app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_mqtt_app.dir/clean

CMakeFiles/my_mqtt_app.dir/depend:
	cd /home/tri/Downloads/HTTPClient/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tri/Downloads/HTTPClient /home/tri/Downloads/HTTPClient /home/tri/Downloads/HTTPClient/build /home/tri/Downloads/HTTPClient/build /home/tri/Downloads/HTTPClient/build/CMakeFiles/my_mqtt_app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_mqtt_app.dir/depend

