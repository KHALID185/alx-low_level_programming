#include "lists.h"

/**
 * add_dnodeint - add a new node at the biginning of the list
 * @head: pointer to 1 element of the list
 * @n: la valeur quand va ajouter
 * Return: the new node
*/

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *n_n = malloc(sizeof(dlistint_t));

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
	n_n->prev = NULL;
	if (!*head)
	{
		*head = n_n;
		n_n->next = NULL;
	}
	else
	{
		n_n->next = *head;
		(*head)->prev = n_n;
		(*head) = n_n;
	}
	return (n_n);
}
