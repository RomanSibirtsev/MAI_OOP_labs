#include "Rectangle.hpp"
#include "Square.hpp"
#include "Triangle.hpp"
#include "Array.hpp"
#include "Figure.hpp"
#include <gtest/gtest.h>

TEST(TestCenter, Test_1) {
    Square<int> s = {Dot<int>{0, 0}, Dot<int>{0, 2}, Dot<int>{2, 2}, Dot<int>{2, 0}};
    ASSERT_TRUE((s.Center()==Dot<int>{1, 1}));
}

TEST(TestCenter, Test_2) {
    Rectangle<int> s = {Dot<int>{0, 0}, Dot<int>{0, 2}, Dot<int>{4, 2}, Dot<int>{4, 0}};
    ASSERT_TRUE((s.Center()==Dot<int>{2, 1}));
}

TEST(TestCenter, Test_3) {
    Triangle<double> s = {Dot<double>{0, 0}, Dot<double>{0, 2}, Dot<double>{2, 2}};
    ASSERT_TRUE((s.Center()==Dot<double>{0.6666666, 1.3333333}));
}

//---
TEST(TestArea, Test_1) {
    Square<int> s = {Dot<int>{0, 0}, Dot<int>{0, 2}, Dot<int>{2, 2}, Dot<int>{2, 0}};
    ASSERT_EQ((double)s,  4.);
}

TEST(TestArea, Test_2) {
    Rectangle<int> s = {Dot<int>{0, 0}, Dot<int>{0, 2}, Dot<int>{4, 2}, Dot<int>{4, 0}};
    ASSERT_EQ((double)s,  8.);
}

TEST(TestArea, Test_3) {
    Triangle<int> s = {Dot<int>{0, 0}, Dot<int>{0, 2}, Dot<int>{2, 2}};
    ASSERT_EQ((double)s,  2.);
}

//----Array

TEST(TestArray, Test_1) {
    Square<int> s = {Dot<int>{0, 0}, Dot<int>{0, 2}, Dot<int>{2, 2}, Dot<int>{2, 0}}; 
    Rectangle<int> r = {Dot<int>{0, 0}, Dot<int>{0, 2}, Dot<int>{4, 2}, Dot<int>{4, 0}};
    Triangle<int> t = {Dot<int>{0, 0}, Dot<int>{0, 2}, Dot<int>{2, 2}}; 
    Array<std::shared_ptr<Figure<int>>> arr;
    arr.push_back(std::make_shared<Square<int>>(s));
    arr.push_back(std::make_shared<Rectangle<int>>(r));
    arr.push_back(std::make_shared<Triangle<int>>(t));
    ASSERT_EQ(arr.get_total_area(), 14.);
}

TEST(TestArray, Test_2) {
    Square<int> s = {Dot<int>{0, 0}, Dot<int>{0, 2}, Dot<int>{2, 2}, Dot<int>{2, 0}}; 
    Rectangle<int> r = {Dot<int>{0, 0}, Dot<int>{0, 2}, Dot<int>{4, 2}, Dot<int>{4, 0}};
    Triangle<int> t = {Dot<int>{0, 0}, Dot<int>{0, 2}, Dot<int>{2, 2}}; 

    Array<std::shared_ptr<Figure<int>>> arr1, arr2;
    arr1.push_back(std::make_shared<Square<int>>(s));
    arr1.push_back(std::make_shared<Rectangle<int>>(r));
    arr1.push_back(std::make_shared<Triangle<int>>(t));
    arr1.remove(1);
    arr2.push_back(std::make_shared<Square<int>>(s));
    arr2.push_back(std::make_shared<Triangle<int>>(t));
    
    ASSERT_EQ(arr2.get_size(), 2);
    for (int i = 0; i < arr2.get_size(); ++ i) {
        ASSERT_TRUE(*arr1[i] == *arr2[i]);
    }
}


