//Разбивает строку str на ряд токенов, разделенных delim.

#include "s21_string.h"

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