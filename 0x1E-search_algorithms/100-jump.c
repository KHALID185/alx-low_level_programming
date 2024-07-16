#include "search_algos.h"

/**
  * jump_search - search a int value using jump search
  * @array: array
  * @size: the size of array
  * @value:the value we want
  * Return: integer
  */
int jump_search(int *array, size_t size, int value)
{
	size_t i, jmp, etape;

	if (array == NULL || size == 0)
		return (-1);

	etape = sqrt(size);
	for (i = jmp = 0; jmp < size && array[jmp] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", jmp, array[jmp]);
		i = jmp;
		jmp += etape;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", i, jmp);

	jmp = jmp < size - 1 ? jmp : size - 1;
	for (; i < jmp && array[i] < value; i++)
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	printf("Value checked array[%ld] = [%d]\n", i, array[i]);

	return (array[i] == value ? (int)i : -1);
}
