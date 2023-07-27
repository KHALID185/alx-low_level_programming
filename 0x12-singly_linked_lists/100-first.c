#include "lists.h"

void construct(void) __attribute__ ((constructor));

/**
 * construct - excute before main or any functions
 * Return: empty
*/

void construct(void)
{
printf("You're beat! and yet, you must allow,\n"
		"I bore my house upon my back!\n");
}
