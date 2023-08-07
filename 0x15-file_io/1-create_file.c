#include "main.h"

/**
 * len_s - length of string
 * @str: string
 * Return: the length integer
*/

int len_s(char *str)
{
int j = 0;
if (!str)
	return (0);
while (*str++)
	j++;
return (j);
}

/**
 * create_file -  a function that creates a file.
 * @filename: name of file
 * @text_content: contenue
 * Return: integer
*/

int create_file(const char *filename, char *text_content)
{
	int f;
	ssize_t byt = 0,  l = len_s(text_content);

	if (!filename)
		return (-1);
	f = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (f == -1)
		return (-1);
	if (l)
		byt = write(f, text_content, l);
	close(f);
	byt = l ? 1 : -1;
	return (byt);
}
