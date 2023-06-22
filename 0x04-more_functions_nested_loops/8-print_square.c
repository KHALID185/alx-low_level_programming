nclude "main.h"

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

	for (l = 1; l <= size; l++)
	{
		for (c = 1; c <= size; c++)
			_putchar('#');
		_putchar('\n');
	}

}
