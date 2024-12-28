#include <math.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct {
    int flag_l;
    int flag_h;
    int flag_big_l;
    int minus;
    int plus;
    int zero;
    int space;
    int hash;
} flag_struct;

int s21_sprintf(char *str, const char *format, ...);
void accuracy(char *str, const char* format, int *i, int *j, va_list args);
void specifier_c(char *str, int *i, va_list args);
void specifier_d(char *str, int *i, va_list args, flag_struct flags);
 void specifier_f(char *str, int *i, va_list args);
void specifier_s(char *str, int *i, va_list args);
void specifier_u(char *str, int *i, va_list args, flag_struct flags);
void specifier_per(char *str, const char *format, int *i, int *j);
void specifier_l(char *str, const char* format, int *i, int* j, va_list args);
void specifier_h(char *str, const char* format, int *i, int* j, va_list args);

void parser_sign(char const* format, flag_struct* flags, int* j);
void parser_flags(char const* format, flag_struct* flags, int* j);