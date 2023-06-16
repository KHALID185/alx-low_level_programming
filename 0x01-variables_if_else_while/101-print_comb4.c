#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: prints all possible different combinations of two digits
 *
 * Return: 0 (success
*/

int main(void)
{
	int cnum1 = 0, cnum2, cnum3;

	while (cnum1 <= 9)
	{
		cnum2 = 0;
		while (cnum2 <= 9)
		{
			cnum3 = 0;
			while (cnum3 <= 9)
			{
				if (cnum1 != cnum2 && cnum1 < cnum2 &&
				cnum2 != cnum3 && cnum2 < cnum3)
				{
				putchar(cnum1 + 48);
				putchar(cnum2 + 48);
				putchar(cnum3 + 48);

					if (cnum1 + cnum2 + cnum3 != 24)
					{
					putchar(',');
					putchar(' ');
					}
				}
				cnum3++;
			}
			cnum2++;
		}
		cnum1++;
	}
	putchar('\n');
	return (0);

}

