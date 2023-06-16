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
	int num = 48;

	while (num <= 102)
	{
		putchar(num);
	if (num == 57)
		num += 39;
	num++;
	}
	putchar('\n');
	return (0);

}

