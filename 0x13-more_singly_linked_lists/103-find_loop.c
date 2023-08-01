#include "lists.h"

/**
 * find_listint_loop -  a function that finds the loop in a linked list
 * @head: pointer on the first node
 * Return: structure
*/
listint_t *find_listint_loop(listint_t *head)
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
