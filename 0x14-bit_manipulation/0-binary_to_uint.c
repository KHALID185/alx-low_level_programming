#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: pointer to the binary number
 * Return: the converted num or 0
*/

unsigned int binary_to_uint(const char *b)
{
	unsigned int j, res = 0;

	if (b == NULL)
		return (0);
	while (b != NULL)
	{
		if (b[j] != '0' && b[j] != '1')
			return (0);
		res = res * 2 + (b[j++] - '0');
	}
	return (res);
}
