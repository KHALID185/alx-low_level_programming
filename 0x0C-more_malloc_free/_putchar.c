#include "main.h"
#include <unistd.h>
/**
 * _putchar - write one string
 * @c: character
 * Return: char
*/

int _putchar(char c)
{
return (write(1, &c, 1));
}
