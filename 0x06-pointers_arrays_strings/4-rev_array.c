#include "main.h"

/**
 *reverse_array - revereses an array.
 *@a: pointer to array.
 *@n: number of elements
 */

void reverse_array(int *a, int n)
{
	int t, c;

	n = n - 1;
	c = 0;
	while (c <= n)
	{
		t = a[c];
		a[c++] = a[n];
		a[n--] = t;
	}
}
