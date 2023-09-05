#ifndef SHELL_H
#define SHELL_H

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

#endif
