#include <math.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct {
    int flag_l; // d u
    int flag_h; // d u
    int flag_big_l;
    int minus; 
    int plus; // d f
    int zero;
    int space; // сделан для d и f
    int hash;
    int width;
    long int number;
    
} flag_struct;

int s21_sprintf(char *str, const char *format, ...);
void accuracy(char *str, const char* format, int *i, int *j, va_list args);
void specifier_c(char *str, int *i, va_list args);
void specifier_d(char *str, int *i, va_list args, flag_struct flags);
void specifier_f(char *str, int *i, va_list args, flag_struct flags);
void specifier_s(char *str, int *i, va_list args);
void specifier_u(char *str, int *i, va_list args, flag_struct flags);
void specifier_per(char *str, const char *format, int *i, int *j); // переделать

void parser_sign(char const* format, flag_struct* flags, int* j);
void parser_flags(char const* format, flag_struct* flags, int* j);
void metamorph_length(va_list args, flag_struct* flags);
void parser_wight(const char* format, flag_struct* flags, int* j);
void parser_specifier();