#include "hash_tables.h"

/**
 * shash_table_create - create a hash table ordred.
 * @size: size of hash table ordred.
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
 * new_shnode - a new node for the hash table sorted
 * @ky: the key
 * @val: data associate with the key
 * Return: a pointer to the new sh node
*/

shash_node_t *new_shnode(const char *ky, const char *val)
{
	shash_node_t *sh;

	sh = malloc(1 * sizeof(shash_node_t));
	if (!sh)
		return (NULL);
	sh->key = strdup(ky);
	if (sh->key == NULL)
	{
		free(sh);
		return (NULL);
	}
	sh->value = strdup(val);
	if (sh->value == NULL)
	{
		free(sh->key);
		free(sh);
		return (NULL);
	}
	sh->next = sh->snext = sh->sprev = NULL;
	return (sh);
}

/**
 * addnode - add node to linked list
 * @sh_table: sorted hash table
 * @nd: node
 * Return: empty
*/

void addnode(shash_table_t *sh_table, shash_node_t *nd)
{
	shash_node_t *garage;

	if (sh_table->shead == NULL && sh_table->stail == NULL)
	{
		sh_table->shead = sh_table->stail = nd;
		return;
	}
	garage = sh_table->shead;
	while (garage)
	{
		if (strcmp(nd->key, garage->key) < 0)
		{
			nd->snext = garage;
			nd->sprev = garage->sprev;
			garage->sprev = nd;
			if (nd->sprev)
				nd->sprev->snext = nd;
			else
				sh_table->shead = nd;
			return;
		}
		garage = garage->snext;
	}
	nd->sprev = sh_table->stail;
	sh_table->stail->snext = nd;
	sh_table->stail = nd;
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

	if (
		!ht || !key || ht->size == 0 || !value ||
		ht->array == NULL || strlen(key) == 0
	)
		return (0);

	ndx = key_index((const unsigned char *)key, ht->size);
	garage = ht->array[ndx];
	while (garage)
	{
		if (strcmp(garage->key, key) == 0)
		{
			vall = strdup(value);
			if (!vall)
				return (0);
			free(garage->value);
			garage->value = vall;
			return (1);
		}
		garage = garage->next;
	}

	new_node = new_shnode(key, value);
	if (new_node == NULL)
		return (0);
	new_node->next = ht->array[ndx];
	ht->array[ndx] = new_node;
	addnode(ht, new_node);
	return (1);
}

/**
 * shash_table_get - retrieve the value
 * @ht: hash table
 * @key: key to entre
 * Return: the value associate with key
*/
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *garage;
	unsigned long int ndx;

	if (
		!ht || !key || strlen(key) == 0 ||
		ht->array == NULL || ht->size == 0
	)
		return (NULL);

	ndx = key_index((const unsigned char *)key, ht->size);
	garage = ht->array[ndx];
	while (garage != NULL)
	{
		if (strcmp(garage->key, key) == 0)
			return (garage->value);
		garage = garage->next;
	}
	return (NULL);
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
