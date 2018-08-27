#include <stddef.h>
#include "gtest/gtest.h"

void test_strcpy_apenas_retorno(char* dst, const char* src, char* (*my_strcpy)(char*, const char*))
{
	ASSERT_EQ(dst, my_strcpy(dst, src));
}

void test_strcpy_completo(char* dst, const char* src, char* (*my_strcpy)(char*, const char*))
{
	test_strcpy_apenas_retorno(dst, src, my_strcpy);

	ASSERT_STREQ(src, dst);
}

void test_strcat(const char* expected, char* str1, const char *str2, char* (*my_strcat)(char*, const char*))
{
	ASSERT_EQ(str1, my_strcat(str1, str2));

	ASSERT_STREQ(expected, str1);
}

void test_strncat(const char* expected, char* str1, const char *str2, size_t num, char* (*my_strncat)(char*, const char*, size_t))
{
	ASSERT_EQ(str1, my_strncat(str1, str2, num));

	ASSERT_STREQ(expected, str1);
}

void test_memcmp(const void* ptr1, const void* ptr2, size_t num, int(*my_memcmp)(const void*, const void*, size_t))
{
	int memcmpResult = memcmp(ptr1, ptr2, num);
	int myMemcmpResult = my_memcmp(ptr1, ptr2, num);

	ASSERT_TRUE((memcmpResult == 0 && myMemcmpResult == 0) || (memcmpResult > 0 && myMemcmpResult > 0) || (memcmpResult < 0 && myMemcmpResult < 0));
}

void test_memcpy_apenas_retorno(void* ptr1, const void* ptr2, size_t num, void*(*my_memcpy)(void*, const void*, size_t))
{
	ASSERT_EQ(ptr1, my_memcpy(ptr1, ptr2, num));
}

void test_memcpy_completo(void* ptr1, const void* ptr2, size_t num, void*(*my_memcpy)(void*, const void*, size_t))
{
	test_memcpy_apenas_retorno(ptr1, ptr2, num, my_memcpy);

	ASSERT_EQ(memcmp(ptr1, ptr2, num), 0);
}

void test_memset_apenas_retorno(void* ptr, char value, size_t num, void*(*my_memset)(void* ptr, char value, size_t num))
{
	ASSERT_EQ(ptr, my_memset(ptr, value, num));
}

void test_memset_completo(void* ptr, char value, size_t num, void*(*my_memset)(void* ptr, char value, size_t num))
{
	size_t i;
	char* p = (char*)ptr;

	test_memset_apenas_retorno(ptr, value, num, my_memset);

	for (i = 0; i < num; i++)
		ASSERT_EQ(value, p[i]);
}
