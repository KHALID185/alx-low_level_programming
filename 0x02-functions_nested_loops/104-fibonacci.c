#include "main.h"

/**
 * fct_fbc - length of string
 *
 * @n: operand num
 *
 * Return: number of digit
*/

int fct_fbc(int n)
{
	int length = 0;

	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		length += 1;
	}
	return (length);
}

/**
 * main - Entry pt
 *
 * Return: 0 success
*/

int main(void)
{
	int counteur, init;
	unsigned long s, fbc1 = 1, fbc2 = 2, max = 100000000;
	unsigned long  f1i = 0, f2i = 0, si = 0;

	for (counteur = 1; counteur < 99; counteur++)
	{
		if (f1i > 0)
			printf("%lu", f1i);
		init = fct_fbc(max) - 1 - fct_fbc(fbc1);

		while (f1i > 0 && init > 0)
		{
			printf("%d", 0);
			init--;
		}

		printf("%lu", fbc1);

		s = (fbc1 + fbc2) % max;
		si = f1i + f2i + (fbc1 + fbc2) / max;
		fbc1 = fbc2;
		f1i = f2i;
		fbc2 = s;
		f2i = si;
		if (counteur != 98)
			printf(", ");
		else
			printf("\n");

	}
	return (0);
}
