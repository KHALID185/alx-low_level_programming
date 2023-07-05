#include "main.h"

/**
 * _sqrt_recursion - function that returns the natural square root of a number
 * @n: integer
 * @valeur: square root
 * Return: natural square or -1
*/
int square(int n, int valeur);
int _sqrt_recursion(int n)
{
return (square(n, 1));
}
/**
 * square - function square
 * @n: integer
 * @valeur:integer
 * Return:an a integer or -1
*/
int square(int n, int valeur)
{
if (valeur * valeur == n)
	return (valeur);
else if (valeur * valeur < n)
	return (square(n, valeur + 1));
else
	return (-1);
}
