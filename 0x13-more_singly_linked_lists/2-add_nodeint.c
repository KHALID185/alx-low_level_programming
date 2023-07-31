#include "lists.h"

/**
 * add_nodeint - a function that adds a new node at the beginning
 * @head: the head of the linked list
 * @n: int
 * Return: the structure
*/

listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *n_n = malloc(sizeof(listint_t));

if (!head || !n_n)
	return (NULL);
n_n->next = NULL;
n_n->n = n;
if (*head)
	n_n->next = *head;
*head = n_n;
return (n_n);
}
