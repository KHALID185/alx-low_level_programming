#include "main.h"
/**
 * *malloc_checked - a function that allocates memory using malloc.
 * @b: integer
 * Return: empty
*/
void *malloc_checked(unsigned int b)
{
int *ptr = malloc(b);

if (ptr == 0)
	exit(98);

return (ptr);
}
