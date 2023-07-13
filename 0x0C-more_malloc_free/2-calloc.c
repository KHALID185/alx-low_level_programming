#include "main.h"

/**
 * *_nelement - fills of memory
 * @p: pointer
 * @c: constant byte
 * @m: le max byte to use
 * Return: pointer
*/
char *_nelement(char *p, char c, unsigned int m)
{
char *ptr = p;

while (m--)
	*p++ = c;

return (ptr);
}

/**
 * *_calloc - a function that allocates memory for an array, using malloc.
 * @nmemb: numbers of element
 * @size: sze bytes
 * Return: pointer to the allocated memory.
*/

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *arr;

	if (size == 0 || nmemb == 0)
		return (NULL);
	arr = malloc(sizeof(int) * nmemb);

	if (!arr)
		return (NULL);

	_nelement(arr, 0, sizeof(int) * nmemb);

return (arr);
}
