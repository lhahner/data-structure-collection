#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

typedef struct Hashitem
{
    int key;
    char *value;

} Hashitem;

typedef struct Hashtable
{
    int size;
    Hashitem *list;

} Hashtable;

int hashfunction(char *str);
Hashtable *createHashtable(Hashtable *table, int size);

void main()
{
    Hashtable *table;
    createHashtable(table, 10);
}

/**
 * @todo ASCII Converter to avoid collison
 */
int hashfunction(char *str)
{
    int k = 0;
    for (int i = 0; i < sizeof(str); i++)
    {
        k = k + (int)str[i];
    }
    return k;
}

Hashtable *createHashtable(Hashtable *table, int size)
{
    table = malloc(sizeof(Hashtable *));
    table->size = size;
    table->list = calloc(0, size * sizeof(Hashitem));
    return table;
}

int freeHashtable()
{
}

Hashitem *insert()
{
}

Hashitem *delete()
{
}

/**
 * @todo print item list hashtable
 */
void printList(Hashitem *list)
{
    for (int i = 0; i < sizeof(list); i++)
    {
    }
}