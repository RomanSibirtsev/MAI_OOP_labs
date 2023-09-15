#include <iostream>
#include <gtest/gtest.h>

#include "hight.hpp"

TEST(General, Test_1) {
    ASSERT_EQ(hight(100, 10, 910), "растение достигнет заданного уровня в 10 день");
}

TEST(General, Test_2) {
    ASSERT_EQ(hight(20, 10, 100), "растение достигнет заданного уровня в 9 день");
}

TEST(General, Test_3) {
    ASSERT_EQ(hight(20, 10, 110), "растение достигнет заданного уровня в 10 день");
}

TEST(General, Test_4) {
    ASSERT_EQ(hight(30, 15, 15), "растение достигнет заданного уровня в 1 ночь");
}

TEST(General, Test_5) {
    ASSERT_EQ(hight(40, 39, 2), "растение достигнет заданного уровня в 2 ночь");
}

TEST(NotValid, Test_1) {
    ASSERT_EQ(hight(30, 20, 65), "растение никогда не достигнет заданного уровня!!!");
}

TEST(NotValid, Test_2) {
    ASSERT_EQ(hight(30, 5, 135), "растение никогда не достигнет заданного уровня!!!");
}

TEST(NotValid, Test_3) {
    ASSERT_EQ(hight(30, 5, 210), "растение никогда не достигнет заданного уровня!!!");
}

TEST(LezzZero, Test_1) {
    ASSERT_EQ(hight(20, 30, 80), "растение никогда не достигнет заданного уровня!!!");
}

TEST(LezzZero, Test_2) {
    ASSERT_EQ(hight(50, 100, 30), "растение никогда не достигнет заданного уровня!!!");
}