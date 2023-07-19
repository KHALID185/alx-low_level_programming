#include "function_pointers.h"
#include <stddef.h>

/**
 * array_iterator - that executes a function given each element of an array
 * @array: an array of element type int
 * @size: size of the list of int
 * @action: pointer to the function
 * Return: empty
*/
void array_iterator(int *array, size_t size, void (*action)(int))
{
int *adr_arr = array + size;

if (array != NULL && size != 0 && action != NULL)
	while (array < adr_arr)
		(*action)(*array++);
}
