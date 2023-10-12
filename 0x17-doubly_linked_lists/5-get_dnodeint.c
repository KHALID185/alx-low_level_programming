#include "lists.h"

/**
 * get_dnodeint_at_index - get node dapres index
 * @head: pointer
 * @index: lemplacement
 * Return: the value of list in the index given
*/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int num = 0;

	while (head != NULL)
	{
		if (num == index)
			return (head);
		head = head->next;
		num++;
	}
	return (NULL);
}
