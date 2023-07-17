#include "dog.h"
#include <stdlib.h>
#include <stddef.h>
/**
 * free_dog - a function that frees dogs.
 * @d: pointer of struct
 * Return: empty
*/
void free_dog(dog_t *d)
{
if (d != NULL)
{
	free((*d).name);
	free((*d).owner);
	free(d);
}
}
