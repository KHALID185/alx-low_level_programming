#include "hash_tables.h"

/**
 * shash_table_create - create a hash table ordred.
 * @size: size of hash table ordred.
 *
 * Return: a pointer to the new_node hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *h_t;
	unsigned long int j;

	h_t = malloc(sizeof(shash_table_t));
	if (h_t == NULL)
		return (NULL);

	h_t->size = size;
	h_t->array = malloc(sizeof(shash_node_t *) * size);
	if (h_t->array == NULL)
		return (NULL);
	for (j = 0; j < size; j++)
		h_t->array[j] = NULL;
	h_t->shead = NULL;
	h_t->stail = NULL;

	return (h_t);
}

/**
 * shash_table_set - set a new_node key-value in hash table
 * @ht: pointer to hash table
 * @key: the key
 * @value: value associate with the key
 * Return: integer
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *garage;
	char *vall;
	unsigned long int ndx;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	vall = strdup(value);
	if (vall == NULL)
		return (0);

	ndx = key_ndx((const unsigned char *)key, ht->size);
	garage = ht->shead;
	while (garage)
	{
		if (strcmp(garage->key, key) == 0)
		{
			free(garage->value);
			garage->value = vall;
			return (1);
		}
		garage = garage->snext;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
	{
		free(vall);
		return (0);
	}
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(vall);
		free(new_node);
		return (0);
	}
	new_node->value = vall;
	new_node->next = ht->array[ndx];
	ht->array[ndx] = new_node;

	if (ht->shead == NULL)
	{
		new_node->sprev = NULL;
		new_node->snext = NULL;
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new_node->sprev = NULL;
		new_node->snext = ht->shead;
		ht->shead->sprev = new_node;
		ht->shead = new_node;
	}
	else
	{
		garage = ht->shead;
		while (garage->snext != NULL && strcmp(garage->snext->key, key) < 0)
			garage = garage->snext;
		new_node->sprev = garage;
		new_node->snext = garage->snext;
		if (garage->snext == NULL)
			ht->stail = new_node;
		else
			garage->snext->sprev = new_node;
		garage->snext = new_node;
	}

	return (1);
}

/**
 * shash_table_get - Retrieve the value associated with
 *                   a key in a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 * @key: The key to get the value of.
 *
 * Return: If the key cannot be matched - NULL.
 *         Otherwise - the value associated with key in ht.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int ndx;

	if (!ht || !key || *key == '\0')
		return (NULL);

	ndx = key_ndx((const unsigned char *)key, ht->size);
	if (ndx >= ht->size)
		return (NULL);

	node = ht->shead;
	while (node != NULL && strcmp(node->key, key) != 0)
		node = node->snext;

	return ((node == NULL) ? NULL : node->value);
}

/**
 * shash_table_print - prints the hash tables elements
 * @ht: pointer to the hash table ordred
 * Return: empty
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *new_hash_node;

	if (!ht)
		return;

	new_hash_node = ht->shead;
	printf("{");
	while (new_hash_node != NULL)
	{
		printf("'%s': '%s'", new_hash_node->key, new_hash_node->value);
		new_hash_node = new_hash_node->snext;
		if (new_hash_node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - print the elements in hash table reversed
 * @ht: pointer to the hash table
 * Return: empty
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *new_hnode;

	if (!ht)
		return;

	new_hnode = ht->stail;
	printf("{");
	while (new_hnode != NULL)
	{
		printf("'%s': '%s'", new_hnode->key, new_hnode->value);
		new_hnode = new_hnode->sprev;
		if (new_hnode != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - delete a hash table
 * @ht: hash table
 * Return: empty
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *hd_hn = ht;
	shash_node_t *new_hnode, *garage;

	if (!ht)
		return;

	new_hnode = ht->shead;
	while (new_hnode)
	{
		garage = new_hnode->snext;
		free(new_hnode->key);
		free(new_hnode->value);
		free(new_hnode);
		new_hnode = garage;
	}

	free(hd_hn->array);
	free(hd_hn);
}
