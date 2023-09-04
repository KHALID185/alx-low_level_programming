#include "main.h"

/**
 * read_textfile -reads a text file and prints it to the POSIX stdout
 * @filename: pointer in the first character on the filename
 * @letters: number of l to be read
 * Return: theletters that we are read or 0
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
ssize_t byt_print;
int f_d;
char buff[R_B_S * 8];

if (filename == NULL || letters == 0)
	return (0);
f_d = open(filename, O_RDONLY);
if (f_d == -1)
	return (0);
byt_print = read(f_d, &buff[0], letters);
byt_print = write(STDOUT_FILENO, &buff[0], byt_print);
close(f_d);
return (byt_print);
}
