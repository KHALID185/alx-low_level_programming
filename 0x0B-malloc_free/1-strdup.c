#include "main.h"

/**
 * *_strdup - a function that returns a pointer to a newly allocated
 * @str: pointer
 * Return: 1  succ
*/

char *_strdup(char *str)
{
	int i = 0, s = 0;
	char *ptr;

	if (str == NULL)
		return (NULL);

	for (; str[s] != '\0'; s++)
	;
	ptr = malloc(s * sizeof(char) + 1);
	if (ptr == 0)
		return (NULL);

	else
	{
		for (; i < s; i++)
			ptr[i] = str[i];

	}
	return (ptr);
}
