#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

/*Function Prototypes*/
int _printf(const char *format, ...);
void s_case(va_list args, int *count);
void c_case(va_list args, int *count);
int _strlen(char *s);
int _print_int(int n);
int _print_unsigned(unsigned int n);
int _print_octal(unsigned int n);
int _print_hex_digit(int digit, int uppercase);
int _print_hex(unsigned int n, int uppercase);
int _print_ptr(void *ptr);
#endif
