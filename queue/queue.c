#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**************************************************
 * 
 * Dynamic Queue:
 * Size is generated dynamically by the added values.
 * The items will be dequeued at the beginning.
 * The items will be enqueued at the end.
 *
 * ***********************************************/
    int size;
    int head;
    int *array;
    int tail;


void init(){
    head = -1;
    tail = -1;
    size = 0;
}

int enqueue(int x){
    if(size == 0){
	size++;
	tail++;
    	array = malloc(size);
	array[tail] = x;
	return x;
    }
    else {
        size++;
	tail++;
        int *tmp = array;
        array = realloc(tmp, size);
	array[tail] = x;
	return x;
    }
}

int dequeue(){
    if(size == 0){
        return 1;
    }
   size--;
   tail--;
   int *tmp = malloc(size);
   for(int i = 0;i<size;i++){		 
	if(array[i+1] == 0){
	   break;
	}
	   tmp[i] = array[i+1];
   }
   array = realloc(tmp, size);
   return 0;
}

void printQueue(){
    for(int i = 0; i<size;i++){
        printf("%d, ", array[i]);
    }
}


void main(){
   init();
   enqueue(2);
   enqueue(3);
   enqueue(4);
   printf("first \n");
   printQueue();
   dequeue();
   enqueue(2);
   dequeue();
   printf("second \n");
   printQueue();
}
