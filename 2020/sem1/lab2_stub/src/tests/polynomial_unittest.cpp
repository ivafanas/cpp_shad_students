#include "polynomiallib/polynomial.h"

#include "gtest/gtest.h"


// TODO: implement unit tests for polynomial here

TEST(Factorial, zero)
{
    const int factorial_of_zero = Factorial<0>::value;
    EXPECT_EQ(1, factorial_of_zero);
}

