#include "main.h"

/**
 * main - Entry pt
 *
 * Return: 0 success
*/

int main(void)
{
	int counteur;
	unsigned long s, fbc1 = 0, fbc2 = 1;

	for (counteur = 0; counteur < 50; counteur++)
	{
		s = fbc1 + fbc2;
		printf("%lu", s);

		fbc1 = fbc2;
		fbc2 = s;
		if (counteur == 49)
			printf("\n");
		else
			printf(", ");

	}
	return (0);
}
