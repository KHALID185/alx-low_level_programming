#include "lists.h"

/**
 * sum_dlistint - sum of all data
 * @head: pointer
 * Return: sum integer
*/
int sum_dlistint(dlistint_t *head)
{
	int s = 0;

	while (head != NULL)
	{
		s += head->n;
		head = head->next;
	}
	return (s);
}
