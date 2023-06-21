#include "main.h"

/**
 * print_sign - rints + if n is greater than zero  prints 0
 *
 * @m: take int type input for fct
 *
 * Return: 1 or 0 or -1
 *
*/

int print_sign(int m)
{
	if (m > 0)
	{
		_putchar(43);
		return (1);
	}
	else if (m == 0)
	{
		_putchar(48);
		return (0);
	}
	else
	{
		_putchar(45);
		return (-1);
	}

}
