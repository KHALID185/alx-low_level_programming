#include "main.h"

/**
 * _isalpha - check lowercase or uppercase
 *
 * @c: input of function
 *
 * Return: 1 if c is lowercase 0 otherwise
 *
 */
int _isalpha(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}
