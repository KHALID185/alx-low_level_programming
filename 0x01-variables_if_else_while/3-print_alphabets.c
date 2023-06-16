#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: prints the alphabet in lowercase and then uppercase
 *
 * Return: 0 (success)
*/
int main(void)
{
	char lcase = 'a';
	char ucase = 'A';

	while (lcase <= 'z')
	{
		putchar(lcase);
		lcase++;
	}

	while (ucase <= 'Z')
	{
		putchar(ucase);
		ucase++;
	}
	printf("\n");

	return (0);

}
