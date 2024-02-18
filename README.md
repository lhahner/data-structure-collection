# data-structure-collection
This is a personal collection to learn about data structure and how to implement it in C.

## Currently possible to use
| Data Strucutre | Functionality    |
| -------------- | ---------------- |
| Linked List (not dynamic)    | add, delete      |
| Stack (not dynamic)          | push, pop        |
| Queue          | enqueue, dequeue |

## Purpose
I want to create my own code-base for Projects in the future.
Also I want to learn more about stoarge allocation and pointers to get more knowledge about low-level programming lanugages

## DS Cookbook
### How to cook a linked list
1. struct with value and next, next as type struct.
2. insert
   1. Iterate until next is null and set values by parameter.
  
### How to cook a stack
1. array, tail and size value
2. insert
  1. increase tail and insert in array at position of tail

### How to cook a Queue
#### Blueprint
`int size, tail, head;
 int* content;`

 `void insert(int data);
  void delelte();`

#### Insert functionality
First increase the variable that stores the size of the list.
Then increse the variable that stores the tail of the Queue.
Safe the current content in a temporally allocated variable.
Now Reallocate the Array that stores the content with the temporally
allocated array, use size as the new definied size.
Now the value that should be added to the Array that stores the content
can be added by referencing by tail.

### How to cook a binary search tree

   
