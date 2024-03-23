/**
 * @author Lennart Hahner
 * @date 21.03.2024
 */
#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"
#include "rebuildHt.h"

Node *createList()
{
    Node *node = malloc(sizeof(Node *));
    node->next = NULL;
    return node;
}

void insertNode(Node *head, char *value)
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

Node* deleteNode(Node *head, char *value)
{
    Node* delNode;
    if (head->next->value == value)
    {
        delNode = head->next;
        head->next = head->next->next;
    }
    else
    {
        Node *tmp = head;
        while (tmp->next != NULL)
        {
            if (tmp->next->next->value == value)
            {
                delNode = tmp->next->next;
                tmp->next->next = tmp->next->next->next;
                return delNode;
            }
            tmp = tmp->next;
        }
        return delNode;
    }
}