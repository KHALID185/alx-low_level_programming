#include "lists.h"

/**
 * len_s - length of a string
 * @st: string
 * Return: integer
*/

int len_s(char *st)
{
int j = 0;

if (!st)
	return (0);
while (*st++)
	j++;
return (j);
}

/**
 * print_list - a function that prints all the elements of a list_t list.
 * @h: poi,ter to th first node
 * Return: number of nodes
*/

size_t print_list(const list_t *h)
{
size_t j = 0;
while (h)
{
	printf("[%d] %s\n", len_s(h->str), h->str ? h->str : "(nil)");
	h = h->next;
	j++;
}
return (j);
}
