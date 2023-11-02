#include "hash_tables.h"

/**
 * hash_table_get - get a value by entre the key
 * @ht: a pointer to the hash table
 * @key: the key
 * Return: the value assosiate with the key
*/

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *garage;
	unsigned long int indx;

	if (
		!ht || !key || ht->array == NULL ||
		strlen(key) == 0 || ht->size == 0
	)
		return (NULL);
	indx = key_index((const unsigned char *)key, ht->size);
	garage = ht->array[indx];
	while (garage)
	{
		if (strcmp(garage->key, key) == 0)
			return (garage->value);
		garage = garage->next;
	}
	return (NULL);
}
