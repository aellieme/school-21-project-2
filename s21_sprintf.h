#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>


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
    int dot_z;
    int accuracy;
    long int number;
    int spec_d;
    int spec_u;
} flag_struct;

int s21_sprintf(char *str, const char *format, ...);

void specifier_c(char *str, int *i, va_list args, flag_struct flags);
void specifier_d_u(char *str, int *i, va_list args, flag_struct flags);
void specifier_f(char *str, int *i, va_list args, flag_struct flags);
void specifier_s(char *str, int *i, va_list args, flag_struct flags);
void specifier_per(char *str, const char *format, int *i, int *j); // переделать
void do_widht(int clear_widht, char *str, flag_struct flags, int* i);

void parser_sign(char const* format, flag_struct* flags, int* j);
void parser_length(char const* format, flag_struct* flags, int* j);
void metamorph_length(va_list args, flag_struct* flags);
void metamorph_unsight_length(va_list args, flag_struct* flags);
int parser_wight(const char* format, int* j, va_list args);
void parser_accuracy(const char* format, int* j, va_list args, flag_struct* flags);
void parser_specifier(const char* format, char* str, int* j, int* i, va_list args, flag_struct flags);
float round_number(float number);

#endif //S21_SPRINTF_H