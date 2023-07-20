#include "variadic_functions.h"

/**
 * print_strings - a function that prints strings, followed by a new line.
 * @separator: separer les strings
 * @n: numbers of arguments
 * @...: characters to prints
*/

void print_strings(const char *separator, const unsigned int n, ...)
{
unsigned int j = 0;
char *ch;
va_list ptr;

va_start(ptr, n);
for (; j < n; j++)
{
	ch = va_arg(ptr, char *);
	if (ch == NULL)
		printf("(nil)");
	else
		printf("%s", ch);
	if (j != (n - 1) && separator != NULL)
		printf("%s", separator);
}
printf("\n");
va_end(ptr);
}
