#include "main.h"

/**
 * l_str - length of string
 * @str: string
 * Return: integer
*/

int l_str(char *str)
{
int j = 0, length;

if (str[j] == '\0')
	return (0);
while (str[j] != '\0')
	length++;
return (length);
}

/**
 * append_text_to_file - a function that appends text at the end of a file.
 * @filename: pointer
 * @text_content: the content to append in file
 * Return: integer
*/

int append_text_to_file(const char *filename, char *text_content)
{
	int f_d, byt_a = 0;
	int l = l_str(text_content);

	if (filename == NULL)
		return (-1);
	f_d = open(filename, O_WRONLY | O_APPEND);
	if (f_d == -1)
		return (-1);
	if (l != 0)
		byt_a = write(f_d, text_content, l);
	close(f_d);
	if (byt_a != l)
		return (-1);
	return (1);

}
