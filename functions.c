#include "main.h"
/**
 *s_case - function that print a string
 *@args: the arguments
 *@count: count the string length
 */
void s_case(va_list args, int *count)
{
    char *ptr;

    ptr = va_arg(args, char *);
    if (ptr == NULL)
    {
        write(1, "(null)", 6);
        *count += 6;
    }
    else
    {
        write(1, ptr, _strlen(ptr));
        *count += _strlen(ptr);
    }
}

/**
 *c_case - function that print a single character
 *@args: the argument
 *@count: count the argument
 */
void c_case(va_list args, int *count)
{
    char ch;

    ch = va_arg(args, int);
    write(1, &ch, 1);
    *count += 1;
}


/**
 *_strlen - entry point
 *@s: value pointer
 * Return: str
 */
int _strlen(char *s)
{
    int str = 0;

    while (s[str] != '\0')
    {
        str++;
    }

    return (str);
}

/**
 * _print_unsigned - Print an unsigned integer.
 * @n: The unsigned integer to be printed.
 *
 * Return: The number of characters printed.
 */
int _print_unsigned(unsigned int n)
{
    int i = 0, j;
    char buffer[20];

    if (n == 0)
    {
        write(1, "0", 1);
        return 1;
    }

    while (n != 0)
    {
        buffer[i++] = n % 10 + '0';
        n /= 10;
    }

    for (j = i - 1; j >= 0; j--)
    {
        write(1, &buffer[j], 1);
    }

    return i;
}

/**
 * _print_octal - Prints an unsigned integer in octal format
 * @n: The unsigned integer to be printed
 * Return: The number of characters printed
 */
int _print_octal(unsigned int n)
{
    int i = 0, j;
    char buffer[20];

    if (n == 0)
    {
        write(1, "0", 1);
        return 1;
    }

    while (n != 0)
    {
        buffer[i++] = n % 8 + '0';
        n /= 8;
    }

    for (j = i - 1; j >= 0; j--)
    {
        write(1, &buffer[j], 1);
    }

    return i;
}

/**
 * _print_hex_digit - Converts a hexadecimal digit to its ASCII character
 * @digit: The hexadecimal digit (0-15)
 * @uppercase: Flag indicating whether to print in uppercase (1) or lowercase (0)
 * Return: The ASCII character representing the hexadecimal digit
 */
int _print_hex_digit(int digit, int uppercase)
{
    if (digit < 10)
    {
        return digit + '0';
    }
    else
    {
        return (uppercase ? 'A' : 'a') + (digit - 10);
    }
}

/**
 * _print_hex - Prints an unsigned integer in hexadecimal format
 * @n: The unsigned integer to be printed
 * @uppercase: Flag indicating whether to print in uppercase (1) or lowercase (0)
 * Return: The number of characters printed
 */
int _print_hex(unsigned int n, int uppercase)
{
    int i = 0, j;
    char buffer[20];

    if (n == 0)
    {
        write(1, "0", 1);
        return 1;
    }

    while (n != 0)
    {
        buffer[i++] = _print_hex_digit(n % 16, uppercase);
        n /= 16;
    }

    for (j = i - 1; j >= 0; j--)
    {
        write(1, &buffer[j], 1);
    }

    return i;
}

/**
 * _print_ptr - Prints a pointer address in hexadecimal format
 * @ptr: The pointer to be printed
 * Return: The number of characters printed
 */
int _print_ptr(void *ptr)
{
    unsigned long int value = (unsigned long int)ptr;
    int count = 0;
    
    write(1, "0x", 2);
    count += 2;
    
    count += _print_hex(value, 1);
    
    return count;
}
