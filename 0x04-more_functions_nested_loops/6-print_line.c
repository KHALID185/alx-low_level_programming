#include "main.h"

/**
 * print_diagonal - print straight line
 *
 * @n: number of \
 *
*/

void print_diagonal(int n)
{
	int i, space;

	if (n <= 0)
		_putchar('\n');
	else
	{
		for (i = O; i <  n; i++)
		{
			for (space = 0; space < i; space++)
				_putchar(' ');
			_putchar(92);
			_putchar('\n');
		}
	}
}
