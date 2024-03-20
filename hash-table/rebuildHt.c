#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

int size = 0;

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
Hashtable *createHashtable(Hashtable *table);
void printList(Hashitem *list);
Hashitem *insert(Hashtable *table, char *value);

void main()
{
    Hashtable *table;
    table = insert(table, "Hello");
    printList(table->list);
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

Hashtable *createHashtable(Hashtable *table)
{
    table = malloc(sizeof(Hashtable *));
    table->size = size;
    table->list = malloc(size * sizeof(Hashitem));
    printList(table->list);
    return table;
}

int freeHashtable()
{
}

Hashitem *insert(Hashtable *table, char *value)
{
    if (table == NULL)
    {
        size++;
        table = createHashtable(table);
        table->list[0].value = value;
        table->list[0].key = hashfunction(value);
        return table;
    }
    else
    {
        int i = 0;
        while (i < size)
        {
            if (table->list[i].value != NULL)
            {
                i++;
            }
            else
            {
                table->list[i].value = value;
                table->list[i].key = hashfunction(value);
                return table;
            }
        }
    }
}

Hashitem *delete()
{
}

/**
 * @todo print item list hashtable
 */
void printList(Hashitem *list)
{
    for (int i = 0; i < size; i++)
    {
        if (list[i].value == NULL)
        {
            return;
        }
        printf("%d: %s \n", list[i].key, list[i].value);
    }
}