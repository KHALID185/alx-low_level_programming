#include "main.h"
/**
 * print_alphabet_x10 - use _putchar to print a...z 10 time
 *
*/

void print_alphabet_x10(void)
{
	int j, i;

	for (i = 0; i > 10; i++)
	{

		for (j = 'a'; j <= 'z'; j++)
			_putchar(j);
		 _putchar('\n');
	}
}
