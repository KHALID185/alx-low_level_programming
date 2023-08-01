#include "lists.h"

/**
 * reall - memory allocation again
 * @l: the old list
 * @sz: size
 * @n_n: structure
 * Return: double pointer
*/
const listint_t **reall(const listint_t **l, size_t sz, const listint_t *n_n)
{
const listint_t **n_n_2;
size_t j;
n_n_2 = malloc(sz * sizeof(listint_t));
if (n_n_2 == NULL)
{
free(l);
exit(98);
}
for (j = 0; j < sz - 1; j++)
	n_n_2[j] = l[j];
n_n_2[j] = n_n;
free(l);
return (n_n_2);
}

/**
 * print_listint_safe - a function that prints a listint_t linked list.
 * @head: pointer the first node
 * Return: number of nodes
 */

size_t print_listint_safe(const listint_t *head)
{
size_t j, n_1 = 0;
const listint_t **ls = NULL;
while (head != NULL)
{
	for (j = 0; j < n_1; j++)
	{
		if (head == ls[j])
		{
			printf("-> [%p] %d\n", (void *)head, head->n);
			free(ls);
			return (n_1);
		}
	}
	n_1++;
	ls = reall(ls, n_1, head);
	printf("[%p] %d\n", (void *)head, head->n);
	head = head->next;
}
free(ls);
return (n_1);
}
