#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @s: The character
 *
 * Return: 1 success
*/

int _putchar(char s)
{
	return (write(1, &s, 1));
}
