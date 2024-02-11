#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    int size;
    int head;
    int *array;
    int tail;


void init(int initsize){
    head = -1;
    tail = -1;
    size = initsize;
    array = malloc(sizeof(int)*size);
    memset(array, 0, sizeof(int)*size);
}

int enqueue(int x){
    if(size-1 == tail){
        size++;
        int *tmp = array;
        array = realloc(tmp, sizeof(array)*size);
    }
    tail++;
    array[tail] = x;
    return x;
}

/**
 * @TODO Dequeue and increase size of dynamic array
 * */
int dequeue(){
    if(size == 0){
        return 1;
    }
    head++;
    int *tmp = malloc(sizeof(array)*siize);
    for(int i = head+1;i<size;i++){
    	tmp[i] = array[i];
    }
    size--;
    array = realloc(tmp, sizeof(array)*size);
    return 0;
}

void printQueue(){
    for(int i = 0; i<size;i++){
        printf("%d, ", array[i]);
    }
}


void main(){
   init(4);
   enqueue(2);
   enqueue(3);
   enqueue(4);
   printf("first \n");
   printQueue();
   dequeue();
   printf("second \n");
   printQueue();
}
