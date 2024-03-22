#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "linkedlist.h"
#include "rebuildHt.h"

int iterator = 0;

void main()
{
    Hashtable *table = createHashtable(5);
    insert(table, "Hello");
    insert(table, "Test");
    insert(table, "Adding");
    insert(table, "Multiple");
    insert(table, "Multiple");
    insert(table, "Adding");
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

Hashtable *createHashtable(int length)
{
    Hashtable *table = malloc(sizeof(Hashtable *));
    table->size = length;
    table->head = NULL;
    table->list = malloc(length * sizeof(Hashitem));
    printList(table->list);
    return table;
}

int freeHashtable()
{
}

void insert(Hashtable *table, char *value)
{
    
    if (get(table, hashfunction(value)) != NULL)
    {
        //creating linkedlist
        if(table->head == NULL){
            table->head = createList();
            insertNode(table->head, value);
        }
        else {
            insertNode(table->head, value);
        }
    }
    else
    {
        table->list[iterator].value = value;
        table->list[iterator].key = hashfunction(value);
        iterator++;
        return;
    }
}

char *get(Hashtable *table, int key)
{
    for (int i = 0; i < iterator; i++)
    {
        if (table->list[i].key == key)
            return table->list[i].value;
    }
    return NULL;
}

Hashitem *delete()
{
}

/**
 * @todo print item list hashtable
 */
void printList(Hashitem *list)
{
    for (int i = 0; i < iterator; i++)
    {
        if (list[i].value == NULL)
        {
            return;
        }
        printf("%d: %s \n", list[i].key, list[i].value);
    }
}