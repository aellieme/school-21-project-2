#include "s21_sprintf.h"
#include <string.h>

int main() {
    char buffer[1028] = {0};
    s21_sprintf(buffer, "Hello %*d|", 5, 2);
    printf("%s\n", buffer);
    sprintf(buffer, "Hello %*d|", 5, 2);
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
            parser_length(format, &flags, &j);
            parser_wight(format, &flags, &j, args);
            if (format[j] == '.') accuracy(str, format, &i, &j, args); // Alena
            parser_specifier(format, str, &j, &i, args, flags);
            j++;
        }
    }

    va_end(args);

    return i;
}


void do_widht(int dlina_slova, char *str, flag_struct flags, int* i) {

    int clear_widht = flags.width - dlina_slova;

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
        case 'd': specifier_d(str, i, args, flags); break;
        case 'u': specifier_u(str, i, args, flags); break;
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
}

void accuracy(char *str, const char* format, int *i, int *j, va_list args) { // переписать через (*j)++ вместо (*j) + 2
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

void specifier_d(char *str, int *i, va_list args, flag_struct flags) {

    metamorph_length(args, &flags);

    long int d = flags.number;
    long int d_copy = d;
    int z = 0;
    for (z; d_copy > 0; z++) {
        d_copy /= 10;
    }

 ////////
    if (!flags.minus) {
        do_widht(z, str, flags, i);
    }

    body_d(d, str, i, flags);

    if (flags.minus) {
        do_widht(z, str, flags, i);
    }
    /////////
}


void specifier_f(char *str, int *i, va_list args, flag_struct flags) { // округление шалит
    double l = va_arg(args, double);

    int z = 0;

    double f = (round)(l * 1000000);
    f = f / 1000000;
    char number[100] = {0};
    int k = 0, count = 0;
    int d = (int)f;

    int f_copy = (round)(f * 1000000);

    for (z; f_copy > 0; z++) {
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
    }

    if (f == '.') {
        number[k++] = '.';
    } else {
        while (d > 0) {
            number[k] = (d % 10) + '0';
            k++;
            d = d / 10;
        }
        // (*j)++;
        for (int z = k - 1; z >= 0; z--) {
            str[(*i)++] = number[z];
        }
        str[(*i)++] = '.';
        double h = (round)((f - (long long)f)*1000000)/1000000; // точность - используем число которое ввели

        while (count < 6) {
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

    int x = strlen(s);

    if (!flags.minus) {
        do_widht(x, str, flags, i);
    }
    
    for (int k = 0; s[k] != '\0'; k++) {
        str[(*i)++] = s[k];
    }

    if (flags.minus) {
        do_widht(x, str, flags, i);
    }

}

void specifier_u(char *str, int *i, va_list args, flag_struct flags) {
    metamorph_length(args, &flags);
    
    unsigned long int u = flags.number;
    unsigned long int u_copy = u;
    int z = 0;

    for (z; u_copy > 0; z++) {
        u_copy /= 10;
    }
    
    int x = flags.width - z;

    if (!flags.minus) {
        do_widht(x, str, flags, i);
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
    } // дубл

    if (!flags.minus) {
        do_widht(x, str, flags, i);
    }

}

void metamorph_length(va_list args, flag_struct* flags) {
    if (flags->flag_l) {
        flags->number = va_arg(args, long int);
    } else if (flags->flag_h) {
        flags->number = (short)va_arg(args, int);
    } else flags->number = va_arg(args, int); // d u // c s
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

void body_d(long int d, char* str, int* i, flag_struct flags) {
    char number[100] = {0};
    int k = 0;
    if (d < 0) {
        str[(*i)++] = '-';
        d = -(d);
    } else if (flags.plus) { // plus
        // if(flags.width) (*i)--;
        str[(*i)++] = '+';
    } else if (flags.space) { // space
        str[(*i)++] = ' ';
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
        str[(*i)++] = number[z]; // мб сразу в обратном порядке записывать как то можно
    } // дубл
}