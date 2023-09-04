#include "main.h"

#define U "Usage: cp file_from file_to\n"
#define ER_R "Error: Can't read from file %s\n"
#define ER_W "Error: Can't write to %s\n"
#define ER_C "Error: Can't close fd %d\n"

/**
 * new_buff - create buffer size=1024bytes
 * @f: the file name of the buffer
 * Return: pointer
 */
char *new_buff(char *f)
{
char *buff;

buff = malloc(sizeof(char) * R_B_S);

if (buff == NULL)
{
dprintf(STDERR_FILENO, ER_W, f);
exit(99);
}
return (buff);
}

/**
 * c_f - close descriptors files
 * @d_f: descriptor files
 * Return: void
 */
void c_f(int d_f)
{
int j;

j = close(d_f);
if (j == -1)
{
dprintf(STDERR_FILENO, ER_C, d_f);
exit(100);
}
}

/**
 * main - the entry fonction
 * @a_c: conteur of arguments
 * @a_v: vecteur of arguments
 * Return: int
 */
int main(int a_c, char *a_v[])
{
int f_fd, to_fd, rd, wrt;
char *buff;

if (a_c != 3)
{
dprintf(STDERR_FILENO, U);
exit(97);
}
buff = new_buff(a_v[2]);
f_fd = open(a_v[1], O_RDONLY);
rd = read(f_fd, buff, R_B_S);
to_fd = open(a_v[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);

do {
if (f_fd == -1 || rd == -1)
{
dprintf(STDERR_FILENO, ER_R, a_v[1]);
free(buff);
exit(98);
}

wrt = write(to_fd, buff, rd);
if (to_fd == -1 || wrt == -1)
{
dprintf(STDERR_FILENO, ER_W, a_v[2]);
free(buff);
exit(99);
}
rd = read(f_fd, buff, R_B_S);
to_fd = open(a_v[2], O_WRONLY | O_APPEND);

} while (rd > 0);

free(buff);
c_f(f_fd);
c_f(to_fd);

return (0);
}
