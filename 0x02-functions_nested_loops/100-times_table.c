#include "main.h"

/**
 * print_times_table - Write a function that prints the n times table
 *
 * @n: input number
*/

void print_times_table(int n)
{
	int c, l, mtrx;

	if (n <= 15 && n >= 0)
	{
		for (c = 0; c  < n + 1; c++)
		{
			_putchar(48);
			for (l = 1; l < n + 1; l++)
			{
			_putchar(',');
			_putchar(' ');
			mtrx = c * l;
			if (mtrx <= 9)
				_putchar(' ');
			if (mtrx <= 99)
				_putchar(' ');
			if (mtrx >= 100)
			{
				_putchar((mtrx / 100) + 48);
				_putchar((mtrx / 10) % 10 + 48);
			} else if (mtrx <= 99 && mtrx >= 10)
				_putchar((mtrx / 10) + 48);
			_putchar((mtrx % 10) + 48);
			}
			_putchar('\n');

		}
	}
}

