#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * main - a program that adds  numbers
 * @argc:int
 * @argv:string
 * Return: 0 success
*/

int main(int argc, char *argv[])
{
	int i, j, l, add;
	char *p;

	if (argc < 2)
		printf("0\n");
	else
	{
		add = 0;
		for (i = 1; i < argc; i++)
		{
			p = argv[i];
			l = strlen(p);

			for (j = 0; j < l; j++)
			{
				if (isdigit(*(p + j)) == 0)
				{
					printf("Error\n");
					return (1);
				}
			}

			add += atoi(argv[i]);
		}

	printf("%d\n", add);
	}
	return (0);
}
