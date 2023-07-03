#include "main.h"

/**
 * *_memcpy - copies n bytes from memory area src to memory area dest
 *
 * @dest: an string
 * @src: string with n element to copy
 * @n: numbers of bytes to copy
 *
 * Return: a pointer dest
*/

char *_memcpy(char *dest, char *src, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
	dest[i] = src[i];

return (dest);
}
