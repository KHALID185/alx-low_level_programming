#include "main.h"
#include <elf.h>

void p_o_m(Elf64_Ehdr hdr);

/**
 * p_m - print elf magic
 * @hdr: the elf header
 * Return: empty
*/
void p_m(Elf64_Ehdr hdr)
{
	int j;

	printf(" Magic:	");
	for (j = 0; j < EI_NIDENT; j++)
	{
		printf("%2.2x%s", hdr.e_ident[j], j == EI_NIDENT - 1 ? "\n" : " ");
	}
}

/**
 * p_c - print elf class
 * @hdr: the elf header
 * Return: empty
*/

void p_c(Elf64_Ehdr hdr)
{
	printf(" Class:				");
	switch (hdr.e_ident[EI_CLASS])
	{
		case ELFCLASS64:
				printf("ELF64");
		break;
		case ELFCLASS32:
				printf("ELF32");
		break;
		case ELFCLASSNONE:
				printf("none");
		break;
	}
	printf("\n");
}

/**
 * p_d - print elf data
 * @hdr: elf header
 * Return: empty
*/

void p_d(Elf64_Ehdr hdr)
{
printf(" Data:					");
switch (hdr.e_ident[EI_DATA])
{
	case ELFDATA2MSB:
		printf("2's complement, big endian");
	break;
	case ELFDATA2LSB:
		printf("2's complement, little endian");
	break;
	case ELFDATANONE:
		printf("none");
	break;
}
printf("\n");
}

/**
 * p_v - print elf version
 * @hdr: elf header
 * Return: empty
*/

void p_v(Elf64_Ehdr hdr)
{
printf(" Version:				%d", hdr.e_ident[EI_VERSION]);
switch (hdr.e_ident[EI_VERSION])
{
	case EV_CURRENT:
		printf(" (current)");
	break;
	case EV_NONE:
		printf("%s", "");
	break;
	break;
}
printf("\n");
}

/**
 * p_o - print elf OSABI
 * @hdr: elf header
 * Return: empty
*/

void p_o(Elf64_Ehdr hdr)
{
printf(" OS/ABI:				");
switch (hdr.e_ident[EI_OSABI])
{
	case ELFOSABI_NONE:
		printf("UNIX - System V");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - L inux");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris");
		break;
	case ELFOSABI_AIX:
		printf("UNIX - AIX");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64");
		break;
	default:
		p_o_m(hdr);
		break;
}
printf("\n");
}

/**
 * p_o_m - print more OSABI
 * @hdr: header elf
 * Return: empty
*/
void p_o_m(Elf64_Ehdr hdr)
{
switch (hdr.e_ident[EI_OSABI])
{

	case ELFOSABI_MODESTO:
		printf("Novell - Modesto");
		break;
	case ELFOSABI_OPENBSD:
		printf("UNIX - OpenBSD");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App");
		break;
	case ELFOSABI_ARM:
		printf("ARM");
		break;
	default:
		printf("<unknow: %x>", hdr.e_ident[EI_OSABI]);
		break;
}

}

/**
 * p_a - print elf abi version
 * @hdr: elf header
 * Return: empty
*/

void p_a(Elf64_Ehdr hdr)
{
	printf(" ABI Version:				%d\n", hdr.e_ident[EI_ABIVERSION]);
}

/**
 * p_t - print elf type
 * @hdr: elf header
 * Return: empty
*/

void p_t(Elf64_Ehdr hdr)
{
	char *ptr = (char *)&hdr.e_type;
	int j = 0;

	printf(" Type:					");
	if (hdr.e_ident[EI_DATA] == ELFDATA2MSB)
		j = 1;
	switch (ptr[j])
	{
		case ET_NONE:
			printf("NONE (None)");
			break;
		case ET_REL:
			printf("REL (Relocatable file)");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)");
			break;
		case ET_CORE:
			printf("CORE (Core file)");
			break;
		default:
			printf("<unknown>: %x", ptr[j]);
		break;

	}
	printf("\n");
}

/**
 * p_e - printf elf entry
 * @hdr: header elf
 * Return: empty
*/

void p_e(Elf64_Ehdr hdr)
{
	int j = 0, l = 0;
	unsigned char *ptr = (unsigned char *)&hdr.e_entry;

	printf(" Entry point address:			0x");
	if (hdr.e_ident[EI_DATA] != ELFDATA2MSB)
	{
		j = hdr.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!ptr[j])
			j--;
		printf("%x", ptr[j--]);
		for (; j >= 0; j--)
			printf("%02x", ptr[j]);
		printf("\n");
	}
	else
	{
		j = 0;
		l = hdr.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!ptr[j])
			j++;
		printf("%x", ptr[j++]);
		for (; j <= l; j++)
			printf("%02x", ptr[j]);
		printf("\n");
	}
}

/**
 * main - entry function
 * @ac: arg counteur
 * @av: arg vector
 * Return: 1 success
*/
int main(int ac, char **av)
{
	int f;
	Elf64_Ehdr hdr;
	ssize_t byt;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}
	f = open(av[1], O_RDONLY);
	if (f == -1)
	{
		dprintf(STDERR_FILENO, "Cant't open file: %s\n", av[1]);
		exit(98);
	}
	byt = read(f, &hdr, sizeof(hdr));
	if (byt < 1 || byt != sizeof(hdr))
	{
		dprintf(STDERR_FILENO, "Can't read from file: %s\n", av[1]);
		exit(98);
	}
	if (hdr.e_ident[0] == 0x7f && hdr.e_ident[1] == 'E'
		&& hdr.e_ident[2] == 'L' && hdr.e_ident[3] == 'F')
	{
		printf("ELF Header:\n");
	}
	else
	{
		dprintf(STDERR_FILENO, "Not ELF file: %s\n", av[1]);
		exit(98);
	}

	p_m(hdr);
	p_c(hdr);
	p_d(hdr);
	p_v(hdr);
	p_o(hdr);
	p_a(hdr);
	p_t(hdr);
	p_e(hdr);
	if (close(f))
	{
		dprintf(STDERR_FILENO, "Error closing file descriptor: %d\n", f);
		exit(98);
	}
	return (EXIT_SUCCESS);
}
