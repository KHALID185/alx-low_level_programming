#include "hash_tables.h"

/**
 * hash_table_print - print a hash table
 * @ht: a hash table
 * Return: empty
*/

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *garage;
	unsigned long int j;
	char no_data;

	if (!ht || ht->array == NULL)
		return;
	printf("{");
	for (j = 0; j < ht->size; j++)
	{
		garage = ht->array[j];
		while (garage)
		{
			if (no_data == 1)
				printf(", ");
			printf("'%s': '%s'", garage->key, garage->value);
			no_data = 1;
			garage = garage->next;
		}
	}
	printf("}\n");
}
