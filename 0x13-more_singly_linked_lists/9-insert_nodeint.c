#include "lists.h"

/**
 * insert_nodeint_at_index -  a function that inserts a new node at a given pos
 * @head: pointer
 * @idx: index
 * @n: the value of the nd
 * Return: the new structure
*/

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
listint_t *nd, *n_n = malloc(sizeof(listint_t));
unsigned int j;

if (!head || !n_n)
	return (NULL);
n_n->n = n;
n_n->next = NULL;

if (!idx)
{
	n_n->next = *head;
	*head = n_n;
	return (n_n);
}
nd = *head;
while (nd)
{
	if (j == idx - 1)
	{
		n_n->next = nd->next;
		nd->next = n_n;
		return (n_n);
	}
	j++;
	nd = nd->next;
}
free(n_n);
return (NULL);
}
