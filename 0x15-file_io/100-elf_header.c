#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>


#define ER_NoELF "Error: Not an ELF file\n"
#define LE "2's complement, little endian\n"
#define BE "2's complement, big endian\n"
#define No "Error: `%s`: No such file\n"
#define ER_R "Error: Can't read file %s\n"
#define ER_C "Error: Can't close fd %d\n"

void ch_e(unsigned char *e_ident);
void p_m(unsigned char *e_ident);
void p_c(unsigned char *e_ident);
void p_d(unsigned char *e_ident);
void p_v(unsigned char *e_ident);
void p_a(unsigned char *e_ident);
void p_o(unsigned char *e_ident);
void p_t(unsigned int e_type, unsigned char *e_ident);
void p_e(unsigned long int e_entry, unsigned char *e_ident);
void c_e(int el);

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
 * p_v - prints the elf version hd
 * @e_ident: a pointer to an array countain the elf
 * Return: void
*/
void p_v(unsigned char *e_ident)
{
printf(" Version: %d", e_ident[EI_VERSION]);

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

/**
 * p_o - prints elf osabi hd
 * @e_ident: point to an array countain elf
 * Return: empty
 */
void p_o(unsigned char *e_ident)
{
printf(" OS/ABI: ");

switch (e_ident[EI_OSABI])
{
case ELFOSABI_NONE:
	printf("UNIX - System V\n");
	break;
case ELFOSABI_HPUX:
	printf("UNIX - HP-UX\n");
	break;
case ELFOSABI_NETBSD:
	printf("UNIX - NetBSD\n");
	break;
case ELFOSABI_LINUX:
	printf("UNIX - Linux\n");
	break;
case ELFOSABI_SOLARIS:
	printf("UNIX - Solaris\n");
	break;
case ELFOSABI_IRIX:
	printf("UNIX - IRIX\n");
	break;
case ELFOSABI_FREEBSD:
	printf("UNIX - FreeBSD\n");
	break;
case ELFOSABI_TRU64:
	printf("UNIX - TRU64\n");
	break;
case ELFOSABI_ARM:
	printf("ARM\n");
	break;
case ELFOSABI_STANDALONE:
	printf("Standalone App\n");
	break;
default:
	printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}
}

/**
 * p_a - prints the elf hd of abi version
 * @e_ident: array countain elf hd
 * Return: empty
 */
void p_a(unsigned char *e_ident)
{
printf(" ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * p_t - prints elf type
 * @e_type: type of elf hd
 * @e_ident: pointer to an string
 */
void p_t(unsigned int e_type, unsigned char *e_ident)
{
if (e_ident[EI_DATA] == ELFDATA2MSB)
e_type >>= 8;
printf(" Type: ");

switch (e_type)
{
case ET_NONE:
	printf("NONE (None)\n");
	break;
case ET_REL:
	printf("REL (Relocatable file)\n");
	break;
case ET_EXEC:
	printf("EXEC (Executable file)\n");
	break;
case ET_DYN:
	printf("DYN (Shared object file)\n");
	break;
case ET_CORE:
	printf("CORE (Core file)\n");
	break;
default:
	printf("<unknown: %x>\n", e_type);
}
}

/**
 * p_e - prints the elf hd of a entry pnt
 * @e_entry: the adress of this point
 * @e_ident: pointer to an array
 */
void p_e(unsigned long int e_entry, unsigned char *e_ident)
{
printf(" Entry point address: ");

if (e_ident[EI_DATA] == ELFDATA2MSB)
{
	e_entry = ((e_entry << 8) & 0xFF00FF00) |
	((e_entry >> 8) & 0xFF00FF);
	e_entry = (e_entry << 16) | (e_entry >> 16);
}

if (e_ident[EI_CLASS] == ELFCLASS32)
{
	printf("%#x\n", (unsigned int)e_entry);
}
else
{
	printf("%#lx\n", e_entry);
}
}
/**
 * c_e - close elf
 * @el: elf descriptor file
 *Return: void
 */
void c_e(int el)
{
if (close(el) == -1)
{
	dprintf(STDERR_FILENO, ER_C, el);
	exit(98);
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
