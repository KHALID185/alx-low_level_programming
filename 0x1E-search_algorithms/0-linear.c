#include "search_algos.h"

/**
 * linear_search - this fct is to search a value in array of int
 * @array: the list of value
 * @size: the size
 * @value: the int we want 
 * Return: integer
 */
int linear_search(int *array, size_t size, int value)
{
	int j;

	if (array == NULL)
		return (-1);

	for (j = 0; j < (int)size; j++)
	{
		printf("Value checked array[%u] = [%d]\n", j, array[j]);
		if (value == array[j])
			return (j);
	}
	return (-1);
}
