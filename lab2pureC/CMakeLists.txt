cmake_minimum_required(VERSION 3.3)
project(lab2pureC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c")
set(SOURCE_FILES main.c)
set(CMAKE_C_IMPLICIT_LINK_LIBRARIES -lm)
add_executable(lab2pureC ${SOURCE_FILES})