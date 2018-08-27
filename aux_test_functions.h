#ifndef AUX_TEST_FUNCTIONS_H
#define AUX_TEST_FUNCTIONS_H

#include <stddef.h>

void test_strcpy_apenas_retorno(char* dst, const char* src, char* (*myStrcpy)(char*, const char*));
void test_strcpy_completo(char* dst, const char* src, char* (*myStrcpy)(char*, const char*));
void test_strcat(const char* expected, char* str1, const char *str2, char* (*myStrcat)(char*, const char*));
void test_strncat(const char* expected, char* str1, const char *str2, size_t num, char* (*myStrncat)(char*, const char*, size_t));
void test_memcmp(const void* ptr1, const void* ptr2, size_t num, int(*myMemcmp)(const void*, const void*, size_t));
void test_memcpy_apenas_retorno(void* ptr1, const void* ptr2, size_t num, void*(*myMemcpy)(void*, const void*, size_t));
void test_memcpy_completo(void* ptr1, const void* ptr2, size_t num, void*(*myMemcpy)(void*, const void*, size_t));
void test_memset_apenas_retorno(void* ptr, char value, size_t num, void*(*myMemset)(void* ptr, char value, size_t num));
void test_memset_completo(void* ptr, char value, size_t num, void*(*myMemset)(void* ptr, char value, size_t num));

#endif // AUX_TEST_FUNCTIONS_H