#include "main.h"

/**
 * main - Entry pt
 *
 * Return: 0 success
*/

int main(void)
{
	float s_even;
	unsigned long s, fbc1 = 0, fbc2 = 1;

	while (1)
	{
		s = fbc1 + fbc2;
		if (s > 4000000)
			break;
		if ((s % 2) == 0)
			s_even += s;

		fbc1 = fbc2;
		fbc2 = s;
	}
	printf("%0.f\n", s_even);

	return (0);
}
