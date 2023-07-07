#include "main.h"

/**
 * _strcmp - a function that compares two strings.
 * @s1: string 1
 * @s2: string 2
 * Return:the comparation
 */

int _strcmp(char *s1, char *s2)
{
	int counter, cmpVal;

	counter = 0;
	while (s1[counter] == s2[counter] && s1[counter] != '\0')
	{
		counter++;
	}

	cmpVal = s1[counter] - s2[counter];
	return (cmpVal);
}
