#ifndef REBUILDHT_H_
#define REBUILDHT_H_

#include "./linkedlist.h"

typedef struct Hashitem
{
    int key;
    char *value;

} Hashitem;

typedef struct Hashtable
{
    int size;
    struct Node* head;
    Hashitem *list;

} Hashtable;

int hashfunction(char *str);
Hashtable *createHashtable(int length);
void printList(Hashitem *list);
void insert(Hashtable *table, char *value);
char *get(Hashtable *table, int key);

#endif