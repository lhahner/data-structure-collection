#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int top = -1;
int *stack;

/**
 * Call first and initalize size of the list
 * */
void createQueue(int size){
	stack = malloc(sizeof(int)*size);
	memset(stack,0, sizeof(int)*size); 
}

/**
 * Add a new Value on the stack
 * */
int push(int x, int size){
	if(top == size-1){
		return 1;
	}
	top = top +1;
	stack[top] = x;
	return x;
}

/**
 * Remove one from the list
 * */
int pop(){
	if(top == -1){
		return 1;
	}
	int deleted = stack[top];
	stack[top] = 0;
	top = top - 1;
	return deleted;
}

/**
 * Print the whole stack, size required
 * */
void printStack(int size){
	printf("[");
	for(int i = 0; i<size; i++){
		printf("%d,", stack[i]);
	}
	printf("]\n");
}

void main(){
	int size = 10;
	createQueue(size);
	push(2, size);
	push(4, size);
	push(5, size);
	printStack(size);
	pop();
	push(3, size);
	printStack(size);

}
