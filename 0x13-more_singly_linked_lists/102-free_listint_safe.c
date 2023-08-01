#include "lists.h"

/**
* floop - finds in linked list the loop
* @head: the first element
* Return: the adress
*/

listint_t *floop(listint_t *head)
{
	listint_t *pnt, *fin;

	if (head == NULL)
		return (NULL);
	for (fin = head->next; fin != NULL; fin = fin->next)
	{
		if (fin == fin->next)
			return (fin);
		for (pnt = head; pnt != fin; pnt = pnt->next)
			if (pnt == fin->next)
				return (fin->next);
	}
	return (NULL);
}

/**
 * free_listint_safe - a function that frees a listint_t list.
 * @h: double pointer to the adress of the first node
 * Return: number
*/

size_t free_listint_safe(listint_t **h)
{
	listint_t *nxt, *l_n;
	size_t l;
	int lp;

	if (h == NULL || *h == NULL)
		return (0);
	l_n = floop(*h);
	for (l = 0; (*h != l_n || lp) && *h != NULL; *h = nxt)
	{
		l++;
		nxt = (*h)->next;
		if (*h == l_n && lp)
		{
			if (l_n == l_n->next)
			{
				free(*h);
				break;
			}
			l++;
			nxt = nxt->next;
			free((*h)->next);
			lp = 0;
		}
		free(*h);
	}
	*h = NULL;
	return (l);
}
