#include "shell.h"

/**
 * ch_e - a function to check if its a file elf
 * @e_ident: a pointer to ann tab countain the elf num
 * Return: void
 */
void ch_e(unsigned char *e_ident)
{
	int k;

	for (k = 0; k < 4; k++)
	{
		if (e_ident[k] != 127 &&
		    e_ident[k] != 'E' &&
		    e_ident[k] != 'L' &&
		    e_ident[k] != 'F')
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
	int j;

	printf("  Magic:   ");

	for (j = 0; j < EI_NIDENT; j++)
	{
		printf("%02x", e_ident[j]);

		if (j == EI_NIDENT - 1)
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

/**
 * p_o - prints elf osabi hd
 * @e_ident: point to an array countain elf
 * Return: empty
 */

void p_o(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

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
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * p_typ - prints elf type
 * @e_type: type of elf hd
 * @e_ident: pointer to an string
 * Return: empty
 */

void p_typ(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

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
 * Return: empty
 */

void p_e(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * c_e - close elf
 * @E_L: elf descriptor file
 *Return: void
 */

void c_e(int E_L)
{
	if (close(E_L) == -1)
	{
		dprintf(STDERR_FILENO,
			ER_C, E_L);
		exit(98);
	}
}

/**
 * main - entry function
 * @a_c: counter of arguments
 * @a_v: vecteur of arguments pointer
 * Return: o success
 */

int main(int __attribute__((__unused__)) a_c, char *a_v[])
{
	Elf64_Ehdr *header;
	int d_f, lect;

	d_f = open(a_v[1], O_RDONLY);
	if (d_f == -1)
	{
		dprintf(STDERR_FILENO, ER_R, a_v[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		c_e(d_f);
		dprintf(STDERR_FILENO, ER_R, a_v[1]);
		exit(98);
	}
	lect = read(d_f, header, sizeof(Elf64_Ehdr));
	if (lect == -1)
	{
		free(header);
		c_e(d_f);
		dprintf(STDERR_FILENO, ER_N, a_v[1]);
		exit(98);
	}

	ch_e(header->e_ident);
	printf("ELF Header:\n");
	p_m(header->e_ident);
	p_c(header->e_ident);
	p_d(header->e_ident);
	p_v(header->e_ident);
	p_o(header->e_ident);
	p_a(header->e_ident);
	p_typ(header->e_type, header->e_ident);
	p_e(header->e_entry, header->e_ident);

	free(header);
	c_e(d_f);
	return (0);
}
