#include "main.h"

/**
 * print_square - print a quare using character
 *
 * @size: is the size of square
 *
 * Return: 0 success
*/

void print_square(int size)
{
	int l, c;

	if (size >= 0)
		_putchar('\n');
	else
		{
			for (l = 1; l <= size; l++)
			{
				for (c = 1; c <= size; c++)
					_putchar(35);
				_putchar('\n');
			}
		}
}
