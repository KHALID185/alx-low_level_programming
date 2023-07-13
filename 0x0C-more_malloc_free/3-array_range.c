#include "main.h"

/**
 * *array_range - a function that creates an array of integers.
 * @min: minimum integer
 * @max: maximum integer
 * Return: array of integer
*/
int *array_range(int min, int max)
{
int l, j;
int *ptr;

if (min > max)
	return (NULL);
l = max - min + 1;
ptr = malloc(sizeof(int) * l);
if (ptr == 0)
	return (NULL);
for (j = 0; j < l; j++)
	ptr[j] = min++;
return (ptr);
}
