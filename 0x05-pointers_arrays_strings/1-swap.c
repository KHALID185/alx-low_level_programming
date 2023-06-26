#include "main.h"

/**
 * swap_int - function that swaps the values of two integers
 * @a: first variable int
 * @b: second variable int
*/
void swap_int(int *a, int *b)
{
	int vr;

	vr = *a;
	*b = *a;
	*b = vr;
}
