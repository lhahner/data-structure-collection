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

### How to cook a queue
1. head, tail, content and size needed
2. insert
  1.  increase size and tail.
  2.  safe current content in tmp
  3.  realloc content
  4.  add value to position at tail in array content
   
