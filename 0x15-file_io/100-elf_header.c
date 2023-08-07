#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ch_elf(unsigned char *e_ident);
void p_nm(unsigned char *e_ident);
void p_c(unsigned char *e_ident);
void p_data(unsigned char *e_ident);
void p_v(unsigned char *e_ident);
void p_ab(unsigned char *e_ident);
void p_o(unsigned char *e_ident);
void p_t(unsigned int e_type, unsigned char *e_ident);
void p_ent(unsigned long int e_entry, unsigned char *e_ident);
void c_elf(int elf);


/**
 * ch_elf - Check if a file is an ELF file.
 * @e_ident: a pointer countain elf num
 * Return: empty
 */
void ch_elf(unsigned char *e_ident)
{
int i;

for (i = 0; i < 4; i++)
{
if (e_ident[i] != 127 && e_ident[i] != 'E' && e_ident[i] != 'L' && e_ident[i] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}

/**
 * p_nm - Prints the magic num
 * @e_ident: a pointer countain elf num
 * Return: Empty
 */
void p_nm(unsigned char *e_ident)
{
int i;

printf(" Magic: ");
for (i = 0; i < EI_NIDENT; i++)
{
printf("%02x", e_ident[i]);
if (i == EI_NIDENT - 1)
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
 * p_c - afficher classe of elf
 * @e_ident: a pointer countain elf num
 * Return: Empty
 */
void p_c(unsigned char *e_ident)
{
printf(" Class: ");
switch (e_ident[EI_CLASS])
{
case ELFCLASSNONE:
{
printf("none\n");
break;
}
case ELFCLASS32:
{
printf("ELF32\n");
break;
}
case ELFCLASS64:
{
printf("ELF64\n");
break;
}
default:
{
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}
}

/**
 * p_data - Print data
 * @e_ident: A pointer to an array containing the ELF class.
 * Return: empty
 */
void p_data(unsigned char *e_ident)
{
printf(" Data: ");
switch (e_ident[EI_DATA])
{
case ELFDATANONE:
{
printf("none\n");
break;
}
case ELFDATA2LSB:
{
printf("2's complement, little endian\n");
break;
}
case ELFDATA2MSB:
{
printf("2's complement, big endian\n");
break;
}
default:
{
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
}
}

/**
 * p_v - Print version
 * @e_ident: a pointer countain elf num
 * Return: Empty
 */
void p_v(unsigned char *e_ident)
{
printf(" Version: %d", e_ident[EI_VERSION]);
switch (e_ident[EI_VERSION])
{
case EV_CURRENT:
{
printf(" (current)\n");
break;
}
default:
{
printf("\n");
break;
}
}
}

/**
 * p_o - Prints the OS_ABI.
 * @e_ident: A pointer to an array containing the ELF version.
 * Return: empty
 */
void p_o(unsigned char *e_ident)
{
printf(" OS/ABI: ");
switch (e_ident[EI_OSABI])
{
case ELFOSABI_NONE:
{
printf("UNIX - System V\n");
break;
}
case ELFOSABI_HPUX:
{
printf("UNIX - HP-UX\n");
break;
}
case ELFOSABI_NETBSD:
{
printf("UNIX - NetBSD\n");
break;
}
case ELFOSABI_LINUX:
{
printf("UNIX - Linux\n");
break;
}
case ELFOSABI_SOLARIS:
{
printf("UNIX - Solaris\n");
break;
}
case ELFOSABI_IRIX:
{
printf("UNIX - IRIX\n");
break;
}
case ELFOSABI_FREEBSD:
{
printf("UNIX - FreeBSD\n");
break;
}
case ELFOSABI_TRU64:
{
printf("UNIX - TRU64\n");
break;
}
case ELFOSABI_ARM:
{
printf("ARM\n");
break;
}
case ELFOSABI_STANDALONE:
{
printf("Standalone App\n");
break;
}
default:
{
printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}
}
}

/**
 * p_ab - Prints the ABI
 * @e_ident: A pointer to ELF
 * Return: empty
 */
void p_ab(unsigned char *e_ident)
{
printf(" ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * p_t - Prints the
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void p_t(unsigned int e_type, unsigned char *e_ident)
{
if (e_ident[EI_DATA] == ELFDATA2MSB)
e_type >>= 8;

printf(" Type: ");

switch (e_type)
{
case ET_NONE:
{
printf("NONE (None)\n");
break;
}
case ET_REL:
{
printf("REL (Relocatable file)\n");
break;
}
case ET_EXEC:
{
printf("EXEC (Executable file)\n");
break;
}
case ET_DYN:
{
printf("DYN (Shared object file)\n");
break;
}
case ET_CORE:
{
printf("CORE (Core file)\n");
break;
}
default:
{
printf("<unknown: %x>\n", e_type);
}
}
}

/**
 * p_ent - Print entry
 * @e_entry: integer
 * @e_ident: A pointer to an array containing the ELF class.
 * Return: empty
 */

void p_ent(unsigned long int e_entry, unsigned char *e_ident)
{
printf(" Entry point address: ");

if (e_ident[EI_DATA] == ELFDATA2MSB)
{
e_entry = ((e_entry << 8) & 0xFF00FF00) | ((e_entry >> 8) & 0xFF00FF);
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
 * c_elf - Closes an ELF
 * @elf: The file of the ELF file.
 *Return: empty
 */
void c_elf(int elf)
{
if (close(elf) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
exit(98);
}
}

/**
 * main - Entry function
 * @argc: The number of arg
 * @argv: An array of pointers to arg
 * Return: 0 success
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
Elf64_Ehdr *h;
int i, j;

i = open(argv[1], O_RDONLY);
if (i == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
h = malloc(sizeof(Elf64_Ehdr));
if (h == NULL)
{
c_elf(i);
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
j = read(i, h, sizeof(Elf64_Ehdr));
if (j == -1)
{
free(h);
c_elf(i);
dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
exit(98);
}

ch_elf(h->e_ident);
printf("ELF Header:\n");
p_nm(h->e_ident);
p_c(h->e_ident);
p_data(h->e_ident);
p_v(h->e_ident);
p_o(h->e_ident);
p_ab(h->e_ident);
p_t(h->e_type, h->e_ident);
p_ent(h->e_entry, h->e_ident);

free(h);
c_elf(i);
return (0);
}
