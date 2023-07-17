#include "dog.h"
#include <stddef.h>
/**
 * init_dog - a function that initialize a variable of type struct dog
 * @d: the structure dog
 * @name: dog name
 * @age: age of dog
 * @owner: the owner of the dog
 * Return: empty
*/

void init_dog(struct dog *d, char *name, float age, char *owner)
{
if (d != NULL)
{
	(*d).name = name;
	(*d).age = age;
	(*d).owner = owner;
}
}