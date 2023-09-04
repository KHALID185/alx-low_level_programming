#include "main.h"

/**
 * l_str - length of a string
 * @strg: a string
 * Return: integer length
*/

int l_str(char *strg)
{
int j = 0;

if (strg == NULL)
	return (-1);

for (j = 0; strg[j];)
	j++;
return (j);
}

/**
 * create_file - a function that creates a file.
 * @filename: pointer to the name of that file
 * @text_content: the content to put inside the filename
 * Return: integer
*/

int create_file(const char *filename, char *text_content)
{
int  byt_print = 0, l_s;
int f_d;

if (filename == NULL)
	return (-1);
f_d = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
if (f_d == -1)
	return (-1);
l_s = l_str(text_content);
if (l_s != -1)
	byt_print = write(f_d, text_content, l_s);
if (byt_print != l_s)
	return (-1);
close(f_d);

return (1);
}
