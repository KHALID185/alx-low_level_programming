#include "lists.h"

/**
 * delete_dnodeint_at_index - delete node at index
 * @head: pointer at the 1 node
 * @index: uns int place
 * Return: int
*/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *garage = *head;

	if (!(*head))
		return (-1);
	for (; index != 0; index--)
	{
		if (garage == NULL)
			return (-1);
		garage = garage->next;
	}
	if (garage == (*head))
	{
		*head = garage->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}
	else
	{
		garage->prev->next = garage->next;
		if (garage->next != NULL)
			garage->next->prev = garage->prev;
	}
	free(garage);
	return (1);
}
