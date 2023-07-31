#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: point the first node
 * Return: integer
*/
int pop_listint(listint_t **head)
{
	listint_t *nd;
	int el;

	if (head == NULL || !*head)
		return (0);
	nd = (*head)->next;
	el = (*head)->n;
	free(*head);
	*head = nd;
	return (el);
}
