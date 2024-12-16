#include "s21_sprintf.h"

int main() {
    char buffer[1028] = {0};
    s21_sprintf(buffer, "Hello %lc", '1');
    printf("%s\n", buffer);
    sprintf(buffer, "Hello %lc", '1');
    printf("%s\n", buffer);
    return 0;
}

int s21_sprintf(char *str, const char *format, ...) {
    va_list args;
    va_start(args, format);
    int j = 0;
    int i = 0;

    while (format[j] != '\0') {
        if (format[j] == '%') {
            j++;
            if (format[j] == 'h') specifier_lh(str, format, &i, &j, args);
            if (format[j] == 'l') specifier_ll(str, format, &i, &j, args);
        else if (format[j] == 'c') specifier_c(str, &i, &j, args);
        else if (format[j] == 'd') specifier_d(str, &i, &j, args);
        else if (format[j] == 'f') specifier_f(str, &i, &j, args);
        else if (format[j] == 's') specifier_s(str, &i, &j, args);
        else if (format[j] == 'u') specifier_u(str, &i, &j, args);
        else if (format[j] == '%') specifier_per(str, format, &i, &j);
        }
        str[i++] = format[j++];
    }
    str[i++] = '\0';
    va_end(args);
    return 0;
}

void specifier_lh(char *str, const char* format, int *i, int* j, va_list args) {
    char number[100] = {0};
    int k = 0;
    if (format[*j+1] == 'd') {
        int hd = va_arg(args, int);
        short int d = (short int)hd;
        if (d < 0) {
            str[(*i)++] = '-';
            d = -d;
        }
         if (d == 0) {
            str[(*i)++] = '0';
            (*j) = (*j)+2;
    } else {
        while (d > 0) {
            number[k++] = (d % 10) + '0';
            d = d / 10;
        }
        (*j) = (*j)+2;

    for (int z = k - 1; z >= 0; z--) {
        str[(*i)++] = number[z];
        }
    }
    }
    if (format[*j+1] == 'u') {
    unsigned int dd = va_arg(args, unsigned int);
    short unsigned int a = (short unsigned int)dd;
    while (a > 0) {
                number[k] = (a % 10) + '0';
                k++;
                a = a / 10;
            }
            (*j) = (*j)+2;
            for (int z = k - 1; z >= 0; z--) {
                str[(*i)++] = number[z];
            }
    }
}


void specifier_ll(char *str, const char* format, int *i, int* j, va_list args) {
    char number[100] = {0};
    int k = 0;
    if (format[*j+1] == 'd') {
        long int d = va_arg(args, long int);
        if (d < 0) {
            str[(*i)++] = '-';
            d = -d;
        }
         if (d == 0) {
            str[(*i)++] = '0';
            (*j) = (*j)+2;
    } else {
        while (d > 0) {
            number[k++] = (d % 10) + '0';
            d = d / 10;
        }
        (*j) = (*j)+2;

    for (int z = k - 1; z >= 0; z--) {
        str[(*i)++] = number[z];
        }
    }
    }
    if (format[*j+1] == 'u') {
    unsigned long int a = va_arg(args, unsigned long int);
    while (a > 0) {
                number[k] = (a % 10) + '0';
                k++;
                a = a / 10;
            }
            (*j) = (*j)+2;
            for (int z = k - 1; z >= 0; z--) {
                str[(*i)++] = number[z];
            }
    }
    if (format[*j+1] == 'c') {
    wchar_t ch = (wchar_t)va_arg(args, int);
    str[(*i)++] = ch;
    (*j) = (*j)+2;
    }
    if (format[*j+1] == 's') {
    char *s = va_arg(args, char *);
    for (int k = 0; s[k] != '\0'; k++) {
        str[(*i)++] = s[k];
    }
    (*j) = (*j)+2;
    }
}


void specifier_c(char *str, int *i, int *j, va_list args) {
    char ch = (char)va_arg(args, int);
    str[(*i)++] = ch;
    (*j)++;
}

void specifier_d(char *str, int *i, int *j, va_list args) {
    int d = va_arg(args, int);
    char number[100] = {0};
    int k = 0;
    if (d < 0) {
        str[(*i)++] = '-';
        d = -d;
    }
    if (d == 0) {
        str[(*i)++] = '0';
        (*j)++;
    } else {
     while (d > 0) {
            number[k++] = (d % 10) + '0';
            d = d / 10;
        }
        (*j)++;

    for (int z = k - 1; z >= 0; z--) {
        str[(*i)++] = number[z];
        }
    }
    
}

void specifier_f(char *str, int *i, int *j, va_list args){
    double f = va_arg(args, double);
    double l = round(f*1000000);
    l = l/1000000;
        char number[100] = {0};
        int k = 0;
        int d = (int)l;
        if (l < 0) {
            str[(*i)++] = '-';
            l = -l;
            d = -d;
        }
         if ((l > 0 && l < 1) || (l == 0))
        {
             str[(*i)++] = '0';
        }
        if (l == '.') {
            number[k++] = '.';
        }
        else {
         while (d > 0) {
            number[k] = (d % 10) + '0';
                k++;
                d = d / 10;
        }
        (*j)++;
        for (int z = k - 1; z >= 0; z--) {
            str[(*i)++] = number[z];
        }
        str[(*i)++] = '.';
        double h = l - (long long)l;
        int count = 0;
        while (count < 6) {
            h = h * 10;
            str[(*i)++] = (int)(long long)h%10 + '0';
            count++;
        } 
    }
}

void specifier_s(char *str, int *i, int *j, va_list args) {
    char *s = va_arg(args, char *);
    for (int k = 0; s[k] != '\0'; k++) {
        str[(*i)++] = s[k];
    }
    (*j)++;
}

void specifier_u(char *str, int *i, int *j, va_list args) {
    unsigned int a = va_arg(args, unsigned int);
    char number[100] = {0};
    int k = 0;
    while (a > 0) {
                number[k] = (a % 10) + '0';
                k++;
                a = a / 10;
            }
            (*j)++;
            for (int z = k - 1; z >= 0; z--) {
                str[(*i)++] = number[z];
            }
}

void specifier_per(char *str, const char *format, int *i, int *j) {
    int count_per = 1;

    while (format[*j] == '%' && format[*j + 1] == '%') {
        count_per++;
        (*j)++;
    }

    if ((format[*j] == '%' && format[*j + 1] != '%')) {
        count_per++;
        (*j)++;
    }

    if (count_per % 2 == 0) {
        for (int k = 1; k <= count_per / 2; k++) {
            str[(*i)++] = '%';
        }
    }
    // Прописать иначе - NULL и остановка программы
}

