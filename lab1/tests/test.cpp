#include <iostream>
#include <gtest/gtest.h>

#include "hight.hpp"

TEST(TestGroupName, Test_1) {
    ASSERT_EQ(hight(100, 10, 910), 0);
}