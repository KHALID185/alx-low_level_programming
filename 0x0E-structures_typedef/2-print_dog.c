#include "dog.h"
#include <stdio.h>
#include <stddef.h>

/**
 * print_dog -  a function that prints a struct dog
 * @d: structure of dog
 *
 * Return: empty
*/

void print_dog(struct dog *d)
{
if (d != NULL)
{
	printf("Name: %s\n", (*d).name ? (*d).name : "(nil)");
	printf("Age: %f\n", (*d).age);
	printf("Owner: %s\n", (*d).owner ? (*d).owner : "(nil)");
}
}
