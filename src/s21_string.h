#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdio.h>
#include <string.h> // Только для теста

#define s21_NULL ((void *)0)
#define s21_size_t unsigned long long

char *s21_strpbrk(const char *str1, const char *str2);
int main_s21_strpbrk();

char *s21_strrchr(const char *str, int c);
int main_s21_strrchr();

char *s21_strncpy(char *str_to, const char *str_from, s21_size_t n);
int main_s21_strncpy();

int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
int main_s21_strncmp();

char *s21_strncat(char *str_to, const char *str_from, s21_size_t size);
int main_s21_strncat();

s21_size_t s21_strlen(const char *string);
int main_s21_strlen();

s21_size_t s21_strcspn(const char *str1, const char *str2);
int main_s21_strcspn();

char *s21_strchr(const char *str, unsigned int c);
int main_s21_strchr();

// Функции для работы с памятью
int s21_sprintf(char *str, const char *format, ...);

void *s21_memset(void *str, int value, s21_size_t volume);
int main_s21_memset();

void *s21_memcpy(void *memory_to, const void *memory_from, size_t size);
int main_s21_memcpy();

int s21_memcmp(const void *str1, const void *str2, s21_size_t size);
int main_s21_memcmp();

void *s21_memchr(const void *string, int item, s21_size_t count);
int main_s21_memchr();

char *s21_strerror(int errnum);

void *s21_to_upper(const char *str);
int main_s21_to_upper();

void *to_lower(const char *str);
int main_s21_to_lower();

void *s21_insert(const char *src, const char *str, s21_size_t start_index);
int main_s21_insert();

void *s21_trim(const char *src, const char *trim_chars);
int main_s21_trim();

const char *s21_strstr(const char *haystack, const char *needle);

char *s21_strtok(char *str, const char *delim);
int main_s21_strtok();

#endif // S21_STRING_H