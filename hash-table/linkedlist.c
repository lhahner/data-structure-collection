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

void deleteNode(Node *head, char *value)
{
    if (head->next->value == value)
    {
        head->next = head->next->next;
    }
    else
    {
        Node *tmp = head;
        while (tmp->next != NULL)
        {
            if (tmp->next->next->value == value)
            {
                tmp->next->next = tmp->next->next->next;
                return;
            }
            tmp = tmp->next;
        }
        return;
    }
}