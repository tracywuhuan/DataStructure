cmake_minimum_required(VERSION 3.7)
project(Queue)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_COMPILER g++)

set(SOURCE_FILES main.cpp Queue.cpp)
add_executable(Queue ${SOURCE_FILES})