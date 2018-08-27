#include <string.h>
#include "gtest/gtest.h"
#include "aux_test_functions.h"

extern "C"
{
	char* strcat3(char* dst, const char* src);
}

TEST(strcat3, StringVaziaComStringVazia)
{
	const char expected[] = "";
	char str1[sizeof(expected)] = "";
	const char str2[] = "";

	test_strcat(expected, str1, str2, strcat3);
}

TEST(strcat3, StringUmCaractereComStringVazia)
{
	const char expected[] = "a";
	char str1[sizeof(expected)] = "a";
	const char str2[] = "";

	test_strcat(expected, str1, str2, strcat3);
}

TEST(strcat3, StringVaziaComStringUmCaractere)
{
	const char expected[] = "a";
	char str1[sizeof(expected)] = "";
	const char str2[] = "a";

	test_strcat(expected, str1, str2, strcat3);
}

TEST(strcat3, StringUmCaractereComStringUmCaractere)
{
	const char expected[] = "aa";
	char str1[sizeof(expected)] = "a";
	const char str2[] = "a";

	test_strcat(expected, str1, str2, strcat3);
}

TEST(strcat3, StringUmCaractereComStringUmCaractereNaoUltrapassaFimDaString)
{
	const char expected[] = "aa";
	char str1[] = { 'a', '\0', 0x13, 0x37 };
	const char str2[] = { 'a', '\0', 'b' };

	test_strcat(expected, str1, str2, strcat3);
	ASSERT_EQ(0x37, str1[3]);
}

TEST(strcat3, StringCincoCaracteresComStringVazia)
{
	const char expected[] = "abcde";
	char str1[sizeof(expected)] = "abcde";
	const char str2[] = "";

	test_strcat(expected, str1, str2, strcat3);
}

TEST(strcat3, StringVaziaComStringCincoCaracteres)
{
	const char expected[] = "abcde";
	char str1[sizeof(expected)] = "";
	const char str2[] = "abcde";

	test_strcat(expected, str1, str2, strcat3);
}

TEST(strcat3, StringCincoCaracteresComStringQuatroCaracteres)
{
	const char expected[] = "abcdefghi";
	char str1[sizeof(expected)] = "abcde";
	const char str2[] = "fghi";

	test_strcat(expected, str1, str2, strcat3);
}
