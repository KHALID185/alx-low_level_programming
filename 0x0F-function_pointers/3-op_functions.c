#include "3-calc.h"

/**
 * op_add - addition of 2 numbers
 * @a: number 1 type integer
 * @b: number 2 type integer
 * Return: integer
*/
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - substraction of 2 numbers
 * @a: the first number int
 * @b: the second number int
 * Return: integer
*/
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiplication of two numbers
 * @a: number one
 * @b:number two
 * Return: integer
*/
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - division of number 1 and 2
 * @a: number 1
 * @b: number 2
 * Return: ineger
*/

int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a / b);
}

/**
 * op_mod - module of two number le rest of div
 * @a: integer
 * @b: integer
 * Return: resultat int
*/

int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}
