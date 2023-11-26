#include "main.h"
/**
 * _printf - recreating the printf function
 * @format: is a character string
 * Return: 0
 */
int _printf(const char *format, ...)
{
    int i = 0;
    int count = 0;

    va_list args;

    va_start(args, format);

    while (format != NULL && format[i])
    {
        if (format[i] == '%')
        {
            i++;

            switch (format[i])
            {
            case '%': /* case of a % */
                write(1, &format[i], 1);
                break;

            case 's': /* case of a string */
                s_case(args, &count);
                break;

            case 'c': /* case of a single character */
                c_case(args, &count);
                break;

            case 'd': /* case of an integer */
                count += _print_int(va_arg(args, int));
                break;

	    case 'i':
            case 'u': /* case of an unsigned integer */
                count +=  _print_unsigned(va_arg(args, unsigned int));
                break;

            case 'o': /* case of an unsigned octal */
                count += _print_octal(va_arg(args, unsigned int));
                break;

            case 'x': /* case of an unsigned hexadecimal (lowercase) */
                count += _print_hex(va_arg(args, unsigned int), 0);
                break;

            case 'X': /* case of an unsigned hexadecimal (uppercase) */
                count += _print_hex(va_arg(args, unsigned int), 1);
                break;

            case 'p':
                count += _print_ptr(va_arg(args, void *));
                break;

            case 'r':
                write(1, &format[i - 1], 2);
                count += 2;
                break;

            default:
                write(1, "%", 1);
                write(1, &format[i], 1);
            }
        }
        else
            count += write(1, &format[i], 1);
        i++;
    }
    va_end(args);
    return (count);
}
