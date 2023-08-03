#include "main.h"

/**
 * flip_bits - umber of bits you would need to flip to get from one number
 * @n: number
 * @m: another number
 * Return: integer
*/

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor = n ^ m;
	unsigned int c = 0;

	while (xor)
	{
		if (xor & 1ul)
			c++;
		xor = xor >> 1;
	}
	return (c);
}
