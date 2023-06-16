#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: prints all single digit numbers using putchar
 *
 * Return: 0 (success)
*/
int main(void)
{
	int num = 0;

	while (num <= 9)
	{
		putchar(num + '0');
		num++;
	}
	putchar('\n');
	return (0);

}
