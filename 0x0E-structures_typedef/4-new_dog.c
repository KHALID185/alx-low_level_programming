#include "dog.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * new_dog - a function that creates a new dog.
 * @name: new name
 * @age: age of the new dog
 * @owner: owner of the dog
 * Return: structure of the new dog
*/

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *n_d;

	n_d =  malloc(sizeof(dog_t));
	if (n_d == NULL)
		return (NULL);

	if (name == NULL)
	{
		free(n_d);
		free(owner);
		return (NULL);
	}
	if (owner == NULL)
	{
		free(n_d);
		free(name);
		return (NULL);
	}
	n_d->name = name;
	n_d->age = age;
	n_d->owner = owner;

	return (n_d);
}
