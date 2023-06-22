#include "main.h"

/**
 * main - prints 0 to 100
 * mult of 3 Fizz
 * mult of 5 Buzz
 * mult of 15 FizzBuzz
 *
 * Return: 0 success
*/

int main(void)
{
	int n;

	for (n = 0; n < 101; n++)
	{
		if (n % 3 == 0 && !(n % 5 == 0))
			printf("Fizz");
		else if (n % 5 == 0 && !(n % 3 == 0))
			printf("Buzz");
		else if (n % 5 == 0 && (n % 3 == 0))
			printf("FizzBuzz");
		else
			printf("%d", n);
		if (n != 100)
			printf(" ");
		else
			printf("\n");
	}

	return (0);
}
