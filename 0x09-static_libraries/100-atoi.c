#include "main.h"

/**
 * _atoi -  a function that convert a string to an integer
 * @s: string param
 * Return: convert int frm str
*/

int _atoi(char *s)
{
	unsigned int number = 0;
	int signe = 1;

	do {
		if (*s == '-')
			signe *= -1;
		else if (*s >= '0' && *s <= '9')
			number = (number * 10) + (*s - '0');
		else if (number > 0)
			break;
	} while (*s++);

	return (number * signe);
}
