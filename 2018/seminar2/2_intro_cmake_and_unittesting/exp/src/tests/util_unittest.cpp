#include "gtest/gtest.h"

#include "explib/util.h"

#include <sstream>

TEST(calc_exp, the_first_num)
{
	EXPECT_EQ(2.0, calc_exp(1));
}

TEST(calc_exp, high_order_value)
{
	EXPECT_EQ(2.7181, calc_exp(50));	
}

TEST(read_n, correct_value)
{
	std::stringstream ss("33");

	const unsigned n = read_n(ss); 

	EXPECT_EQ(33, n);
}

TEST(read_n, incorrect_value)
{
	std::stringstream ss("trololo");

	const unsigned n = read_n(ss);

	// ... ?
	// bad function design or contracts ?
}

