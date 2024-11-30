#define NULL ((void*)0); //в интернете написано что это определение нулевого указателя
#include <stdio.h>
unsigned long size_t;

void* memchr(const void* ptr, int ch, size_t count) {
  //const unsigned char* p = (const unsigned char*)ptr;
  void* return_value = NULL;
  for (size_t i = 0; i < count; i++) {
    if (ptr[i] ==  (unsigned char)ch) {
      return_value = (void*)(ptr + i);
      break;//!!!!!!!!!!!!!!
      }
    }
    return return_value;
}
// ptr – указатель на область памяти, где будет производиться поиск.
// ch – символ, который нужно найти.Этот параметр 
//приводится к типу unsigned char.count – количество байт,
//которые будут проверены начиная с позиции, указанной параметром ptr.
int main() { memchr(const void* ptr, int ch, unsigned long size_t count); }
