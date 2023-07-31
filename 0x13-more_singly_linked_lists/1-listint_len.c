#include "lists.h"

/**
 * listint_len - a function that prints all the elements of a listint_t list.
 * @h: head of the list
 * Return: length (number of node)
*/
size_t listint_len(const listint_t *h)
{
	size_t number_el = 0;

	while (h)
	{
		h = h->next;
		number_el++;
	}
	return (number_el);
}
