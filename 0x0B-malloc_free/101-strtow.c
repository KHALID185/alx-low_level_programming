#include "main.h"

/**
 * cmptw - compteur for words
 * @st: word to count
 * Return: number of words type integer
*/

int cmptw(char *st)
{
int i, cmpt = 0;

for (i = 0; st[i]; i++)
{
	if (st[i] == ' ')
	{
		if (st[i + 1] != ' ' && st[i + 1] != '\0')
			cmpt++;
	}
	else if (i == 0)
		cmpt++;

}
cmpt++;
return (cmpt);

}
/**
 * **strtow - a function that splits a string into words.
 * @str:a double pointer
 * Return: a pointer to an array of strings
*/
char **strtow(char *str)
{
int i, j, a, b, cnt = 0, cntw = 0;
char **ptr;

if (str == NULL || *str == '\0')
	return (NULL);
cnt = cmptw(str);
if (cnt == 1)
	return (NULL);
ptr = (char **)malloc(sizeof(char *) * cnt);
if (ptr == NULL)
	return (NULL);
ptr[cnt - 1] = NULL;
i = 0;
while (str[i])
{
	if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
	{
		for (j = 1; str[i + j] != ' ' && str[i + j]; j++)
			;
		j++;
		ptr[cntw] = (char *)malloc(sizeof(char) * j);
		j--;
		if (ptr[cntw] == NULL)
		{
			for (a = 0; a < cntw; a++)
				free(ptr[a]);
			free(ptr[cnt - 1]);
			free(ptr);
			return (NULL);
		}
		for (b = 0; b < j; b++)
			ptr[cntw][b] = str[i + b];
		ptr[cntw][b] = '\0';
		cntw++;
		i += j;
	}
	else
		i++;
}
return (ptr);
}
