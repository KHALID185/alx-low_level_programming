#include "function_pointers.h"
#include <stdio.h>

/**
 * main - Entry function
 * @argc: the numbers of elements
 * @argv: list
 * Return: 0 success
*/

int main(int argc, int **argv)
{
char *p_f = (char *)main;
int i;

if (argc != 2)
{
	printf("Error\n");
	exit(1);
}
i = atoi(argv[1]);
if (i < 0)
{
	printf("Error\n");
	exit(2);
}
while (i--)
	printf("%02hhx%s", *p_f++, i ? " " : "\n");
return (0);
}
