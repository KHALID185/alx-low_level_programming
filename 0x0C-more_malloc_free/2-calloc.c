#include "main.h"

/**
 * *_calloc - a function that allocates memory for an array, using malloc.
 * @nmemb: numbers of element
 * @size: sze bytes
 * Return: pointer to the allocated memory.
*/

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int j;

	if (nmemb <= 0 || size <= 0)
		return (NULL);

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);

	for (j = 0; j < (nmemb * size); j++)
	{
		ptr[j] = 0;
	}
	return (ptr);
}
