#include "lists.h"

/**
 * insert_dnodeint_at_index - add a new node at index
 * @h: pointer to 1 element of the list
 * @n: la valeur quand va ajouter
 * @idx: index
 * Return: the new node
*/

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *garage = *h, *n_n;

	if (idx == 0)
		return (add_dnodeint(h, n));
	for (; idx != 1; idx--)
	{
		garage = garage->next;
		if (garage == NULL)
			return (NULL);
	}
	if (garage->next == NULL)
		return (add_dnodeint_end(h, n));
	n_n = malloc(sizeof(dlistint_t));
	if (!n_n)
		return (NULL);

	n_n->n = n;
	n_n->prev = garage;
	n_n->next = garage->next;
	garage->next->prev = n_n;
	garage->next = n_n;

	return (n_n);
}
