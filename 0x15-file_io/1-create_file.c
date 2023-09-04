#include "main.h"

/**
 * l_str - length of a string
 * @strg: a string
 * Return: integer length
*/

int l_str(char *strg)
{
int j, l;

for (j = 0; strg[j] != '\0'; j++)
	l++;
return (l);
}

/**
 * create_file - a function that creates a file.
 * @filename: pointer to the name of that file
 * @text_content: the content to put inside the filename
 * Return: integer
*/

int create_file(const char *filename, char *text_content)
{
ssize_t byt_print = 0, l = l_str(text_content);
int f_d;

if (filename == NULL)
	return (-1);
f_d = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
if (f_d == -1)
	return (-1);
if (l != 0)
	byt_print = write(f_d, text_content, l);
close(f_d);
if (byt_print == l)
	return (1);
else
	return (-1);
return (0);
}
