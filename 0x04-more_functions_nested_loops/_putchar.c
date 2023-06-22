#include <unistd.h>
#include "main.h"

/**
 * _putchar - write character
 *
 * @s: the character
 *
 * Return: 1 (success)
*/

int _putchar(char s)
{
	return (write(1, &s, 1));
}
