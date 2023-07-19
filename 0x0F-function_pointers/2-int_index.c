#include "function_pointers.h"
#include <stddef.h>

/**
 * int_index - a function that searches for an integer.
 * @array: les element type integer
 * @size: number of elements
 * @cmp: pointer to the function to be used to compare values
 * Return: integer
*/

int int_index(int *array, int size, int (*cmp)(int))
{
int index = 0;

	if (array == NULL || size <= 0 || cmp == NULL)
	{
		return (-1);
	}
	while (index < size)
	{
		if ((*cmp)(*(array + index)))
			return (index);
		index++;
	}
	return (-1);
}
