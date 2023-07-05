#include "main.h"

/**
 * _pow_recursion - function that returns the value of x to the power of y
 * @x: integer
 * @y: integer
 * Return: x pow y or -1
*/

int _pow_recursion(int x, int y)
{
if (y < 0)
	return (-1);
else if (y == 1)
	return (x);
else if (y == 0)
	return (1);
else
	return (x * _pow_recursion(x, y - 1));

}
