#include <unistd.h>

/**
 * _putchar - write character
 *
 * @c: the character
 *
 * Return: 1 (success)
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
