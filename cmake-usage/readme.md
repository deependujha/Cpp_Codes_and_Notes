# CMAKE usage

## Best resource to learn about cmake

- https://github.com/ttroy50/cmake-examples

---

- cmake is a build system generator tool for C/C++ projects.
- It is a cross-platform tool that can generate build files for many different build systems.

- You don't have to write makefiles for your project, cmake will generate them for you (depending on the build system you are using, like, make, ninja, xcode, etc.)

---

## Basics

- Cmake looks for a file named `CMakeLists.txt` in the root of your project.
- This file contains the instructions for cmake to build your project.
- The file is written in a simple text format.
- Then you run `cmake` to generate the build files.

```bash
cmake -S <source_dir> -B <build_dir>
```

- You can build project anywhere, but the standard is to build in a separate directory, and keep the source and build directories separate & clean.

```bash
mkdir build
cd build
cmake .. # assumes CMakeLists.txt file is in the ../ directory and you are in the build directory
```

---

## `CMakeLists.txt` contents

- Basically, you specify `cmake version`
- `project name`
- `add_executable` command to specify the cpp file to be compiled and the name of the output executable

```cmake
# A simple `CMakeLists.txt` file looks like this:

CMAKE_MINIMUM_REQUIRED(VERSION 3.16)

project(learn_cmake)

add_executable(${PROJECT_NAME} learn_cmake.cpp) # variable => PROJECT_NAME
```

- To build the project, run `cmake` command in the build directory:

```bash
mkdir build
cd build
cmake .. # assumes CMakeLists.txt file is in the ../ directory and you are in the build directory

# ==============================

make # run make command to build the project
./learn_cmake # run the executable
```

---

## Installing the executable

```cmake
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
```

- `install` command is used to install the executable to the specified directory (in linux, it is `/usr/bin` by default).
- `TARGETS` specifies the executable to be installed.
- `DESTINATION` specifies the directory to install the executable to.

> - In build directory, run `sudo make install` to install the executable to `/usr/bin` directory.
> - `sudo` is required bcoz the executable is installed in a root directory.

---

## Print something & set/unset variables in CMake

- You can print something in CMake using `message` command with different modes (`STATUS`, `WARNING`, etc.).
- You can set/unset variables using `set` and `unset` commands.

```cmake
message(STATUS "A simple msg from Cmake file.")
message(WARNING "A warning msg from Cmake file.")

set(PYTORCH_VERSION "2.3.0")
set(PYTORCH_MIN_VERSION "1.12.0")
message(STATUS "Torch version ${Torch_VERSION}")
unset(PYTORCH_VERSION)
message(STATUS "Torch version ${Torch_VERSION}")
```

---

## Use a library in your C/C++ project

- Add a library to your project using `add_library` command.
- Link the library to your executable using `target_link_libraries` command.
- Specify the directory to search for the library using `target_link_directories` command.

```cmake
add_library(helper helper.cpp helper.h)

add_executable(${PROJECT_NAME} learn_cmake.cpp)

target_link_libraries(${PROJECT_NAME} helper)

target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
```

---

## `add_subdirectory`

- You can add a subdirectory to your project using `add_subdirectory` command.
- This calls `CMakeLists.txt` file in the subdirectory.

---

## Conditional compilation

- You can use `if` and `else` commands to conditionally compile your code.

```cmake
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "Compiler is GNU")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message(STATUS "Compiler is Clang")
else()
    message(STATUS "Unknown compiler")
endif()
```

---

## `if MSVC` (microsoft visual studio - windows)

- You can use `if` command to check if the compiler is microsoft visual studio.

```cmake
if(MSVC)
    message(STATUS "Compiler is MSVC")
endif()
```

---

## `execute_process`

- You can use `execute_process` command to execute a command and get the output.

```cmake
execute_process(COMMAND echo "Hello World" OUTPUT_VARIABLE output)  # will create a directory named meow in (build directory)
```

---

> There's a lot more commands in CMake, you can check them out [here](https://cmake.org/).
