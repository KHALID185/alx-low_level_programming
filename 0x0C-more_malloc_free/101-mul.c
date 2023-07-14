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

	return (signe * res);
}

/**
 * p_i - print numbers
 * @num: nmber
 * Return: empty
*/
void p_i(unsigned long int num)
{
	unsigned long int div = 1, j, res;

	for (j = 0; num / div > 9; j++, div *= 10)
	;
	for (; div >= 1; num %= div, div /= 10)
	{
		res = num / div;
		_putchar('0' + res);
	}
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
	m = stoi(argv[1]) * stoi(argv[2]);
	printf("%lu\n", m);

	return (0);
}

