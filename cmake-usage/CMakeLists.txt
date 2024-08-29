
CMAKE_MINIMUM_REQUIRED(VERSION 3.16)

project(learn_cmake)
# message(STATUS "A simple msg from Cmake file.")
# message(WARNING "A warning msg from Cmake file.")

# set(PYTORCH_VERSION "2.3.0")
# message(STATUS "Torch version ${PYTORCH_VERSION}")
# unset(PYTORCH_VERSION)
# message(STATUS "Torch version ${PYTORCH_VERSION}")

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "Compiler is GNU")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message(STATUS "Compiler is Clang")
else()
    message(STATUS "Unknown compiler")
endif()

execute_process(COMMAND mkdir meow OUTPUT_VARIABLE output) # will create a directory named meow in (build directory)

add_library(helper lib/helper.cpp lib/helper.h)

add_executable(${PROJECT_NAME} learn_cmake.cpp) # variable => PROJECT_NAME

target_link_libraries(${PROJECT_NAME} helper)

# target_link_directories(helper PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
