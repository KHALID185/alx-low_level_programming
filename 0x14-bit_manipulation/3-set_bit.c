#include "main.h"

/**
 * set_bit -  a function that sets the value of a bit to 1 at index.
 * @n: number
 * @index: integr
 * Return: integer
*/

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int j = sizeof(n) * 8;

	if (index >= j)
		return (-1);
	return (!!(*n |= 1L << index));
}
