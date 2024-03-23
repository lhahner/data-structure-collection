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
    delete(table, "Adding");
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

/**
 * @todo create a reverse hash function to generate 
*/
char* reverseHashfunction(int key){
    return "Not implemented";
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

/**
 * @todo should free the memory of a selected hashitem.
*/
int freeHashitem(Hashitem* item)
{
  
    item->key = 0;
    item->value = 0;
    iterator--;
    return 0;
}

void insert(Hashtable *table, char *value)
{
    if (getValue(table, hashfunction(value)) != NULL)
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

char *getValue(Hashtable *table, int key)
{
    for (int i = 0; i < iterator; i++)
    {
        if (table->list[i].key == key)
            return table->list[i].value;
    }
    return NULL;
}

Hashitem* getItem(Hashtable *table, int key){
    for (int i = 0; i < iterator; i++)
    {
        if (table->list[i].key == key)
            return &(table->list[i]);
    }
    return NULL;
}

/**
 * @todo the delete function should delete the value from the
 * hashtable. 
 * Also should move a collision item from the linked list 
 * to the hashtable if the item was moved to linkedlist
 * when inserted.
*/
Hashitem *delete(Hashtable* table, char* value)
{
    Hashitem* itemToDelete = getItem(table, hashfunction(value));
    freeHashitem(itemToDelete);
    return itemToDelete;

}

/**
 * @todo should move the item from linkedlist to hashtable
*/
int moveToHashtable(Hashtable* table, Node* head, char* value){
    Node* node = deleteNode(head, value);
    insert(table, node->value);
    return 1;
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