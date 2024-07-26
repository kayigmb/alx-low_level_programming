#include "variadic_functions.h"

/**
 * printS - prints string
 * @ap: pointer to opject
 */
void printS(va_list *ap)
{
	char *s = va_arg(*ap, char *);

	if (s)
	{
		printf("%s", s);
		return;
	}
	printf("(nil)");
}

/**
 * printC - prints char
 * @ap: pointer to opject
 */
void printC(va_list *ap)
{
	printf("%c", va_arg(*ap, int));
}

/**
 * printI - prints integer
 * @ap: pointer to opject
 */
void printI(va_list *ap)
{
	printf("%d", va_arg(*ap, int));
}

/**
 * printF - prints float
 * @ap: pointer to opject
 */
void printF(va_list *ap)
{
	printf("%f", va_arg(*ap, double));
}

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 *
 * Description: prints all anything passed as args after format
 * the type is acording to the format followed by a new line
 */

void print_all(const char * const format, ...)
{
	int i = -1, index;
	va_list ap;

	void (*fun[4])(va_list *) = {printC, printI, printF, printS};

	va_start(ap, format);
	while (format != NULL && format[++i] != '\0')
	{
		index =	(format[i] == 'c') + (format[i] == 'i') * 2
			+ (format[i] == 'f') * 3 + (format[i] == 's') * 4;
		while (index)
		{
			fun[index - 1](&ap);
			if (format[i + 1] != '\0')
				printf(", ");
			break;
		}
	}
	va_end(ap);
	putchar('\n');
}
