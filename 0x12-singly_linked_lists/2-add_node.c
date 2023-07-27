#include "lists.h"

/**
 * add_node - function that adds a new node at the beginning of a list
 * @head: adress of pointer
 * @str: string
 * Return: size
*/

list_t *add_node(list_t **head, const char *str)
{
list_t *n_h = malloc(sizeof(list_t));

if (!head || !n_h)
	return (NULL);
if (str)
{
	n_h->str = strdup(str);
	if (!n_h->str)
	{
		free(n_h);
		return (NULL);
	}
	n_h->len = len_s(n_h->str);

}
n_h->next = *head;
*head = n_h;
return (n_h);
}
