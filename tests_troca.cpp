#include "gtest/gtest.h"

extern "C"
{
	void troca(int a, int b);
}

TEST(troca, Troca12)
{
	int a = 1, b = 2;

	troca(a, b);

	EXPECT_EQ(2, a);
	EXPECT_EQ(1, b);
}