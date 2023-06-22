#include "main.h"

/**
 * more_numbers - print numbers 0 to 14
 *
 * Return: 0 success
*/

void more_numbers(void)
{
	int i, j, n;

	for (i = 1; i < 11; i++)
	{
		for (j = 0; j < 15; j++)
		{
			n = j;
			if (j >= 10)
			{
				_putchar(1 + 48);
				n = (j % 10);
			}
			_putchar(n + 48);
		}

		_putchar('\n');
	}
}
