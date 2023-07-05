#include "main.h"

/**
 * prime - check numbers
 * @a: integer
 * @i: integer
 *
 * Return:  1 or 0
 */
int prime(int a, int i)
{
	if (a == i)
		return (1);
	else if (a % i == 0)
		return (0);
	return (prime(a, i + 1));
}
/**
 * is_prime_number - checks if a number is prime
 * @n: Number Integer
 *
 * Return: 1 or 0.
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (prime(n, 2));
}
