// Сравнивает не более первых n байтов str1 и str2

#include <stdio.h>

#define s21_NULL (void *)0
#define s21_size_t unsigned long long

int s21_strncmp(const char *str1, const char *str2, s21_size_t n){
    s21_size_t i = 0;
    s21_size_t who_more = 0;

    while ((*str1 != '\0') && (*str2 != '\0') && (*str1 == *str2) && (i<n)) {
        str1++;
        str2++;
        i++;
        }
        if (i!=n){
            if (*str1 > *str2) who_more = 1; 
            else if (*str1 < *str2) who_more = -1;
            i++;
            }
        return (i==n) ? 0 : who_more;
}