#include "s21_sprintf.h"

int main() {
    char buffer[1028] = {0};
    s21_sprintf(buffer, "Hello %hd", 1951);
    printf("%s\n", buffer);
    sprintf(buffer, "Hello %hd", 1951);
    printf("%s\n", buffer);

    return 0;
}

int s21_sprintf(char *str, const char *format, ...) {
    va_list args;
    va_start(args, format);
    int j = 0, i = 0; // возможно можно убрать

    while (format[j] != '\0') {
        if (format[j] != '%') {
            str[i++] = format[j++];
        } else {
            j++;
            flag_struct flags = {0};
            parser_sign(format, &flags, &j);
            parser_flags(format, &flags, &j);
            // parser_accuracy(format, );
            if (format[j] == '.') accuracy(str, format, &i, &j, args);
            else if (format[j] == 'c') specifier_c(str, &i, args);
            else if (format[j] == 'd') specifier_d(str, &i, args, flags);
            else if (format[j] == 'u') specifier_u(str, &i, args, flags);
//            else if (format[j] == 'f') specifier_f(str, &i, args);
            else if (format[j] == 's') specifier_s(str, &i, args);
            // else if (format[j] =='l') specifier_l(str, format, &i, &j, args);
            else if (format[j] == '%') specifier_per(str, format, &i, &j);
            j++;
        }
    }

    va_end(args);

    return i;
}

void parser_flags(const char* format, flag_struct* flags, int* j) {
    while (format[*j] == 'l' || format[*j] == 'h' || format[*j] == 'L') {
        if (format[*j] == 'l') {
            flags->flag_l = 1;
        } else if (format[*j] == 'h') {
            flags->flag_h = 1;
        } else if (format[*j] == 'L') {
            flags->flag_big_l = 1;
        }
        (*j)++;
    }
}

void parser_sign(const char* format, flag_struct* flags, int* j) {
    while (format[*j] == '-' || format[*j] == '+' || format[*j] == ' ' || format[*j] == '0' || format[*j] == '#') {
        if (format[*j] == '-') {
            flags->minus = 1;
        } else if (format[*j] == '+') {
            flags->plus = 1;
        } else if (format[*j] == ' ') {
            flags->space = 1;
        } else if (format[*j] == '0') {
            flags->zero = 1;
        } else if (format[*j] == '#') {
            flags->hash = 1;
        }
        (*j)++;
    }
}

void accuracy(char *str, const char* format, int *i, int *j, va_list args) {
   char number[100] = {0};
   int k = 0;
   int count = 0;
    if (format[*j+1] == '*') {
        int ac = va_arg(args, int);
        if (format[*j+2] == 'd') {
        long int d = va_arg(args, int);

        while( d > 0) {
            number[k++] = (d % 10) + '0';
            d /= 10;
            count++;
        }
        while (count < ac) {
            number[k++] = (d % 10) + '0';
            count++;
        }
        for (int z = k - 1; z >= 0; z--) {
         str[(*i)++]  = number[z]; 
               }
            }
    }
    (*j) = (*j) + 2;
}



void specifier_c(char *str, int *i, va_list args) {
    char ch = (char)va_arg(args, int);
    str[(*i)++] = ch;
}

void specifier_d(char *str, int *i, va_list args, flag_struct flags) {
    long int d = 0;
    if (flags.flag_l) {
        d = va_arg(args, long int);
    } else if(flags.flag_h) {
        d = (short)va_arg(args, int);
    } else {
        d = va_arg(args, int);
    }

    char number[100] = {0};
    int k = 0;
    if (d < 0) {
        str[(*i)++] = '-';
        d = -(d);
    }

    if (d == 0) {
        str[(*i)++] = '0';
    } else {
        while (d > 0) {
            number[k++] = (d % 10) + '0';
            d /= 10;
        }
    }

    for (int z = k - 1; z >= 0; z--) {
        str[(*i)++] = number[z];
    }
}


// void specifier_f(char *str, int *i, va_list args) {
//     double l = va_arg(args, double);
//     double f = (round)(l * 1000000);
//     f = f / 1000000;
//     char number[100] = {0};
//     int k = 0, count = 0;
//     int d = (int)f;

//     if (f < 0) {
//         str[(*i)++] = '-';
//         f = -f;
//         d = -d;
//     }

//     if ((f >= 0 && f < 1)) {
//         str[(*i)++] = '0';
//     }

//     if (f == '.') {
//         number[k++] = '.';
//     } else {
//         while (d > 0) {
//             number[k] = (d % 10) + '0';
//             k++;
//             d = d / 10;
//         }
//         // (*j)++;
//         for (int z = k - 1; z >= 0; z--) {
//             str[(*i)++] = number[z];
//         }
//         str[(*i)++] = '.';
//         double h = f - (long long)f;

//         while (count < 6) {
//             h = h * 10;
//             str[(*i)++] = (int)(long long)h % 10 + '0';
//             count++;
//         }
//     }
// }

void specifier_s(char *str, int *i, va_list args) {
    char *s = va_arg(args, char *);

    for (int k = 0; s[k] != '\0'; k++) {
        str[(*i)++] = s[k];
    }
}

void specifier_u(char *str, int *i, va_list args, flag_struct flags) {
    unsigned long int u = 0;
    if (flags.flag_l) {
        u = va_arg(args, unsigned int);
    } else if (flags.flag_h) {
        u = (short unsigned int)va_arg(args, unsigned int);
    }

    char number[100] = {0};
    int k = 0;
    if (u == 0) {
        str[(*i)++] = '0';
    }
    while (u > 0) {
        number[k] = (u % 10) + '0';
        k++;
        u = u / 10;
    }
    for (int z = k - 1; z >= 0; z--) {
        str[(*i)++] = number[z];
    }
}

void specifier_per(char *str, const char *format, int *i, int *j) {
    int count_per = 1;

    while (format[*j] == '%' && format[*j + 1] == '%') {
        count_per++;
        (*j)++;  // т.к. в цикле
    }

    if ((format[*j] == '%' && format[*j + 1] != '%')) {
        count_per++;
        //        (*j)++;
    }

    if (count_per % 2 == 0) {
        for (int k = 1; k <= count_per / 2; k++) {
            str[(*i)++] = '%';
        }
    }
    // Прописать иначе - NULL и остановка программы
}
