#include "variadic_functions.h"

/**
 * sum_them_all - calculates the sum of all parameters.
 * @n: the number of arguments after n
 *
 * Return: the sum of numbers or 0 if n == 0
 */

int sum_them_all(const unsigned int n, ...)
{
	int i = n, sum = 0;
	va_list ap;

	if (n == 0)
		return (0);

	va_start(ap, n);
	while (i--)
	{
		sum += va_arg(ap, int);
	}
	va_end(ap);
	return (sum);
}
