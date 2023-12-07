cmake_minimum_required(VERSION 3.20)

include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)


set(CMAKE_CXX_STANDARD 17)

# lab1
add_executable(lab1_test lab1_test.cpp ../lab1/src/hight.cpp ../lab1/include/hight.hpp)

target_link_libraries(lab1_test PRIVATE GTest::GTest)
target_include_directories(lab1_test PRIVATE ../lab1/include)

add_test(lab1_test lab1_test)

# lab2
add_executable(lab2_test lab2_test.cpp ../lab2/src/Octal.cpp ../lab2/include/Octal.hpp)

target_link_libraries(lab2_test PRIVATE GTest::GTest)
target_include_directories(lab2_test PRIVATE ../lab2/include)

add_test(lab2_test lab2_test)

# lab3
add_executable(lab3_test lab3_test.cpp  ../lab3/src/Array.cpp 
                                        ../lab3/include/Figure.hpp
                                        ../lab3/include/Rectangle.hpp
                                        ../lab3/include/Square.hpp
                                        ../lab3/include/Triangle.hpp
                                        ../lab3/src/Figure.cpp
                                        ../lab3/src/Rectangle.cpp
                                        ../lab3/src/Square.cpp
                                        ../lab3/src/Triangle.cpp)

target_link_libraries(lab3_test PRIVATE GTest::GTest)
target_include_directories(lab3_test PRIVATE ../lab3/include)

add_test(lab3_test lab3_test)

# lab4
add_executable(lab4_test lab4_test.cpp)

target_link_libraries(lab4_test PRIVATE GTest::GTest)
target_include_directories(lab4_test PRIVATE ../lab4/include)

add_test(lab4_test lab4_test)