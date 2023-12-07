cmake_minimum_required(VERSION 3.20)

project(lab4 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-std=c++20)

add_executable(lab4 main.cpp)

target_include_directories(lab4 PRIVATE include)