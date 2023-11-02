#include "hash_tables.h"

/**
 * hash_table_create - function to create a hash table
 * @size: size of the array in hash table
 * Return: pointer to the hash table created
*/

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_hash_table;
	unsigned long int j;

	new_hash_table = malloc(1 * sizeof(hash_table_t));
	if (!new_hash_table)
		return (NULL);
	new_hash_table->size = size;
	new_hash_table->array = malloc(size * sizeof(hash_node_t *));
	if (new_hash_table->array == NULL)
	{
		free(new_hash_table);
		return (NULL);
	}
	for (j = 0; j < size; j++)
		new_hash_table->array[j] = NULL;
	return (new_hash_table);
}
