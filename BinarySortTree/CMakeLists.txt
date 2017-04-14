cmake_minimum_required(VERSION 3.7)
project(BinarySortTree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BinarySortTree.cpp BinarySortTree.h)
add_executable(BinarySortTree ${SOURCE_FILES})