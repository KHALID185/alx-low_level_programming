#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 success
*/

int main(void)
{
	int s, m;

	for (m = 0; m <= 1024; m++)
	{
	if ((m % 3 == 0) || (m % 5 == 0))
		s = s + m;

	}
	printf("%d\n", s);

	return (0);

}
