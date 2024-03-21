/**
 * @author Lennart Hahner
 * @date 21.03.2024
 */
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

/**
 * @todo the value of node should be defined in type Hashitem
 */

typedef struct Node
{
    char *value;
    struct Node *next;
} Node;

Node *createList();
void insert(Node *head, char *value);
void deleteNode(Node *head, char *value);

#endif