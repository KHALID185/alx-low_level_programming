#include "main.h"

/**
 * _isdigit - check number
 *
 * @c: character input
 *
 * Return: 1 if its upper 0 if not
*/

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);

}
