cmake_minimum_required(VERSION 4.2)
project(CS210Fall26)

set(CMAKE_CXX_STANDARD 20)

add_executable(Week2 Week2/main.cpp
        Week2/shape_utility.h
        Week2/shape_utility.cpp)
add_executable(Week4 Week4/main.cpp
        Week4/ArrayList.h)