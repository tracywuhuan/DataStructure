cmake_minimum_required(VERSION 3.7)
project(AVLTree)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_COMPILER g++)
set(SOURCE_FILES main.cpp AVLTree.cpp AVLTree.h)
add_executable(AVLTree ${SOURCE_FILES})