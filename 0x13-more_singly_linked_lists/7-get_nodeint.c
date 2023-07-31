#include "lists.h"

/**
 * get_nodeint_at_index - a function that returns the nth node of a linked list
 * @head: pointer
 * @index: integer
 * Return: structure
*/

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
listint_t *nd;
unsigned int el;

for (nd = head, el = 0; nd && el < index; nd = nd->next, el++)
	;
return (nd);
}
