#include "Rectangle.hpp"
#include "Square.hpp"
#include "Triangle.hpp"
#include "Array.hpp"
#include "Figure.hpp"
#include <gtest/gtest.h>

TEST(TestCenter, Test_1) {
    Square s = {Dot{0, 0}, Dot{0, 2}, Dot{2, 2}, Dot{2, 0}};
    ASSERT_TRUE((s.Center()==Dot{1, 1}));
}

TEST(TestCenter, Test_2) {
    Rectangle s = {Dot{0, 0}, Dot{0, 2}, Dot{4, 2}, Dot{4, 0}};
    ASSERT_TRUE((s.Center()==Dot{2, 1}));
}

TEST(TestCenter, Test_3) {
    Triangle s = {Dot{0, 0}, Dot{0, 2}, Dot{2, 2}};
    ASSERT_TRUE((s.Center()==Dot{0.6666666, 1.3333333}));
}

//---
TEST(TestArea, Test_1) {
    Square s = {Dot{0, 0}, Dot{0, 2}, Dot{2, 2}, Dot{2, 0}};
    ASSERT_EQ((double)s,  4.);
}

TEST(TestArea, Test_2) {
    Rectangle s = {Dot{0, 0}, Dot{0, 2}, Dot{4, 2}, Dot{4, 0}};
    ASSERT_EQ((double)s,  8.);
}

TEST(TestArea, Test_3) {
    Triangle s = {Dot{0, 0}, Dot{0, 2}, Dot{2, 2}};
    ASSERT_EQ((double)s,  2.);
}

//----Array

TEST(TestArray, Test_1) {
    Square s = {Dot{0, 0}, Dot{0, 2}, Dot{2, 2}, Dot{2, 0}}; 
    Rectangle r = {Dot{0, 0}, Dot{0, 2}, Dot{4, 2}, Dot{4, 0}};
    Triangle t = {Dot{0, 0}, Dot{0, 2}, Dot{2, 2}}; 
    Array arr = {&s, &r, &t};
    ASSERT_EQ(arr.get_total_area(), 14.);
}

TEST(TestArray, Test_2) {
    Square s = {Dot{0, 0}, Dot{0, 2}, Dot{2, 2}, Dot{2, 0}}; 
    Rectangle r = {Dot{0, 0}, Dot{0, 2}, Dot{4, 2}, Dot{4, 0}};
    Triangle t = {Dot{0, 0}, Dot{0, 2}, Dot{2, 2}}; 
    Array arr1 = {&s, &r, &t};
    Array arr2 = {&s, &t};
    arr1.remove(1);
    ASSERT_EQ(arr2.get_size(), 2);
    for (int i = 0; i < arr2.get_size(); ++ i) {
        ASSERT_EQ(arr1[i], arr2[i]);
    }
}


