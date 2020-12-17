cmake_minimum_required(VERSION 3.17)
project(part_a)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(part_a
        hash_functions.h
        main.cpp)
