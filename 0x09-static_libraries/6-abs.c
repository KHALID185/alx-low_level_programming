#include "main.h"

/**
 * _abs - computes the absolute value of an integer
 *
 * @m: input type int
 *
 * Return: 0 success
*/

int _abs(int m)
{
	if (m < 0)
		m = (-1) * m;
	return (m);

}
