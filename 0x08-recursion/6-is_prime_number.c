#include "main.h"

/**
 * is_prime_number -  a function that returns 1 if the input integer
 * @n: integer
 * @i: integer to check
 * @Return: 1 or 0
*/

int is_it_primenum(int n, int i);
int is_prime_number(int n)
{
	return (is_it_primenum(n, 2));
}

/**
 * is_it_primenum - fct to check
 * @n: integer
 * @i: integer to check
 * Return: 0 or 1
*/
int is_it_primenum(int n, int i)
{
if (n > 1 && i > n + 1)
	return (1);
else if (n % i == 0 || n < 2)
	return (0);
else
	return (is_it_primenum(n, i + 1));
}
