#include "variadic_functions.h"

/**
 * print_strings - prints numbers
 * @n: the number of arguments after n
 * @separator: the char\s to print betwen the numbers
 *
 * Description: prints all numbers passed as args after n
 * sperated by (separator) and followed by a new line
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	int i = n;
	char *s;
	va_list ap;

	va_start(ap, n);
	while (i--)
	{
		s = va_arg(ap, char *);
		if (s)
			printf("%s", s);
		else
			printf("(nil)");
		if (separator && i)
			printf("%s", separator);
	}

	va_end(ap);
	putchar('\n');
}
