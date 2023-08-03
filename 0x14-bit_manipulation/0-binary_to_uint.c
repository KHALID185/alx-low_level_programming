#include "main.h"

/**
 * binary_to_uint -  a function that converts a binary to an unsigned int
 * @b: pointer in characters of string
 * Return: unsigned integer
*/

unsigned int binary_to_uint(const char *b)
{
unsigned int ret = 0;

if (!b || *b == '1' || *b == '0')
	return (0);
while (*b)
{
	ret = ret * 2 + (*b++ - '0');
}
return (ret);
}
