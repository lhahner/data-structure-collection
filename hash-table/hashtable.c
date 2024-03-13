/**
 * @author Lennart Hahner
 * @cite https://www.digitalocean.com/community/tutorials/hash-table-in-c-plus-plus
 * @copyright DigitalOcean
 */
#include <stdlib.h>
#include <stdio.h>
#define CAPACTIY 50000

// Defines the Hashtable item
typedef struct Ht_item
{
    char *key;
    char *value;
} Ht_item;

// Define the Hashtable
typedef struct HashTable
{
    Ht_item **items;
    int size;
    int count;
} HashTable;

Ht_item *create_item(char *key, char *value);

int main()
{
    printf("Hello");
}

// Weak Hash function
unsigned long hash_function(char *str)
{
    unsigned long i = 0;

    for (int j = 0; str[j]; j++)
    {
        i += str[j];
    }
    return i % CAPACTIY;
}

// Alloacte Memory for the item
Ht_item *create_item(char *key, char *value)
{
    Ht_item *item = (Ht_item *)malloc(sizeof(Ht_item));
    item->key = key;
    item->value = value;
    return item;
}

// Alloacte Memiry for the list
HashTable *create_Hashtable(int size)
{
    // Creates a new HashTable
    HashTable *table = (HashTable *)malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->items = (Ht_item **)calloc(table->size, sizeof(Ht_item *));

    for (int i = 0; table->size; i++)
    {
        table->items[i] = NULL;
    }

    return table;
}

// Freeing up memory is a C/C++ best practice. Free up memory that you’ve allocated on the heap with malloc() and calloc().
// free one item
int free_ht_item(Ht_item *item)
{
    if (item == NULL)
    {
        return 1;
    }
    else
    {
        free(item->key);
        free(item->value);
        free(item);
        return 0;
    }
}

// free entire Hashtable
int free_hashtable(HashTable *table)
{
    if (table == NULL)
    {
        return 1;
    }
    else
    {
        for (int i = 0; i < table->size; i++)
        {
            if (table->items[i] != NULL)
            {
                free(table->items[i]);
            }
        }
        free(table->items);
        free(table);
        return 0;
    }
}

// print the hashtable
void print_table(HashTable *table)
{
    for (int i = 0; i < table->size; i++)
    {
        if (table->items[i] != NULL)
        {
            printf("Index: %d, Items: %d", i, table->items[i]);
        }
    }
}

/**
 * @todo Collison handling in hashtable
 */
void handle_collision(HashTable *table, Ht_item *item)
{
}

// Insert function for Hashtable
int ht_insert(HashTable *table, char *key, char *value)
{
    if (table == NULL || key == NULL || value == NULL)
    {
        return 1;
    }
    Ht_item *item = create_item(key, value);
    int index = hash_function(key);

    Ht_item *current_item = table->items[index];

    if (current_item == NULL)
    {
        // Key does not exist.
        if (table->count == table->size)
        {
            // Hashtable is full
            printf("Insert Error");
            free_item(item);
            return;
        }
    }
    else
    {
        if (strcmp(current_item->key, key) == 0)
        {
            strcpy(table->items[index]->value, value);
            return;
        }
        else
        {
            handle_collision(table, item);
            return;
        }
    }
    table->items[index] = item;
    table->count++;
    return 0;
}

// Search in Hashtable
char *ht_search(HashTable *table, char *key)
{
    int index = hash_function(key);
    Ht_item *item = table->items[index];

    if (item != NULL)
    {
        if (strcmp(item->key, key) == 0)
        {
            return item->value;
        }
    }
    return NULL;
}

// print the requested search
void print_search(HashTable *table, char *key)
{
    char *val;

    if ((val = ht_search(table, key)) == NULL)
    {
        printf("Key:%s does not exist", key);
        return;
    }
    else
    {
        printf("Key:%s, Value:%s\n", key, val);
    }
}

/**
 * @todo: Create a Linked List for Chaining whenever a collison happens.
 ***/