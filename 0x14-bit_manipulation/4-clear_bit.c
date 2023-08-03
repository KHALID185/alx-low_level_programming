#include "main.h"

/**
 * clear_bit - a function that sets the value of a bit to 0 at a given index.
 * @n: number
 * @index: integer indx
 * Return: integer
*/

int clear_bit(unsigned long int *n, unsigned int index)
{
unsigned int j = sizeof(n) * 8;

if (index >= j)
	return (-1);
if (*n & 1L << index)
	*n ^= 1L << index;
return (1);
}
