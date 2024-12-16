#ifndef SPRINTF_H
#define SPRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>


struct specifications{
    int ch;
    int d;
    int u;
    int f;
};

void fun_spec_1(char *buf, char *bufer, int *k, int *a, int **i);
void fun_specif(struct specifications params, char* bufer, va_list args, int *i);
void print_strings(char* bufer, const char* string, ...);



#endif