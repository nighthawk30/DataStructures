cmake_minimum_required(VERSION 3.17)
project(linked_template)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(linked_template main.cpp linked_list.h)