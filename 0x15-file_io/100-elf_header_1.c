#include "shell.h"

/**
 * ch_e - a function to check if its a file elf
 * @e_ident: a pointer to ann tab countain the elf num
 * Return: void
 */
void ch_e(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
		    e_ident[index] != 'E' &&
		    e_ident[index] != 'L' &&
		    e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * p_m - Prints the elf magic numbers
 * @e_ident: A pointer
 * Return: void
 */

void p_m(unsigned char *e_ident)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * p_c - prints elf f_hdr classes
 * @e_ident: pointer to an array
 * Return: empty
*/

void p_c(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * p_d - prints the elf data
 * @e_ident: a pointer
 * Return: void
 */

void p_d(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * p_v - prints the elf version hd
 * @e_ident: a pointer to an array countain the elf
 * Return: void
*/

void p_v(unsigned char *e_ident)
{
	printf("  Version:                           %d",
	       e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

