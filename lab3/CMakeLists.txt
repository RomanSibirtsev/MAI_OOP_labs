cmake_minimum_required(VERSION 3.20)

project(lab3)

add_executable(lab3 main.cpp
                    include/Figure.hpp
                    include/Square.hpp 
                    include/Triangle.hpp
                    include/Rectangle.hpp
                    include/Array.hpp
                    src/Figure.cpp 
                    src/Square.cpp
                    src/Triangle.cpp
                    src/Rectangle.cpp
                    src/Array.cpp)

target_include_directories(lab3 PRIVATE include)