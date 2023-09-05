#include "shell.h"

/**
 * p_a - prints the elf hd of abi version
 * @e_ident: array countain elf hd
 * Return: empty
 */
void p_a(unsigned char *e_ident)
{
printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}
