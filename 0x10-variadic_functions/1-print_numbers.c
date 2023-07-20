#include "variadic_functions.h"
#include <stdlib.h>
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

va_start(ptr, n);
while (j--)
{
	printf("%d", va_arg(ptr, int));
	if (j != 0 && separator != NULL)
		printf("%s", separator);
}
printf("\n");
va_end(ptr);
}
