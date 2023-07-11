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
 * *argstostr -  a function that concatenates all the arguments
 * @ac: integer
 * @av: double pointer to string
 * Return: a string
*/

char *argstostr(int ac, char **av)
{
	int i = 0, j = 0, str_c = 0, ligne = 0;
	char *ptr;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++, str_c++)
		str_c += leng_str(av[i]);

	ptr = malloc(sizeof(char) * str_c + 1);
	if (ptr == 0)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++, ligne++)
			s[ligne] = av[i][j];
		s[ligne] = '\n';
		ligne++;
	}
	s[ligne] = '\0';
	return (ptr);
}
