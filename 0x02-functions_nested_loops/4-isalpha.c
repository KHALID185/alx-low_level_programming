#include "main.h"

/**
 * _islpha - check lowercase
 *
 * @c: input of function
 *
 * Return: 1 if c is lowercase 0 otherwise
 *
 */
int _islpha(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}
