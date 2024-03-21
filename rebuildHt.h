#ifndef REBUILDHT_H_
#define REBUILDHT_H_

int iterator = 0;

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
Hashtable *createHashtable(int length);
void printList(Hashitem *list);
void insert(Hashtable *table, char *value);
char *get(Hashtable *table, int key);

#endif