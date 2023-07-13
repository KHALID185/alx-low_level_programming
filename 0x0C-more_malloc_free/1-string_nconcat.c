#include "main.h"

/**
 * *string_nconcat -  a function that concatenates two strings.
 * @s1: string 1
 * @s2: string 2
 * @n: integer
 * Return: first string and n element of string 2
*/

char *string_nconcat(char *s1, char *s2, unsigned int n);
{
char *ptr;
unsigned int i, j, l_1, l_2;
if (s1 == NULL)
	s1 = "";
if (s2 == NULL)
	s2 = "";

for (l_1 = 0; s1[l_1] != '\0'; l_1++)
	;
for (l_2 = 0; s2[l_2] != '\0'; l_2++)
	;
ptr = malloc(l_1 + n + 1);
if (ptr == NULL)
	return (NULL);
for (i = 0; s1[i] != '\0'; i++)
	ptr[i] = s1[i];
for (j = 0; j < n; j++)
{
	ptr[i] = s2[j];
	i++;
}
ptr[i] = '\0';
return (ptr);
}
