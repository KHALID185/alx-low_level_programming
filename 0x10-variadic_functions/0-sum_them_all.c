#include "variadic_functions.h"

/**
 * sum_them_all - a function that returns the sum of all its parameters.
 * @n: numbers of integer numbers
 * @...: numbers
 * Return: sum
*/

int sum_them_all(const unsigned int n, ...)
{
unsigned int sum = 0, j = 0;
va_list ptr;
if (!n)
	return (0);
va_start(ptr, n);
for (; j < n; j++)
	sum += va_arg(ptr, int);
va_end(ptr);
return (sum);
}
