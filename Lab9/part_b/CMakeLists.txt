cmake_minimum_required(VERSION 3.17)
project(part_b)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(part_b
        hash_functions.h
        main.cpp)
