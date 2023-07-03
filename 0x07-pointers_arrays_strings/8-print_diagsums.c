#include "main.h"
/**
 * print_diagsums -a function that prints the sum of the two diagonals
 * @a: a pointer integer
 * @size: size
 * Return: empty
*/

void print_diagsums(int *a, int size)
{
int i, p1 = 0, p2 = 0;

for (i = 0; i < size; i++)
{
	p1 += a[i];
	p2 += a[size - i - 1];
	a += size;

}
printf("%d, ", p1);
printf("%d\n", p1);
}
