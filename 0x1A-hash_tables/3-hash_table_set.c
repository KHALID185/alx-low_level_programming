#include "hash_tables.h"
/**
 * new_hnode - create new hash node
 * @ky: the key
 * @val: the value associate with the key
 * Return: the new node
*/

hash_node_t *new_hnode(const char *ky, const char *val)
{
	hash_node_t *new_nd;

	new_nd = malloc(1 * sizeof(hash_node_t));
	if (!new_nd)
		return (NULL);
	new_nd->key = strdup(ky);
	if (new_nd->key == NULL)
	{
		free(new_nd);
		return (NULL);
	}
	new_nd->value = strdup(val);
	if (new_nd->value == NULL)
	{
		free(new_nd->key);
		free(new_nd);
		return (NULL);
	}
	new_nd->next = NULL;
	return (new_nd);
}


/**
 * hash_table_set - set a hash node in hash table
 * @ht: hash table
 * @key: the key
 * @value: the value associate with the key
 * Return: integer
*/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int indx;
	hash_node_t *new_nd, *garage;
	char *vall;

	if (
		!ht || !key || !value || strlen(key) == 0 ||
		ht->array == NULL || ht->size == 0
	)
		return (0);
	indx = key_index((const unsigned char *)key, ht->size);
	garage = ht->array[indx];
	while (garage != NULL)
	{
		if (strcmp(garage->key, key) == 0)
		{
			vall = strdup(value);
			if (vall == NULL)
				return (0);
			free(garage->value);
			garage->value = vall;
			return (1);
		}
		garage = garage->next;
	}
	new_nd = new_hnode(key, value);
	if (!new_nd)
		return (0);
	new_nd->next = ht->array[indx];
	ht->array[indx] = new_nd;
	return (1);
}
