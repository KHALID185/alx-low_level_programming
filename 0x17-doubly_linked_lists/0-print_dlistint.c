#include "lists.h"

/**
 * print_dlistint - prints all element of dlistint
 * @h: pointer on head
 * Return: size exactly number of nodes
*/
size_t print_dlistint(const dlistint_t *h)
{
	size_t n_n = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		n_n++;
	}
	return (n_n);
}
