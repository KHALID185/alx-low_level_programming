#include "search_algos.h"

/**
 * bin_search - use the Binary search algorithm to found the int value
 * @array: input array
 * @size: size of the array
 * @value: value to search in
 * Return: index of the number
 */
int bin_search(int *array, size_t size, int value)
{
	size_t hlf = size / 2;
	size_t i;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array");

	for (i = 0; i < size; i++)
		printf("%s %d", (i == 0) ? ":" : ",", array[i]);

	printf("\n");

	if (hlf && size % 2 == 0)
		hlf--;

	if (value == array[hlf])
	{
		if (hlf > 0)
			return (bin_search(array, hlf + 1, value));
		return ((int)hlf);
	}

	if (value < array[hlf])
		return (bin_search(array, hlf + 1, value));

	hlf++;
	return (bin_search(array + hlf, size - hlf, value) + hlf);
}

/**
 * advanced_binary - use advanced binary to found the value
 * @array: the array
 * @size: the size int
 * @value: the int we want
 * Return: integer
 */
int advanced_binary(int *array, size_t size, int value)
{
	int indx;

	indx = bin_search(array, size, value);

	if (indx >= 0 && array[indx] != value)
		return (-1);

	return (indx);
}
