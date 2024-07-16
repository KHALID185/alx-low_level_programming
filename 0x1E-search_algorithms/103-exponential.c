#include "search_algos.h"

/**
  * _b_search - search value using binary search
  * @arr: array
  * @ll: starting index left
  * @rr: ending index right
  * @value: The value to search for.
  *
  * Return: integer
  */
int _b_search(int *arr, size_t ll, size_t rr, int value)
{
	size_t i;

	if (arr == NULL)
		return (-1);

	while (rr >= ll)
	{
		printf("Searching in array: ");
		for (i = ll; i < rr; i++)
			printf("%d, ", arr[i]);
		printf("%d\n", arr[i]);

		i = ll + (rr - ll) / 2;
		if (arr[i] == value)
			return (i);
		if (arr[i] > value)
			rr = i - 1;
		else
			ll = i + 1;
	}

	return (-1);
}

/**
  * exponential_search - using exponential search to found the int in the array
  * @array: Array
  * @size: size of array
  * @value: the int we search
  *
  * Return: integer
  */
int exponential_search(int *array, size_t size, int value)
{
	size_t j = 0, right;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (j = 1; j < size && array[j] <= value; j = j * 2)
			printf("Value checked array[%ld] = [%d]\n", j, array[j]);
	}

	right = j < size ? j : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", j / 2, right);
	return (_b_search(array, j / 2, right, value));
}
