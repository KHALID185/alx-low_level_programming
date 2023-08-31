#include "main.h"

/**
 * print_binary - prints the binary representation
 * @n: integer number
 * Return: empty
*/

void print_binary(unsigned long int n)
{
	int b = sizeof(n) * 8, prt = 0;

	while (b)
	{
		if (n & 1L << --b)
		{
			_putchar ('1');
			prt++;
		}
		else if (prt)
			_putchar('0');
	}
	if (!prt)
		_putchar('0');

}
