#include "main.h"

/**
 * *_realloc - a function that reallocates a memory block using malloc and free
 * @ptr: pointer alloc
 * @old_size: integer
 * @new_size: integer
 * Return: empty
*/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
void *arr;
unsigned int i;

if (new_size == old_size)
	return (ptr);
if (new_size == 0 && ptr != NULL)
{
	free(ptr);
	return (NULL);
}
if (!ptr)
{
	arr = malloc(new_size);
	if (!arr)
		return (NULL);
	return (arr);
}
if (new_size > old_size)
{
	arr = malloc(new_size);
	if (!arr)
		return (NULL);
	for (i = 0; i < new_size; i++)
		*((char *)arr + i) = *((char *)ptr + i);
	free(ptr);
}
return (arr);

}
