#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0.
*/

void times_table(void)
{
	int c, l, mtrx;

	for (c = 0; c  < 10; c++)
	{
		_putchar(48);
		for (l = 1; l < 10; l++)
		{
		_putchar((',');
		_putchar(' ');
		mtrx = c * l;
		if (mtrx <= 9)
			_putchar(' ');
		else
			_putchar((mtrx / 10) + 48);
		_putchar((mtrx % 10) + 48);
		}
		_putchar('\n');
	}
}
