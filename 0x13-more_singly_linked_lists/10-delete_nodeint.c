#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index index
 * @head: pointer to the first node
 * @index: int
 * Return: integer
*/

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *nd, *n_pre;
unsigned int j = 0;

if (!head || !*head)
	return (-1);

if (!index)
{
	nd = *head;
	*head = (*head)->next;
	free(nd);
	return (1);
}
nd = *head;
while (nd)
{
	if (j == index)
	{
	n_pre->next = nd->next;
	free(nd);
	return (1);
	}
	j++;
	n_pre = nd;
	nd = nd->next;
}
return (-1);
}
