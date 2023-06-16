#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: prints the alphabet in lowercase
 *
 * Return: 0 (success)
*/
int main(void)
{
	char lcase = 'a';

	while (lcase <= 'z')
	{
		if (lcase == 'e' || lcase == 'q')
			lcase++;
		putchar(lcase);
		lcase++;
	}
	printf("\n");
	return (0);

}
