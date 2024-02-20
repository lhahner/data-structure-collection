# data-structure-collection
This is a personal collection to learn about data structure and how to implement it in C.

## Currently possible to use
| Data Strucutre | Functionality    |
| -------------- | ---------------- |
| Linked List (not dynamic)    | add, delete      |
| Stack (not dynamic)          | push, pop        |
| Queue          | enqueue, dequeue |
| Double Linked List | Insert, Delete |
| Binary Search Tree | Insert, Delelte |

## Purpose
I want to create my own code-base for Projects in the future.
Also I want to learn more about stoarge allocation and pointers to get more knowledge about low-level programming lanugages

## DS Cookbook
### How to cook a Linked-list
#### Blueprint
`struct { int value; Node* next };`
`void push(struct Node* obj ,int data);`
`void pop(struct Node* obj, int data);`

#### Insert functionality
Create a struct that can sture a value and has a pointer to the next Node.
In the insert funtionality there should be the Node given that is the first
Node of the list. Also the Parameter should provide the value that should be assigend.
Now a temporaly variable is needed to store the frist Node of the list, provided by
the paramter. Use a loop to iterate over the Nodes, initalize the temporally stored
variable to store the next Node of the current Node.
For the next Node of the current, that is null, memory allocation is needed.
Allocate memory and set the value as given in the paramter. The next Node
should then be null, since the variable is added at the end of the list.
  
### How to cook a stack
1. array, tail and size value
2. insert
  1. increase tail and insert in array at position of tail

### How to cook a Queue
#### Blueprint
`int size, tail, head;`
`int* content;`

 `void enqueue(int data);`
 `void dequeue();`

#### Insert functionality
First increase the variable that stores the size of the list.
Then increse the variable that stores the tail of the Queue.
Safe the current content in a temporally allocated variable.
Now Reallocate the Array that stores the content with the temporally
allocated array, use size as the new definied size.
Now the value that should be added to the Array that stores the content
can be added by referencing by tail.

### How to cook a binary search tree
#### Blueprint
`struct Node { int value; Node* left; Node* right; };`
#### Insert functionality

### How to cook a double linked list
#### Blueprint
`struct Node { int value; Node* next; Node* prev; };`
`insertBeginning(Node* head, int data);`
`insertAfter(Node* before, int data);`
`deleteAfter(Node* node);`
`delteBeginnign();`

#### Insert functionality
