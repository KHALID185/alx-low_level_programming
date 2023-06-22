#include "main.h"

/**
 * print_triangle - print a diagonal line
 * @size: size of triangle
 *
 * Return: empty
*/

void print_triangle(int size)
{
	int b, h;

	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (h = 1; h <= size; h++)
		{
			for (b = 1; b <= size; b++)
			{
				if ((h + b) <= size)
					_putchar(' ');
				else
					_putchar('#');
			}
			_putchar('\n');
		}
	}
}
