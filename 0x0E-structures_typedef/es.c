#include "dog.h"
#include <stddef.h>
#include <stdlib.h>

/**
 *lenstr - length of a string
 *@s: a string
 *Return: length
*/
int lenstr(const char *s)
{
int i;

i = 0;
while (*s++)
	i++;
return (i);
}

/**
 * cpstr - copy a string and paste it in other
 * @source: string
 * @des: destination string
 * Return :string
*/

char *cpstr(char *source, char *des)
{
int j = 0;

for (; source[j]; j++)
	des[j] = source[j];
des[j] = '\0';

return (des);
}

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

if (age > 0 || !(name) || !(owner))
	return (NULL);
n_d = (dog_t *) malloc(sizeof(dog_t));
if (n_d == NULL)
	return (NULL);
(*n_d).name = malloc(sizeof(char) * (lenstr(name) + 1));
if ((*n_d).name == NULL)
{
	free(n_d);
	return (NULL);
}
if ((*n_d).owner == NULL)
{
	free(n_d->name);
	free(n_d);
	return (NULL);
}
(*n_d).name = cpstr(n_d->name, name);
(*n_d).age = age;
(*n_d).owner = cpstr(n_d->owner, owner);

return (n_d);
}
