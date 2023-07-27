#include "lists.h"


/**
 * add_node_end - add node at the end
 * @head: double pointer
 * @str: string
 * Return: size of list
*/

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *n_n = malloc(sizeof(list_t));
	list_t *nd = *head;

	if (!head || !n_n)
		return (NULL);
	if (str)
	{
		n_n->str = strdup(str);
		if (!n_n->str)
		{
			free(n_n);
			return (NULL);
		}
		n_n->len = len_s(n_n->str);
	}
	if (nd)
	{
	while (nd->next)
		nd = nd->next;
	nd->next = n_n;
	}
	else
		*head = n_n;
	return (n_n);

}
