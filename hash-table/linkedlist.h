/**
 * @author Lennart Hahner
 * @date 21.03.2024
 */
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "rebuildHt.h"

typedef struct Node
{
    char* value;
    struct Node *next;
} Node;

Node *createList();
void initInsert(char* value);
void insertNode(Node *head, char *value);
void deleteNode(Node *head, char *value);

#endif