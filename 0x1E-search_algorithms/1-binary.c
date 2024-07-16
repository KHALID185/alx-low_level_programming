#include "search_algos.h"

/**
  * binary_search - search for a int value using binary search
  * @array: list of integer
  * @size: the size
  * @value: int we want
  * Return: integer
  */
int binary_search(int *array, size_t size, int value)
{
	size_t i, ll, rr;

	if (array == NULL)
		return (-1);

	for (ll = 0, rr = size - 1; rr >= ll;)
	{
		printf("Searching in array: ");
		for (i = ll; i < rr; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		i = ll + (rr - ll) / 2;
		if (array[i] == value)
			return (i);
		if (array[i] > value)
			rr = i - 1;
		else
			ll = i + 1;
	}

	return (-1);
}
