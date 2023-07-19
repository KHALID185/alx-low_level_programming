#include "function_pointers.h"
#include <stddef.h>

/**
 * print_name - a function that prints a name.
 * @name: the name to u want to print
 * @f: pointers to function
 * Return: empty
*/

void print_name(char *name, void (*f)(char *))
{
if (name != NULL && f != NULL)
	(*f)(name);

}
