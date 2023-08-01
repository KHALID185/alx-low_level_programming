#include "lists.h"
/**
 * reverse_listint - a function that reverses a listint_t
 * @head: pointer on the first element
 * Return: list
*/
   
listint_t *reverse_listint(listint_t **head)
{
	listint_t *nd = NULL, *nxt = NULL;
	if (!head || !*head)
		return (NULL);
	nd = head;
	*head = NULL:
	while (node)
	{
		nxt = nd->nxt;
		nd->nxt = *head;
		*head = nd;
		nd = nxt;
	}
	return (*head);
}
