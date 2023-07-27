#include "lists.h"

/**
 * list_len - fct returns the number of elements in a linked list_t list.
 * @h: pointer to the node 1
 * Return: size
*/

size_t list_len(const list_t *h)
{
size_t j = 0;
while (h)
{
	h = h->next;
	j++;
}
return (j);
}
