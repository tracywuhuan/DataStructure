cmake_minimum_required(VERSION 3.7)
project(Stack)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_COMPILER "g++")

set(SOURCE_FILES main.cpp Stack.cpp)
add_executable(Stack ${SOURCE_FILES})