#include "main.h"
/**
 *_printf - recreating the printf function
 *@format: is a character string
 *Return: 0
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
