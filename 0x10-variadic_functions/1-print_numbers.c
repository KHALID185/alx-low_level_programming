#include "variadic_functions.h"

/**
 * print_numbers - a function that prints numbers, followed by a new line.
 * @separator: string to separe
 * @n: numbers of arguments
 * @...: int to print
 * Return: empty
*/

void print_numbers(const char *separator, const unsigned int n, ...)
{
unsigned int j = n;
va_list ptr;

if (!n)
{
	printf("\n");
	return;
}
va_start(ptr, n);
while (j--)
{
	va_arg(ptr, int);
	printf("%d%s", va_arg(ptr, int), j ? (separator ? separator : "") : "\n");
}
va_end(ptr);
}
