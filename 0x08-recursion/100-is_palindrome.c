#include "holberton.h"

/**
 * palindrome - function calcule length
 * @a: string
 * @l: integer
 *
 * Return: int
*/

int palindrome(char *a, int l)
{
	if (*a == 0)
		return (l - 1);
	return (palindrome(a + 1, l + 1));
}
/**
 * palind_com - compares string vs string reverse
 * @a: string
 * @l: length
 * Return: int
 */

int palind_com(char *a, int l)
{
	if (*a != *(a + l))
		return (0);
	else if (*a == 0)
		return (1);
	return (palind_com(a + 1, l - 2));
}
/**
 * is_palindrome - checks if a string is a palindrome
 * @s: string
 *
 * Return: 1 or 0
 */
int is_palindrome(char *s)
{
	int l;

	l = palindrome(s, 0);
	return (palind_com(s, l));
}
