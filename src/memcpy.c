// Копирует n символов из src в dest.
// memory_to — указатель на область памяти, куда будут скопированы данные.
// memory_from — указатель на  область памяти, откуда будут скопированы данные.
//  size — количество байт, которые нужно скопировать.

#include <stdio.h>

#define s21_NULL (void *)0
#define s21_size_t unsigned long long

void *s21_memcpy(void *memory_to, const void *memory_from, size_t size){

    for (size_t i=0; i<size; i++){
        ((unsigned char*)memory_to)[i] = ((unsigned char *)memory_from)[i];
    }
    return memory_to;
}