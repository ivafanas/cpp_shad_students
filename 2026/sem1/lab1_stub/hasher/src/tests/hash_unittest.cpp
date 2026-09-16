#include "gtest/gtest.h"

TEST(function1, scenario1) {
  EXPECT_EQ(1, 1);
  EXPECT_NE(1, 100);
}

TEST(function1, scenario2) {
  EXPECT_EQ(2, 2);
  EXPECT_NE(2, 100);
}

TEST(function1, scenario3) {
  EXPECT_EQ(3, 3);
  EXPECT_NE(3, 100);
}
