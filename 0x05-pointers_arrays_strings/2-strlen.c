#include "main.h"

/**
 * _strlen - a function that returns the length of a string
 * @s: parametre input
 * Return: length of string
*/

int _strlen(char *s)
{
	int cnt;

	for (cnt = 0; *s != '\0'; s++)
		cnt++;
	return (cnt);
}
