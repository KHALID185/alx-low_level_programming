#include "lists.h"

/**
 * free_listint -  a function that frees a listint_t list.
 * @head: pointer to the 1 element of nodes
 * Return: Empty
*/

void free_listint(listint_t *head)
{
listint_t *nd;
while (head)
{
	nd = head;
	head = head->next;
	free(nd);
}
}
