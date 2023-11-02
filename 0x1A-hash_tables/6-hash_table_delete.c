#include "hash_tables.h"

/**
 * hash_table_delete - function to delete a hash table
 * @ht: a hash table
 * Return: empty
*/

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *suivent;
	unsigned long int k;

	if (!ht || ht->array == NULL || ht->size == 0)
		return;
	for (k = 0; k < ht->size; k++)
	{
		while (ht->array[k] != NULL)
		{
			suivent = ht->array[k]->next;
			free(ht->array[k]->key);
			free(ht->array[k]->value);
			free(ht->array[k]);
			ht->array[k] = suivent;
		}
	}
	free(ht->array);
	ht->array = NULL;
	ht->size = 0;
	free(ht);
}
