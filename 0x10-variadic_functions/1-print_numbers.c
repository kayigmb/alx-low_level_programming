#include "variadic_functions.h"

/**
 * print_numbers - prints numbers
 * @n: the number of arguments after n
 * @separator: the char\s to print betwen the numbers
 *
 * Description: prints all numbers passed as args after n
 * sperated by (separator) and followed by a new line
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	int i = n;
	va_list ap;

	va_start(ap, n);
	while (i--)
	{
		printf("%d", va_arg(ap, int));
		if (separator && i)
			printf("%s", separator);
	}

	va_end(ap);
	putchar('\n');
}
