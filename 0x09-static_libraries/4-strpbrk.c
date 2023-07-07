#include "main.h"

/**
 * *_strpbrk - searches a string for any of a set of bytes.
 * @s: a string
 * @accept: onther string
 *
 * Return: a pointer to the byte in s that matches one of the bytes in accept
*/

char *_strpbrk(char *s, char *accept)
{
int i, j;
char *res;

i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j] != '\0')
		{
			if (accept[j] == s[i])
			{
			res = &s[i];
			return (res);
			}
			j++;
		}
		i++;
	}
	return (0);
}
