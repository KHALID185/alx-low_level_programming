#include "main.h"

/**
 * pstr - print string
 * @s: pointer
 * Return: empty
*/
void pstr(char *s)
{
	int j = 0;

	while (s[j])
	{
		_putchar(s[j]);
		j++;
	}
}

/**
 * stoi - string to int
 * @str: string
 * Return: int
*/

int stoi(const char *str)
{
	int signe = -1;
	unsigned long int res = 0, n_1, i;
	unsigned long int div = 1, k, res_f;

	for (n_1 = 0; !(str[n_1] <= 57 && str[n_1] >= 48); n_1++)
	{
		if (str[n_1] == '-')
		{
			signe *= -1;
		}
	}
	for (i = n_1; str[i] <= 57 && str[i] >= 48; i++)
	{
		res *= 10;
		res += (str[i] - 48);
	}
	for (k = 0; res / div > 9; k++, div *= 10)
	;
	for (; div >= 1; res %= div, div /= 10)
	{
		res_f = res / div;
	}

	return (signe * res_f);
}

/**
 * main - resultat of multiplucatio
 * @argc: int
 * @argv: array
 * Return: 0 success
*/

int main(int argc, char const *argv[])
{
	int i, j;
	unsigned long m;

	if (argc != 3)
	{
		pstr("Error\n");
		exit(98);
	}
	for (i = 0; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] < 48 || argv[i][j] > 58)
			{
				printf("Error\n");
				exit(98);
			}
		}
	}
	m = (stoi(argv[1]) * stoi(argv[2]));
	printf("%lu\n", m);

	return (0);
}

