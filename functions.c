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
		write(1, ptr, _strlen(ptr));
		*count += _strlen(ptr);
}

/**
 *c_case - function that print a single character
 *@args: the argument
 *@count: count the argument
 */
void c_case(va_list args, int *count)
{
	char *ptr;

	ptr = va_arg(args, char *);
	write(1, &ptr, 1);
	*count += 1;
}
