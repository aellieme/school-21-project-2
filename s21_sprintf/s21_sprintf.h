#include <stdarg.h>
#include <stdio.h>

int s21_sprintf(char *str, const char *format, ...);
void specifier_c(char *str, int *i, int *j, va_list args);
void specifier_d(char *str, int *i, int *j, va_list args);
// void specifier_f(char *str, int *i, int *j, va_list args);
void specifier_s(char *str, int *i, int *j, va_list args);
// void specifier_u(char *str, int *i, int *j, va_list args);
void specifier_per(char *str, const char *format, int *i, int *j);