#include "main.h"

/**
 * print_to_98 - prints all natural numbers from n to 98
 *
 * @n: input a number
*/

void print_to_98(int n)
{
	int counteur;

	if (n < 98)
	{
		for (counteur = n; counteur < 98; counteur++)
			printf("%d, ", counteur);
	}
	else
	{
	for (counteur = n; counteur > 98; counteur--)
		printf("%d, ", counteur);

	}
	printf("98\n");
}
