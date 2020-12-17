cmake_minimum_required(VERSION 3.17)
project(Lab12)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab12
        tests.cpp
        unix_clock.cpp
        unix_clock.h analog_clock.h)
