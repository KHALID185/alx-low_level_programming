#include "lists.h"

/**
 * free_listint2 - free a list and  sets head to 0
 * @head: pointer to the first elemnet
 * Return: empty
*/

void free_listint2(listint_t **head)
{
listint_t *nd, *nd_1;

if (!head)
	return;

nd = *head;
while (nd)
{
	nd_1 = nd;
	nd = nd->next;
	free(nd_1);
}
*head = NULL;
}
