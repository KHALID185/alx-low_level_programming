#include <stdio.h>
/**
 * main - Entry point
 *
 * Description:  prints all single digit numbers of base (10) starting from (0)
 *
 * Return: 0 (success)
*/
int main(void)
{
	int num = 0;

	while (num <= 9)
	{
		printf("%d", num);
		num++;
	}
	printf("\n");
	return (0);

}
