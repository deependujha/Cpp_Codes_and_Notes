CMAKE_MINIMUM_REQUIRED(VERSION 3.16)

project(learn_cmake)

add_executable(${PROJECT_NAME} learn_cmake.cpp) # variable => PROJECT_NAME

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
