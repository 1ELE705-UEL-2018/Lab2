#include <string.h>
#include "gtest/gtest.h"

extern "C"
{
	int strcmp3(const char* str1, const char* str2);
}

TEST(strcmp3, StringsVazias)
{
	ASSERT_EQ(0, strcmp3("", ""));
}

TEST(strcmp3, StringsUmCaractereIguais)
{
	ASSERT_EQ(0, strcmp3("a", "a"));
}

TEST(strcmp3, StringsUmCaractereString1Maior)
{
	ASSERT_GT(strcmp3("b", "a"), 0);
}

TEST(strcmp3, StringsUmCaractereString1Menor)
{
	ASSERT_LT(strcmp3("a", "b"), 0);
}

TEST(strcmp3, StringsDoisCaracteresIguais)
{
	ASSERT_EQ(0, strcmp3("aa", "aa"));
}

TEST(strcmp3, StringsDoisCaracteresPrimeiroCaractereString1Maior)
{
	ASSERT_GT(strcmp3("ba", "aa"), 0);
}

TEST(strcmp3, StringsDoisCaracteresPrimeiroCaractereString1Menor)
{
	ASSERT_LT(strcmp3("aa", "ba"), 0);
}

TEST(strcmp3, StringsDoisCaracteresSegundoCaractereString1Maior)
{
	ASSERT_GT(strcmp3("ab", "aa"), 0);
}

TEST(strcmp3, StringsDoisCaracteresSegundoCaractereString1Menor)
{
	ASSERT_LT(strcmp3("aa", "ab"), 0);
}

TEST(strcmp3, StringsDezCaracteresIguais)
{
	ASSERT_EQ(0, strcmp3("abcdefghij", "abcdefghij"));
}

TEST(strcmp3, StringsDezCaracteresUltimoCaractereString1Maior)
{
	ASSERT_GT(strcmp3("abcdefghik", "abcdefghij"), 0);
}

TEST(strcmp3, StringsDezCaracteresUltimoCaractereString1Menor)
{
	ASSERT_LT(strcmp3("abcdefghia", "abcdefghij"), 0);
}