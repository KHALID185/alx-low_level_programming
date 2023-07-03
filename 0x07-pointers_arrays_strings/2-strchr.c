#include "main.h"

/**
 * *_strchr - the first occurrence of the character c in the string s
 * @s: a string
 * @c: a character to find
 *
 * Return: Returns a pointer to the first occurrence of the character
*/

char *_strchr(char *s, char c)
{
int i;

for (i = 0; s[i] >= '\0'; i++)
{
	if (s[i] == c)
	return (s + i);
}
return ('\0');
}

}
