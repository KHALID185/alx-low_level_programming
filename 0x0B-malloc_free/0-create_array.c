#include "main.h"

/**
 * *create_array - creates an array of chars
 * @size: size of array
 * @c: the specific character to initialize
 * Return: pointer
*/

char *create_array(unsigned int size, char c)
{
	char *ptr = malloc(size);

	if (size == 0 || ptr == 0)
		return (0);
	while (size--)
		ptr[size] = c;
	return (ptr);
}
