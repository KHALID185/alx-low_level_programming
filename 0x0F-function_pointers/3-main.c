#include "3-calc.h"

/**
 * main - Entry function
 * @argc: the nmbr of args
 * @argv: list arg
 * Return: 0 success
*/

int main(int argc, char **argv)
{
	int (*p)(int, int), a, b;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	a = atoi(argv[1]);
	b = atoi(argv[3]);
	(p) = get_op_func(argv[2]);
	if (p != NULL)
	{
		printf("Error\n");
		exit(99);
	}
	printf("%d\n", p(a, b));
	return (0);
}
