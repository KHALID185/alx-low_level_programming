#include <stdio.h>
#include <stdlib.h>

/**
 * main -  prints the minimum number of coins to make change of money.
 * @argc:int
 * @argv:string
 * Return: 0 success
*/

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		int i, lc = 0, money = atoi(argv[1]);
		int c[] = {25, 10, 5, 2, 1};

		for (i = 0; i < 5; i++)
		{
			if (money >= c[i])
			{
				lc += money / c[i];
				money = money % c[i];
				if (money % c[i] == 0)
				{
					break;
				}
			}
		}
	printf("%d\n", lc);
	}
	else
	{
	printf("Error\n");
	return (1);
	}
	return (0);
}
