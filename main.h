#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/*Function Prototypes*/
int _printf(const char *format, ...);
void s_case(va_list args, int *count);
void c_case(va_list args, int *count);
int _strlen(char *s);
int _print_int(int n);
#endif
