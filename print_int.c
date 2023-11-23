#include "main.h"
/*
 * _print_int - print integer.
 * @n: argument.
 * Return: i
 */
int _print_int(int n)
{
    int i = 0, j;
    char buffer[20];

    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    else if (n == 0)
    {
        write(1, "0", 1);
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

    return (i);
}
