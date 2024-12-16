#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>

int s21_sprintf(char *str, const char *format, ...);
void specifier_lh(char *str, const char *format, int *i, int *j, va_list args);
void specifier_ll(char *str, const char *format, int *i, int *j, va_list args);
void specifier_c(char *str, int *i, int *j, va_list args);
void specifier_d(char *str, int *i, int *j, va_list args);
void specifier_f(char *str, int *i, int *j, va_list args);
void specifier_s(char *str, int *i, int *j, va_list args);
void specifier_u(char *str, int *i, int *j, va_list args);
void specifier_per(char *str, const char *format, int *i, int *j);