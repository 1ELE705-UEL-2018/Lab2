#include <string.h>
#include "gtest/gtest.h"

extern "C"
{
	int strcmp2(const char* str1, const char* str2);
}

TEST(strcmp2, StringsVazias)
{
	ASSERT_EQ(0, strcmp2("", ""));
}

TEST(strcmp2, StringsUmCaractereIguais)
{
	ASSERT_EQ(0, strcmp2("a", "a"));
}

TEST(strcmp2, StringsUmCaractereString1Maior)
{
	ASSERT_GT(strcmp2("b", "a"), 0);
}

TEST(strcmp2, StringsUmCaractereString1Menor)
{
	ASSERT_LT(strcmp2("a", "b"), 0);
}

TEST(strcmp2, StringsDoisCaracteresIguais)
{
	ASSERT_EQ(0, strcmp2("aa", "aa"));
}

TEST(strcmp2, StringsDoisCaracteresPrimeiroCaractereString1Maior)
{
	ASSERT_GT(strcmp2("ba", "aa"), 0);
}

TEST(strcmp2, StringsDoisCaracteresPrimeiroCaractereString1Menor)
{
	ASSERT_LT(strcmp2("aa", "ba"), 0);
}

TEST(strcmp2, StringsDoisCaracteresSegundoCaractereString1Maior)
{
	ASSERT_GT(strcmp2("ab", "aa"), 0);
}

TEST(strcmp2, StringsDoisCaracteresSegundoCaractereString1Menor)
{
	ASSERT_LT(strcmp2("aa", "ab"), 0);
}

TEST(strcmp2, StringsDezCaracteresIguais)
{
	ASSERT_EQ(0, strcmp2("abcdefghij", "abcdefghij"));
}

TEST(strcmp2, StringsDezCaracteresUltimoCaractereString1Maior)
{
	ASSERT_GT(strcmp2("abcdefghik", "abcdefghij"), 0);
}

TEST(strcmp2, StringsDezCaracteresUltimoCaractereString1Menor)
{
	ASSERT_LT(strcmp2("abcdefghia", "abcdefghij"), 0);
}