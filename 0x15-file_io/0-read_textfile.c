#include "main.h"

/**
 * read_textfile - reads and prints it to the POSIX standard output.
 * @filename: name of file
 * @letters: letters that should read and print
 * Return: numbers of bytes
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
ssize_t byt;
char bf[R_BUFFER_S * 8];
int f;

if (!filename || !letters)
	return (0);
f = open(filename, O_RDONLY);
if (f == -1)
	return (0);
byt = read(f, &bf[0], letters);
byt = write(STDOUT_FILENO, &bf[0], byt);
close(f);
return (byt);
}
