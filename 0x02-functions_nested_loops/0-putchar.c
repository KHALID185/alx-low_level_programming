#include "main.h"
#include <string.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */

int main(void)
{
char string[] = "_putchar";
unsigned int i;
	for (i = 0; i < strlen(string); i++)
		_putchar(string[i]);
	_putchar('\n');

	return (0);

}
