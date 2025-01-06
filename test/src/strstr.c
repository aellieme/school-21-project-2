//Находит первое вхождение всей строки needle (не включая завершающий нулевой символ)
//которая появляется в строке haystack.

#include <stdio.h>
#define s21_NULL (void *)0

// Реализация функции strstr с использованием указателей
char *s21_strstr(const char *haystack, const char *needle) {
    char *result = s21_NULL;
    int found = 0;
    
    if (*needle == '\0') {
        result = (char *)haystack;
        found = 1;
    }
    
    const char *h = haystack;
    
    while (*h != '\0' && !found) {
        const char *n = needle;
        const char *current = h;
        int match = 1;
        
        while (*n != '\0' && match) {
            if (*current != *n) {
                match = 0;
            }
            current++;
            n++;
        }
        
        if (match && *n == '\0') {
            result = (char *)h;
            found = 1;
        }
        
        h++;
    }
    
    return result;
}