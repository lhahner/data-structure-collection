/**
 * @author https://www.digitalocean.com/community/tutorials/min-heap-binary-tree
*/

#include <stdlib.h>
#include <stdio.h>
#define SIZE 10

int* heapify(int* list);
void swap(int* a, int* b);

int main(){
    int* array = calloc(SIZE, sizeof(int));

    return 1;
}

void swap(int* a, int* b){
    int tmp = a;
    *a = *b;
    *b = tmp;
}

int* heapify(int* list, int i){

    int smallest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l < SIZE && list[l] < list[smallest]){
        smallest = l;
    }
    else if(r < SIZE && list[r] < list[smallest]){
        smallest = r;
    }

    if(smallest != i){
        
    }
    return list;
}
