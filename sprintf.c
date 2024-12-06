#include <stdarg.h>
#include <stdio.h>

void print_strings(char* bufer, const char* string, ...);

int main() {
    char where[100];
    print_strings(where, "Sun != %s  %s   %s", "Sunshine", "Su3hine", "Sunshine");
    printf("%s\n", where);
    return 0;
}

void print_strings(char* bufer, const char* string, ...) {
    va_list args;
    va_start(args, string);

    int i = 0;
    int j = 0;
    while (string[j] != '\0') {
        if (string[j] == '%') {
            switch (string[j + 1]) {
                case 's': {
                    char* word = va_arg(args, char*);
                    for (int j = 0; word[j] != '\0'; j++) {
                        bufer[i++] = word[j];
                    }
                    j += 2;
                    break;
                }
            }
        }
        bufer[i++] = string[j++];
    }
    va_end(args);
}
