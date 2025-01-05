
#include "s21_sprintf.h"
#include <stdio.h>

int main() {
    char buffer[1028] = {0};
    int kolvo = s21_sprintf(buffer, "%-10.10ld %-8.15d %-5.1hd %.10s", -12345, -12345, -12345, "hello");
    printf("%s\n", buffer);
    int kolvo1 = sprintf(buffer, "%-10.10ld %-8.15d %-5.1hd %.10s", -12345, -12345, -12345, "hello");

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
            parser_wight(format, &flags, &j, args);
            if (format[j] == '.') parser_accuracy(format, &j, args, &flags); // Alena
            parser_length(format, &flags, &j);
            parser_specifier(format, str, &j, &i, args, flags);
            j++;
        }
    }
    str[i] = '\0';
    va_end(args);

    return i;
}


void do_widht(int clear_widht, char *str, flag_struct flags, int* i) {
  for (int k = 0; k < clear_widht; k++) {
    if (flags.zero) {
      str[(*i)++] = '0';
    } else {
      str[(*i)++] = ' ';
    }
  }

    if (flags.plus || flags.space) {
        (*i)--;
    }
}

void parser_specifier(const char* format, char* str, int* j, int* i, va_list args, flag_struct flags) {
    switch (format[*j]) {
        case 'c': specifier_c(str, i, args, flags); break;
        case 'd': flags.spec_d = 1; specifier_d_u(str, i, args, flags); break;
        case 'u': flags.spec_u = 1; specifier_d_u(str, i, args, flags); break;
        case 'f': specifier_f(str, i, args, flags); break;
        case 's': specifier_s(str, i, args, flags); break;
        case '%': specifier_per(str, format, i, j); break;
        default: break; // Добавить обработку неисвестных спецификаторов
    }
}

void parser_length(const char* format, flag_struct* flags, int* j) {
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

void parser_sign(const char* format, flag_struct* flags, int* j) {  // добавить взаимоисключающие флаги
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

void parser_wight(const char* format, flag_struct* flags, int* j, va_list args) {
    int result = 0;
    while(format[*j] >= '0' && format[*j] <= '9') {
        result = result * 10 + (format[*j] - '0');
        (*j)++;
    }

    if (format[*j] == '*') {
        result = va_arg(args, int);
        (*j)++;
    }
    flags->width = result;
} // flags.wig = int parser

void parser_accuracy(const char* format, int* j, va_list args, flag_struct* flags) {
    int result_ac = 0;
    while(format[(*j)+1] >= '0' && format[(*j)+1] <= '9') {
        result_ac = result_ac * 10 + (format[(*j)+1] - '0');
        (*j)++;
    }
    if (format[(*j)+1] == '*') {
        result_ac = va_arg(args, int);
        (*j)++;
    }
    (*j)++;
    flags->accuracy = result_ac;
}

void specifier_c(char *str, int *i, va_list args, flag_struct flags) {
    char ch = (char)va_arg(args, int);
    int x = flags.width - 1;

    if (!flags.minus) {
        do_widht(x, str, flags, i);
    }
    str[(*i)++] = ch;
    if (flags.minus) {
        do_widht(x, str, flags, i);
    }

}

void specifier_f(char *str, int *i, va_list args, flag_struct flags) { // округление шалит(грустно)
    double l = va_arg(args, double);
    
    int z = 0;
    int ac = 6;
    double f = (round)(l * 1000000);
    f = f / 1000000;
    char number[100] = {0};
    int k = 0, count = 0;
    int d = (int)f;
    int f_copy = (round)(f * 1000000);
    for (; f_copy > 0; z++) {
        f_copy /= 10;
    }
    int x = flags.width - z - 1;
    if (!flags.minus) {
        do_widht(x, str, flags, i);
    }

    if (f < 0) {
        str[(*i)++] = '-';
        f = -f;
        d = -d;
    } else if (flags.plus) { // plus
        str[(*i)++] = '+';
    } else if (flags.space) { // space
        str[(*i)++] = ' ';
    }

    if ((f >= 0 && f < 1)) {
        str[(*i)++] = '0';
        count++;
    }

    if (f == '.') {
        number[k++] = '.';
    } else {
        while (d > 0) {
            number[k] = (d % 10) + '0';
            k++;
            d = d / 10;
        }
        count++;
        // (*j)++;
        for (int z = k - 1; z >= 0; z--) {
            str[(*i)++] = number[z];
        }
        str[(*i)++] = '.';
        double h = (round)((f - (long long)f)*1000000)/1000000; // точность - используем число которое ввели
        if (flags.accuracy) {
            ac = flags.accuracy;
        }
        while (count <= ac) {
            h = h * 10;
            str[(*i)++] = (int)(long long)h % 10 + '0';
            count++;
        }
    }
    if (flags.minus) {
        do_widht(x, str, flags, i);
    }
}

void specifier_s(char *str, int *i, va_list args, flag_struct flags) {
    char *s = va_arg(args, char *);
    int x = flags.width - strlen(s);
    int count = 0;
    if (!flags.minus) {
        do_widht(x, str, flags, i);
    }
    
    for (int k = 0; s[k] != '\0'; k++) {
        if (flags.accuracy) {
        if (flags.accuracy > count) {
        str[(*i)++] = s[k];
        count++;
        }
        }else {
        str[(*i)++] = s[k];
        }
    }

    if (flags.minus) {
        do_widht(x, str, flags, i);
    }

}

void metamorph_length(va_list args, flag_struct* flags) {
    if (flags->flag_l) {
        flags->number = va_arg(args, long int);
    } else if (flags->flag_h) {
        flags->number = (short)va_arg(args, int);
    } else flags->number = va_arg(args, int);
}

void metamorph_unsight_length(va_list args, flag_struct* flags) {
    if (flags->flag_l) {
        flags->number = (unsigned long)va_arg(args, long long);
    } else if (flags->flag_h) {
        flags->number = (short unsigned)va_arg(args, unsigned); // учесть слишком большие числа
    } else flags->number = (unsigned)va_arg(args, unsigned);
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

void specifier_d_u(char *str, int *i, va_list args, flag_struct flags) {
    if (flags.spec_d) {
        metamorph_length(args, &flags);
    } else if (flags.spec_u) {
        metamorph_unsight_length(args, &flags);
    }

    int negativ = 0;
    int count = 0;
    int x = 0;
    char ch;
    char sub_buffer[1048] = {0};

    if (flags.number < 0 && flags.spec_d) {
        negativ = 1;
        flags.number *= -1;
    }

    for (; flags.number > 0 || flags.accuracy > count; count++) {
        sub_buffer[count] = flags.number % 10 + '0';
        flags.number /= 10;
    }

    if (negativ) {
        sub_buffer[count++] = '-';
    } else if (flags.plus) {
        sub_buffer[count++] = '+';
    } else if (flags.space) {
        sub_buffer[count++] = ' ';
    }

    sub_buffer[count] = '\0';

    count--;

    for (; x <= count ;) {
        ch = sub_buffer[x];
        sub_buffer[x++] = sub_buffer[count];
        sub_buffer[count--] = ch;
    }

    // for (int y = 0; y < strlen(sub_buffer); y++) { // specifier_s
    //     str[(*i)++] = sub_buffer[y];
    // }

    ////
    char* s = sub_buffer;
    int blabla = flags.width - strlen(s);
    int count2 = 0;
    if (!flags.minus) {
        do_widht(blabla, str, flags, i);
    }
    
    for (int k = 0; s[k] != '\0'; k++) {
        str[(*i)++] = s[k];
    }

    if (flags.minus) {
        do_widht(blabla, str, flags, i);
    }
    ////

//    strcat(str, sub_buffer);
}

// void specifier_d(char *str, int *i, va_list args, flag_struct flags) {
//     metamorph_length(args, &flags);
//     long int d = flags.number;
//     long int d_copy = d;
//     int count = 0;
//     int z = 0;
//     for (; d_copy > 0; z++) {
//         d_copy /= 10;
//     }

//     int x = flags.width - z;

//     if (flags.width - z > 0) {
//         if (z > flags.accuracy) {
//             x = x + flags.accuracy - z;
//         }
//         x = x - flags.accuracy + z;
//     }

//     // if (!flags.minus) {
//     //     do_widht(x, str, flags, i);
//     // }

//     char number[100] = {0};
//     int k = 0;
//     if (d < 0) {
//         str[(*i)++] = '-';
//         d = -(d);
//     } else if (flags.plus) {
//         str[(*i)++] = '+';
//     } else if (flags.space) {
//         str[(*i)++] = ' ';
//     }

//     if (d == 0) {
//         str[(*i)++] = '0';
//     } else {
//         while (d > 0) {
//             number[k++] = (d % 10) + '0';
//             d /= 10;
//             count++;
//         }
//          if (flags.accuracy) {
//              while (count < flags.accuracy) {
//              number[k++] = '0';
//              count++;
//          }
//          }
//     }

//     for (int z = k - 1; z >= 0; z--) {
//         str[(*i)++] = number[z];
//     } // дубл
//     // if (flags.minus) {
//     //     do_widht(x, str, flags, i);
//     // }
// }