#include <stdio.h>
#include <stdlib.h>

/**
 * main - a program that multiplies two numbers
 * @argc:int
 * @argv:string
 * Return: 0 success
*/

int main(int argc, char *argv[])
{
int add;
char *s;

while (--argc)
{
	for (s = argv[argc]; *s, s++)
		if (*s < '0' || *s > '9')
			return (printf("Error\n", 1));
	add += atoi(argv[argc]);
}

printf("%d\n", add);
return (0);
}
