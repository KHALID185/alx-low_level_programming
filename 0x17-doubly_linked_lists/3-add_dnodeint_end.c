#include "lists.h"

/**
 * add_dnodeint_end - add a new node at the end of the list
 * @head: pointer to 1 element of the list
 * @n: contenu
 * Return: the new node
*/

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *n_n = malloc(sizeof(dlistint_t)), *nd;

	if (head == NULL || n_n == NULL)
	{
		if (n_n)
		{
			free(n_n);
			return (NULL);
		}
		else
			return (NULL);
	}
	n_n->n = n;
	n_n->next = NULL;
	if (!*head)
	{
		n_n->prev = NULL;
		*head = n_n;
	}
	else
	{
		nd = *head;
		while (nd->next)
			nd = nd->next;
		nd->next = n_n;
		n_n->prev = nd;
	}
	return (n_n);
}
