#include "main.h"

/**
 * create_file - a function that creates a file.
 * @filename: pointer to the name of that file
 * @text_content: the content to put inside the filename
 * Return: integer
*/

int create_file(const char *filename, char *text_content)
{
int f_d, byt_w, l = 0;

if (!filename)
	return (-1);
if (text_content != NULL)
{
	while (*text_content++)
		l++;

}
f_d = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
byt_w = write(f_d, text_content, l);

if (f_d == -1 || byt_w == -1)
	return (-1);

close(f_d);

return (1);
}
