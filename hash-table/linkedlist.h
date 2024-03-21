#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

typedef struct Node
{
    char *value;
    struct Node *next;
} Node;

Node *createList();
void insert(Node *head, char *value);
void deleteNode(Node *head, char *value);

#endif