#include "lists.h"

/**
 * dlistint_len - length of list
 * @h: pointer on head
 * Return: size exactly number of nodes
*/
size_t dlistint_len(const dlistint_t *h)
{
	size_t n_n = 0;

	while (h != NULL)
	{
		h = h->next;
		n_n++;
	}
	return (n_n);
}
