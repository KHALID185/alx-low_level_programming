#include "main.h"

/**
 * get_endianness - a function that checks the endianness.
 * Return: integer
*/

int get_endianness(void)
{
	unsigned long int ad = 1;

	return (*(char *)&ad);
}
