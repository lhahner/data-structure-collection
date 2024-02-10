#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

    int top = -1;
    int *content;
    int size;

/**
 * Call first and initalize size of the list
 * */
void init(int initsize){
    size = initsize;
	content = malloc(sizeof(int)*size);
	memset(content,0, sizeof(int)*size);
}

/**
 * Add a new Value on the stack
 * */
int push(int x){

	if(top == size-1){
		return 1;
	}
	top = top +1;
	content[top] = x;
	return x;
}

/**
 * Remove one from the list
 * */
int pop(){
	if(top == -1){
		return 1;
	}
	int deleted = content[top];
	content[top] = 0;
	top = top - 1;
	return deleted;
}

/**
 * Print the whole stack, size required
 * */
void printStack(){
	printf("[");
	for(int i = 0; i<size; i++){
		printf("%d,", content[i]);
	}
	printf("]\n");
}

void main(){
	init(5);
	push(2);

	printStack(size);
}
