cmake_minimum_required(VERSION 3.3)
project(lab_30)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp 123.cpp)
add_executable(lab_30 ${SOURCE_FILES})