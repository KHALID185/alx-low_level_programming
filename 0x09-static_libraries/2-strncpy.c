#include "main.h"

/**
*_strncpy - a function that copies a string.
*@dest: pointer to string.
*@src: pointer to  string.
*@n:  bytes to be used.
*
* Return: pointer to destination string.
*/

char *_strncpy(char *dest, char *src, int n)
{
int Count;

for (Count = 0; Count < n && src[Count] != '\0'; Count++)
dest[Count] = src[Count];
for (; Count < n; Count++)
dest[Count] = '\0';

return (dest);
}
