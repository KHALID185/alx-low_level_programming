#include "main.h"

/**
 * leng_str - legth of string
 * @str: string
 * Return: an integer
*/
int leng_str(char *str)
{
	int l;

	for (l = 0; str[l] != '\0'; l++)
	;
	return (l);
}

/**
 * *str_concat - a function that concatenates two strings.
 * @s1: string 1
 * @s2: string 2
 * Return: a pointer
*/
char *str_concat(char *s1, char *s2)
{
int sz1, sz2, i;
char *ptr;

if (s1 == NULL)
	s1 = "\0";
if (s2 == NULL)
	s2 = "\0";

sz1 = leng_str(s1);
sz2 = leng_str(s2);
ptr = malloc((sz1 + sz2) *sizeof(*s1) + 1);
if (ptr == 0)
	return (0);
for (i = 0; i <= sz1 + sz2; i++)
{
	if (i < sz1)
		ptr[i] = s1[i];
	else
		ptr[i] = s2[i - sz1];

}
ptr[i] = '\0';
return (ptr);
}
