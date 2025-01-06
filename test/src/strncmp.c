// Сравнивает не более первых n байтов str1 и str2

#include <stdio.h>

#define s21_NULL (void *)0
#define s21_size_t unsigned long long

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    s21_size_t i = 0;
    int result = 0;
    
    while (i < n && *str1 && *str2 && (*str1 == *str2)) {
        str1++;
        str2++;
        i++;
    }
    
    if (i < n) {
        result = (unsigned char)*str1 - (unsigned char)*str2;
    }
    
    return result;
}