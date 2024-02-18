#include <stdlib.h>
#include <stdio.h>

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

struct Node* head = NULL;

//display list
void printList(struct Node* node);

//Add Items
void insert(int data);
void addFirst(int data);
void addAfter(struct Node* prevNode, int data);

int main ()
{
  insert(5);
  insert(3);
  printList(head);
  return 0;
}

void insert(int data){
    if(head == NULL){
        addFirst(data);
    }
    else{
        addAfter(head, data);
    }
}

/**
*@Summary You can dereference a pointer from *pointer to (*nonpointer)
*/
void addFirst(int data){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;

    if(head != NULL){
        head->prev = newNode;
    }
    head = newNode;
}

void addAfter(struct Node* prevNode, int data){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;

    //prev -> newNode -> prevnext
    if(newNode->next != NULL){
        newNode->next->prev = newNode;

    }
}

void printList(struct Node* node) {
    struct Node* last;

  while (node != NULL) {
    printf("%d->", node->data);
    last = node;
    node = node->next;
  }
  if (node == NULL)
    printf("NULL\n");
}
