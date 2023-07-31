#include "lists.h"

/**
 * sum_listint - function that returns the sum of all the data (n)
 * @head: ponter on the first element
 * Return: integer sum
*/
int sum_listint(listint_t *head)
{

unsigned int somme;

somme = 0;
while (head)
{
somme += head->n;
head = head->next;
}
return (somme);
