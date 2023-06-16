#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: prints all possible different combinations of two digits
 *
 * Return: 0 (success)
*/
int main(void)
{
	int cnum1 = 0, cnum2;

	while (cnum1 <= 9)

	{
		cnum2 = 0;
		while (cnum2 <= 9)
		{
			if (cnum1 != cnum2 && cnum1 < cnum2)
			{
			putchar(cnum1 + 48);
			putchar(cnum1 + 48);
				if (cnum1 + cnum2 != 17)
				{
				putchar(',');
				putchar(' ');
				}
			}
			cnum2++;
		}
		cnum1++;
	}
	putchar('\n');
	return (0);

}
