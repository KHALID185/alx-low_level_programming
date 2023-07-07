#include "main.h"

/**
 * *_memset -  function fills the first n bytes of the memory area pointed
 *  @s: string input
 *  @b: a const char
 *  @n: numbers of bytes
 *  Return: a pointer to the memory area s
*/

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; n > 0; i++, n--)
	{
	s[i] = b;
	}

	return (s);
}
