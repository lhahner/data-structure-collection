#include <stdio.h>
#include <stdlib.h>


struct node {
    int value;
    struct node *next;
};

void printLinkedList(struct node *p){
    while(p != NULL){
    printf("%d",p->value);
    p = p->next;
    }
}

/**
 * @params Value you want to add and the head of the list
 * Addas a new value to the linked list.
 * **/
void push(int value, struct node *head){

    struct node *current = head;

    while(current->next != NULL){
        current = current->next;
    }

    current->next = malloc(sizeof(struct node));
    current->next->value = value;
    current->next->next = NULL;
}

/**
 * Deletes a value from the list.
 * */
int pop(struct node **head){
	struct node *tmp = NULL;
	if((*head) == NULL){
		return -1;
	}
	tmp = (*head)->next;
	free(*head);
	*head = tmp;

	return 1;
}

void main()
{
    struct node *head;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;

    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));

    one->value = 1;
    two->value = 2;
    three->value = 3;

    one->next = two;
    two->next = three;
    three->next = NULL;

    head = one;

    push(5, head);
    printLinkedList(head);
    printf("Popping: \n");
    pop(&head);
    printLinkedList(head);
}


