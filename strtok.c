//Разбивает строку str на ряд токенов, разделенных delim.

#include <stdio.h>
#define s21_NULL (void *)0
#define s21_size_t unsigned long long

s21_size_t s21_strlen(const char *string) {
    s21_size_t i = 0;
    while (string[i] != '\0') {
        i++;
    }
    return i;
}

char *s21_strpbrk(const char *str1, const char *str2) {
    char *result = s21_NULL;
    int found = 0;
    
    while (*str1 != '\0' && !found) {
        const char *ptr = str2;
        while (*ptr != '\0' && !found) {
            if (*str1 == *ptr) {
                result = (char *)str1;
                found = 1;
            }
            ptr++;
        }
        if (!found) {
            str1++;
        }
    }
    
    return result;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t i = 0;
    int found = 0;
    
    while (str1[i] != '\0' && !found) {
        const char *ptr = str2;
        while (*ptr != '\0' && !found) {
            if (str1[i] == *ptr) {
                found = 1;
            }
            ptr++;
        }
        if (!found) {
            i++;
        }
    }
    
    return i;
}

char *s21_strtok(char *str, const char *delim) {
    static char *next_token = s21_NULL;
    char *current_token = s21_NULL;
    
    if (str != s21_NULL) {
        next_token = str;
    }
    
    if (next_token != s21_NULL) {
        str = next_token;
        s21_size_t span = s21_strcspn(str, delim);
        
        if (str[span] == '\0') {
            current_token = (str[0] != '\0') ? str : s21_NULL;
            next_token = s21_NULL;
        } else {
            str[span] = '\0';
            current_token = str;
            next_token = str + span + 1;
            
            while (*next_token != '\0' && s21_strcspn(next_token, delim) == 0) {
                next_token++;
            }
            
            if (*next_token == '\0') {
                next_token = s21_NULL;
            }
        }
    }
    
    return current_token;
}