#include "lists.h"

/**
 * add_nodeint_end - adds a node at the end
 * @head: pointer to the first node
 * @n: valeur integer
 * Return: pointer to a new node
*/

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *n_n = malloc(sizeof(listint_t));
	listint_t *nd;

	if (head == NULL || n_n == NULL)
		return (NULL);
	n_n->next = NULL;
	n_n->n = n;

	if (!*head)
		*head = n_n;
	else
	{
		nd = *head;
		while (nd->next)
			nd = nd->next;
		nd->next = n_n;
	}
	return (n_n);
}
