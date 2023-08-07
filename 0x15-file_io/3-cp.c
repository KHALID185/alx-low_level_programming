#include "main.h"
#define P (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)
#define U "Usage: cp file_from file_to\n"
#define ERNR "Error: Can't read from file %s\n"
#define ERNW "Error: Can't write to %s\n"
#define ERNC "Error: Can't close fd %d\n"

/**
 * main - entry fct
 * @ac: arg conteur
 * @av: arg vect
 * Return: 1 success
*/

int main(int ac, char **av)
{
	int ff = 0, tf = 0;
	ssize_t byt;
	char bff[R_BUFFER_S];

	if (ac != 3)
		dprintf(STDERR_FILENO, U), exit(97);
	ff = open(av[1], O_RDONLY);
	if (ff == -1)
		dprintf(STDERR_FILENO, ERNR, av[1]), exit(98);
	tf = open(av[2], O_RDONLY | O_CREAT | O_TRUNC, P);
	if (tf == -1)
		dprintf(STDERR_FILENO, ERNW, av[2]), exit(99);
	while ((byt = read(ff, bff, R_BUFFER_S)) > 0)
		if (write(tf, bff, byt) != byt)
			dprintf(STDERR_FILENO, ERNW, av[2]), exit(99);
	if (byt == -1)
		dprintf(STDERR_FILENO, ERNR, av[1]), exit(98);
	ff = close(ff);
	tf = close(tf);
	if (ff)
		dprintf(STDERR_FILENO, ERNC, ff), exit(100);
	if (tf)
		dprintf(STDERR_FILENO, ERNC, ff), exit(100);
	return (EXIT_SUCCESS);
}

