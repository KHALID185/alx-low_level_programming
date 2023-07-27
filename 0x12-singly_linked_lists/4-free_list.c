#include "lists.h"

/**
 * free_list - a function that frees a list_t list.
 * @head: pointer to head node
 * Return: empty
*/

void free_list(list_t *head)
{
list_t *nd, *n_n;
if (!head)
	return;
nd = head;
while (nd)
{
	n_n = nd->next;
	free(nd->str);
	free(nd);
	nd = n_n;
}
}
