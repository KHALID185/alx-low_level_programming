#include "lists.h"

/**
 * free_dlistint - free list
 * @head:pointer to the firsr
 * Return: empty
*/

void free_dlistint(dlistint_t *head)
{
	dlistint_t *nd;

	while (head != NULL)
	{
		nd = head;
		head = head->next;
		free(nd);
	}
}
