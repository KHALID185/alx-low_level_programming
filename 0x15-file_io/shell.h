#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>

void ch_e(unsigned char *e_ident);
void p_m(unsigned char *e_ident);
void p_c(unsigned char *e_ident);
void p_d(unsigned char *e_ident);
void p_v(unsigned char *e_ident);
void p_a(unsigned char *e_ident);
void p_o(unsigned char *e_ident);
void p_typ(unsigned int e_type, unsigned char *e_ident);
void p_e(unsigned long int e_entry, unsigned char *e_ident);
void c_e(int elf);

#endif
