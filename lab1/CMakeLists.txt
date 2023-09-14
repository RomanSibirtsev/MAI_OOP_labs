cmake_minimum_required(VERSION 3.20)

add_executable(lab1 main.cpp src/hight.cpp include/hight.hpp)

target_include_directories(lab1 PRIVATE include)