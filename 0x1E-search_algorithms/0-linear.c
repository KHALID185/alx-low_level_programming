#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * linear_search - Searches for a value in an array
 * @array: Pointer to the first element
 * @size: Number of elements
 * @value: Value to search for
 * Return: The first index where the value
 */
int linear_search(int *array, size_t size, int value)
{
	size_t j;

	if (array == NULL)
		return (-1);

	for (j = 0; j < size; j++)
	{
		printf("Value checked array[%lu] = [%d]\n", j, array[j]);
		if (array[j] == value)
			return (j);
	}

	return (-1);
}
