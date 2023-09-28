cmake_minimum_required(VERSION 3.20)

project(lab2)

#enable_testing()

add_executable(lab2 main.cpp src/Octal.cpp include/Octal.hpp)

target_include_directories(lab2 PRIVATE include)

#add_subdirectory(tests)