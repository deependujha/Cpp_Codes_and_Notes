# CMAKE usage

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
