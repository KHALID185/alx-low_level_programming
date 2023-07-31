#include "lists.h"

/**
 * print_listint - a function that prints all the elements of a listint_t list.
 * @h: head of the list
 * Return: size (number of node)
*/
size_t print_listint(const listint_t *h)
{
	size_t number_el = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		number_el++;
	}
	return (number_el);
}
