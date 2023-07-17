#include "dog.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * lstr - a function calcule the length of a string
 * @str: a string
 * Return: an integer
*/
int lstr(char *str)
{
	int i = 0;

	while (*str++)
	{
		i++;
	}
	return (i);
}

/**
 * *cstr - copy string from source to a destination
 * @i_n: a destination
 * @g_o: string in source
 * Return: string
*/
char *cstr(char *i_n, char *g_o)
{
	int c;

	for (c = 0; g_o[c]; c++)
	{
		i_n[c] = g_o[c];
	}
	i_n[c] = '\0';
	return (i_n);
}

/**
 * new_dog - a function that creates a new dog.
 * @name: name of the new dog
 * @age: age of the dog
 * @owner: owner of new the dog
 * Return: pointer of structure
*/
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *n_d;
	int l_1, l_2;

	if (!name || !owner || age < 0)
		return (NULL);
	l_1 = lstr(name);
	l_2 = lstr(owner);
	n_d = malloc(sizeof(dog_t));
	if (n_d == NULL)
		return (NULL);
	n_d->name = malloc(sizeof(char) * (l_1 + 1));
	if (n_d->name == NULL)
	{
		free(n_d);
		return (NULL);
	}
	n_d->owner = malloc(sizeof(char) * (l_2 + 1));
	if (n_d->owner == NULL)
	{
		free(n_d);
		free(n_d->name);
		return (NULL);
	}
	cstr(n_d->name, name);
	n_d->age = age;
	cstr(n_d->owner, owner);
	return (n_d);
}
