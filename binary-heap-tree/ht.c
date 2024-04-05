/**
 * @author https://www.digitalocean.com/community/tutorials/min-heap-binary-tree
 */

#include <stdlib.h>
#include <stdio.h>
#include "ht.h"

int size = 10;

int main()
{
    int *list = malloc(size * sizeof(int));
    insert(list, 2);
    insert(list, 3);
    insert(list, 1);
    insert(list, 5);
    printList(list);
    return 1;
}

void swap(int *a, int *b)
{
    int tmp = a;
    *a = *b;
    *b = tmp;
}

int *heapify(int *list, int i)
{

    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && list[l] < list[smallest])
    {
        smallest = l;
    }
    else if (r < size && list[r] < list[smallest])
    {
        smallest = r;
    }

    if (smallest != i)
    {
    }
    return list;
}

void insert(int *list, int newNode)
{
    int currentSize = sizeof(list);
    if (list == NULL)
    {
        list = malloc(size * sizeof(int *));
        list[0] = newNode;
    }
    else if (currentSize == size)
    {
        list = realloc(list, currentSize++);
        list[currentSize] = newNode;
        heapify(list, 0);
    }
    else
    {
        for (int i = 0; i < currentSize; i++)
        {
            if (list[i] == NULL)
            {
                list[i] = newNode;
                heapify(list, i);
                return;
            }
        }
    }
}

void printList(int *list)
{
    for (int i = 0; i < sizeof(list); i++)
    {
        printf("%d: %d \n", i, list[i]);
    }
}
