#include "main.h"

/**
 * print_most_numbers - print numbers except 2 and 4
 *
 * Return: 0 success
*/

void print_most_numbers(void)
{
	char i;

	for (i = 48; i < 58; i++)
	{
		if (i != 50 && i != 52)
			_putchar(i);
	}
	_putchar('\n');

}
