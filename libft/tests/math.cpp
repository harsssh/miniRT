#include <gtest/gtest.h>
#include <cmath>

extern "C" {
#include "libft.h"
}

// expect pow
void expect_pow(double a, int b) {
	EXPECT_DOUBLE_EQ(ft_pow(a, b), pow(a, b));
}

// ft_pow
TEST(MathTest, pow) {
	expect_pow(2, 0);
	expect_pow(2, 1);
	expect_pow(2, 10);
	expect_pow(2, 11);
	expect_pow(2, -1);
	expect_pow(2, -10);
	expect_pow(2, -11);
}