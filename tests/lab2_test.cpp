#include <iostream>
#include <gtest/gtest.h>

#include "Octal.hpp"

TEST(TestConstructors, Test_1) {
    Octal a("111");
    Octal b(3, '1');
    ASSERT_EQ(a, b);
}

TEST(TestConstructors, Test_2) {
    Octal a("123");
    Octal b = {'1', '2', '3'};
    ASSERT_EQ(a, b);
}

TEST(TestConstructors, Test_3) {
    Octal a("123");
    Octal b = a;
    ASSERT_EQ(a, b);
}

TEST(TestOperators, Test_1) {
    Octal a("123");
    Octal b("123");
    ASSERT_TRUE(a == b);
}

TEST(TestOperators, Test_2) {
    Octal a("123");
    Octal b("124");
    ASSERT_TRUE(a < b);
}

TEST(TestOperators, Test_3) {
    Octal a("127");
    Octal b("124");
    ASSERT_TRUE(a > b);
}

TEST(TestOperators, Test_4) {
    Octal a("1");
    Octal b("777");
    Octal c("1000");
    ASSERT_TRUE(c == a + b);
}

TEST(TestOperators, Test_5) {
    Octal a("777");
    Octal b("767");
    Octal c("10");
    ASSERT_TRUE(c == a - b);
}

TEST(TestOperators, Test_6) {
    Octal a("777");
    Octal b("770");
    Octal c("7");
    ASSERT_TRUE(c == a - b);
}

TEST(TestOperators, Test_7) {
    Octal a("777");
    Octal b("777");
    Octal c("0");
    ASSERT_TRUE(c == a - b);
}