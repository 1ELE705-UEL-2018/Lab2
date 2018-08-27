#include "gtest/gtest.h"

extern "C"
{
	void troca2(int* pa, int* pb);
}

TEST(troca2, Troca12)
{
	int a = 1, b = 2;

	troca2(&a, &b);

	EXPECT_EQ(2, a);
	EXPECT_EQ(1, b);
}