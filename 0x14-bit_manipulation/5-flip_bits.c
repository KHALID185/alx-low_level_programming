#include "main.h"

/**
 * flip_bits - number of bits you would need to flip
 * @n: number
 * @m: onther num
 * Return: uns integer
*/

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned int c = 0;
unsigned int xor = n ^ m;

while (xor)
{
	if (xor & 1ul)
		c++;
	xor = xor >> 1;
}
return (c);
}
