#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    char *value;
    struct Node *next;
} Node;

Node *createList();
void insert(Node *head, char *value);
char *delete();

void main()
{
    Node *head = createList();
    insert(head, "Lol");
    insert(head, "Dota");
}

Node *createList()
{
    Node *node = malloc(sizeof(Node *));
    node->next = NULL;
    return node;
}

void insert(Node *head, char *value)
{
    Node *node = head;
    while (node->next != NULL)
    {
        node = node->next;
    }
    node->next = malloc(sizeof(Node *));
    node->next->value = value;
    node->next->next = NULL;
    return;
}

void delete()
{
}