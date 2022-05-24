cmake_minimum_required(VERSION 3.22)
project(pong)

set(CMAKE_CXX_STANDARD 14)

#add_executable(pong main.cpp)
# Our Project

add_executable(${PROJECT_NAME} main.cpp)
#set(raylib_VERBOSE 1)
target_link_libraries(${PROJECT_NAME} raylib)

