#includ "main.h"

/**
 * main - Entry pt
 *
 * Return: 0 success
*/

int main(void)
{
	int counteur;
	unsigned long s, fbc1 = 0, fbc2 = 1;

	for (counteur = 0; counteur < 50; counteur++)
	{
		s = fcb1 + fcb2;
		printf("%lu", s);

		fcb1 = fcb2;
		fcb2 = s;
		if (counteur == 49)
			printf("\n");
		else
			printf(", ");

	}
	return (0);
}
