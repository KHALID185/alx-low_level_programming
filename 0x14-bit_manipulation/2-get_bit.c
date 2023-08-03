#include "main.h"

/**
 * get_bit - that returns the value of a bit at a given index.
 * @n: number
 * @index: integer
 * Return: integer
*/

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int j = sizeof(n) * 8;
if (index >= j)
	return (-1);
return (n >> index & 1);
}
