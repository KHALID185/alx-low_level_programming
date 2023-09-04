#include "main.h"

/**
 * l_str - length of a string
 * @str: a string
 * Return: int
*/

int l_str(char *str)
{
	int j = 0;

	while (str[j] != '\0')
		j++;
	return (j);
}

/**
 * append_text_to_file - a function that appends text at the end of a file.
 * @filename: pointer to the name of that file
 * @text_content: the content to put inside the filename
 * Return: integer
*/

int append_text_to_file(const char *filename, char *text_content)
{
int f_d, byt_a, l = 0;

if (!filename)
	return (-1);
if (text_content != NULL)
{
	while (text_content[l] != '\0')
		l++;
}
f_d = open(filename, O_WRONLY | O_APPEND);
byt_a = write(f_d, text_content, l);

if (f_d == -1 || byt_a == -1)
	return (-1);

close(f_d);

return (1);
}
