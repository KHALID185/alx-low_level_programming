#include "main.h"

/**
 * _print_rev_recursion - a function that prints a string in reverse.
 * @s: string to print
*/

void _print_rev_recursion(char *s)
{
while (*s != '\0')
	s++;
_putchar(*s);
_print_rev_recursion(s - 1);
}
