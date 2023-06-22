#include "main.h"

/**
 * print_diagonal - print a diagonal
 *
 * @n: number of 
 *
*/

void print_diagonal(int n)
{
	int i, sp;

	if (n <= 0)
		_putchar('\n');
	else
	{
		for (i = 1; i <=  n; i++)
		{
			for (sp = 1; sp <= i; sp++)
				_putchar(' ');
			_putchar(92);
			_putchar('\n');
		}
	}
}
