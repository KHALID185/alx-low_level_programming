#include "shell.h"
#include "100-elf_header_1.c"
#include "100-elf_header_2.c"
/**
 * ch_e - a function to check if its a file elf
 * @e_ident: a pointer to ann tab countain the elf num
 * Return: void
 */
void ch_e(unsigned char *e_ident)
{
int indx;

for (indx = 0; indx < 4; indx++)
{
	if (e_ident[indx] != 127 && e_ident[indx] != 'E' &&
	e_ident[indx] != 'L' && e_ident[indx] != 'F')
	{
		dprintf(STDERR_FILENO, ER_NoELF);
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
int indx;

printf(" Magic: ");

for (indx = 0; indx < EI_NIDENT; indx++)
{
	printf("%02x", e_ident[indx]);
	if (indx == EI_NIDENT - 1)
	{
		printf("\n");
	}
	else
	{
		printf(" ");
	}
}
}

/**
 * p_c - prints elf header classes
 * @e_ident: pointer to an array
 * Return: empty
*/

void p_c(unsigned char *e_ident)
{
printf(" Class: ");

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
printf(" Data: ");

switch (e_ident[EI_DATA])
{
case ELFDATANONE:
	printf("none\n");
	break;
case ELFDATA2LSB:
	printf(LE);
	break;
case ELFDATA2MSB:
	printf(BE);
	break;
default:
	printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}

/**
 * main - entry function
 * @a_c: counter of arguments
 * @a_v: vecteur of arguments
 * Return: o success
 */

int main(int __attribute__((__unused__)) a_c, char *a_v[])
{
Elf64_Ehdr *hd;
int d_f, rd;

d_f = open(a_v[1], O_RDONLY);
if (d_f == -1)
{
	dprintf(STDERR_FILENO, ER_R, a_v[1]);
	exit(98);
}
hd = malloc(sizeof(Elf64_Ehdr));
if (hd == NULL)
{
	c_e(d_f);
	dprintf(STDERR_FILENO, ER_R, a_v[1]);
	exit(98);
}
rd = read(d_f, hd, sizeof(Elf64_Ehdr));
if (rd == -1)
{
	free(hd);
	c_e(d_f);
	dprintf(STDERR_FILENO, No, a_v[1]);
	exit(98);
}

	ch_e(hd->e_ident);
	printf("ELF header:\n");
	p_m(hd->e_ident);
	p_c(hd->e_ident);
	p_d(hd->e_ident);
	p_v(hd->e_ident);
	p_o(hd->e_ident);
	p_a(hd->e_ident);
	p_t(hd->e_type, hd->e_ident);
	p_e(hd->e_entry, hd->e_ident);
	free(hd);
	c_e(d_f);
return (0);
}
