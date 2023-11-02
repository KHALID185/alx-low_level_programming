#include "hash_tables.h"

/**
 * key_index - a function that give you index for the key
 * @key: key
 * @size: size of array
 * Return: an integer
*/

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
