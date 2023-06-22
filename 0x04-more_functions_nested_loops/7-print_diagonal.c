#include "main.h"

/**
 * print_diagonal - print a diagonal
 *
 * @n: number of \
 *
*/

void print_diagonal(int n)
{
	int i, sp;

	if (n <= 0)
		_putchar('\n');
	else
	{
		for (i = 0; i <  n; i++)
		{
			for (sp = 0; sp < n; sp++)
				_putchar(' ');
			_putchar(92);
			_putchar('\n');
		}
	}
}
