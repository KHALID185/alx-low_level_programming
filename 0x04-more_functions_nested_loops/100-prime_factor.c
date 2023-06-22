#include <stdio.h>

/**
 * _sqrt -f inds the square root
 *
 * @x: input num
 *
 * Return: square root of x
*/

double _sqrt(double x)
{
	float sqrt, k;

	sqrt = x / 2;
	k = 0;
	while (sqrt != k)
	{
		k = sqrt;
		sqrt = (x / k + k) / 2;
	}
	return (sqrt);
}

/**
 * l_p_f - finds and prints the largrst prime factor of num
 *
 * @n: number to find
*/

void l_p_f(long int n)
{
	int n_1, l;

	while (n % 2 == 0)
		n = n / 2;
	for (n_1 = 3; n_1 <= _sqrt(n); n_1 += 2)
	{
		while (n % n_1 == 0)
		{
			n = n / n_1;
			l = n_1;
		}
	}

	if (n > 2)
		l = n;
	printf("%d\n", l);

}

/**
 * main - Entry pt
 *
 * Return: 0 success
*/

int main(void)
{
	l_p_f(612852475143);
	return (0);
}
