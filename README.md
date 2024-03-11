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
#### Blueprint
`int top = -1;`

`int *content;`

`int size;`

`int push(int x);`

`int pop()`

##### Insert functionality
To insert a value in the stack, again memory needs to be allocated.
The size should be specified in the allocation function.
Increase the top counter by 1. And set the postion in the pointer of 
content to the content provided by the parameter x.
Return the inserted value.

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

`struct Node* createStructure(int x);`

`struct Node* insertNode(struct Node* node, int x);`

#### Insert functionality
First we need to create the structure of the tree, which means
the function `createStructure(int x);` should allocate memory and 
set all the value that are listed in `struct Node`.
In the function `insertNode` we need to specify if the node is either null,
then we should create a structure again or it is not.
If it is not null, we need to check if the root node which is provided as a 
parameter is either larger or less than the root value.
if it's larger we need to call the `insertNode()` function recursivly.
So we can do the same for either the right or the left node of the root node,
provided in the parameter.


### How to cook a double linked list
#### Blueprint
`struct Node { int value; Node* next; Node* prev; };`

`insertBeginning(Node* head, int data);`

`insertAfter(Node* before, int data);`

`deleteAfter(Node* node);`

`delteBeginnign();`

#### Insert functionality
It needs do be diffierenciated between insert content at the beginning and insert content between and at the end.
For the beginning we need two parameters, the content that should be inserted and the head pointer.
The head Node can either be set globally or provided as a parameter of the `insertBeginning` function.

##### Insert at the beginning
If the list is NULL, we need to allocate new space in the memory in this function.
Next we need to specify the different pointers of the struct. 
Set the value to the value provided in the parameter. 
Set the next Node to the provided head Node.
Set the prev Node to NULL.
If the head is not NULL and was set earlier in runtime, the prev Node for head should
be the new Node which we allocated memory for. 
Afterwards assign the new Node to the head Node.

##### Insert inbetween or at the end
For this function it is also necassary to get the previous Node of the Node we want to add.
Now again allocate memory first. 
Set the data of the allocated node to the provided data by the parameter.
Set the next node the previous node to the newily allocated node.
Basiclly copy all the pointer from the previouse Node and set them 
to the Node we are allocating. If the next Node is not null also set the 
previouse reference of the next Node to the new Node.

