#include "main.h"

/**
 * print_last_digit - last digit of a number
 *
 * @m: input typr int
 *
 * Return: last digit
*/

int print_last_digit(int m);
{

	int ldigit;

	if (m < 0)
		ldigit = -1 * (m % 10);
	else
		ldigit = m % 10;

	_putchar(ldigit + '0');
	return (ldigit);
}
