# Data-structure-collection
This is a personal collection to learn about data structure and how to implement it in C.

# Currently possible to use
| Data Strucutre | Functionality    |
| -------------- | ---------------- |
| Linked List (not dynamic)    | add, delete      |
| Stack (not dynamic)          | push, pop        |
| Queue          | enqueue, dequeue |
| Double Linked List | Insert, Delete |
| Binary Search Tree | Insert, Delelte |
| Heap | Heapify |
| Graph | Insert, Delete |
| Hash table | Insert, delete |


# Purpose
I want to create my own code-base for Projects in the future.
Also I want to learn more about stoarge allocation and pointers to get more knowledge about low-level programming lanugages.
Furthermore the the process in implementing data structures should be simplified by giving examples as blueprints.

# Basic Blueprint for Data Structures in C
In C we need to allocate memory by ourself. This is something that is pretty strange for someone that has mostly Java expierence.
Since we always need memory for all of our structures the procedure of allocating memory is the first requirement for implementing the data strucutre.
Which leads to the overall best-practice blueprint. This best-practice blue will provide the basic functions a data-strucutre should cover and this 
might also the frist step to go while implementing a specifc data-strucutre.

`create(values, size);`

`freeDs(values);`

The create function should allocate memory for the variable that should contain the values. Be aware to specify a size.
If it should be dynamiclly configured just create a global size variable and increase while adding values.
The free function should either free memory of the whole data structure or for one item of the data strucutre.

# Data Structure Cookbook
## How to cook a Linked-list
### Blueprint
`struct { int value; Node* next };`

`void push(struct Node* obj ,int data);`

`void pop(struct Node* obj, int data);`

### Insert functionality
Create a struct that can store a value and has a pointer to the next Node.
In the insert funtionality there should be the Node given that is the first
Node of the list. Also the Parameter should provide the value that should be assigend.
Now a temporaly variable is needed to store the frist Node of the list, provided by
the paramter. Use a loop to iterate over the Nodes, initalize the temporally stored
variable to store the next Node of the current Node.
For the next Node of the current, that is null, memory allocation is needed.
Allocate memory and set the value as given in the paramter. The next Node
should then be null, since the variable is added at the end of the list.
  
## How to cook a stack
### Blueprint
`int top = -1;`

`int *content;`

`int size;`

`int push(int x);`

`int pop()`

### Insert functionality
To insert a value in the stack, again memory needs to be allocated.
The size should be specified in the allocation function.
Increase the top counter by 1. And set the postion in the pointer of 
content to the content provided by the parameter x.
Return the inserted value.

## How to cook a Queue
### Blueprint
`int size, tail, head;`

`int* content;`

 `void enqueue(int data);`
 
 `void dequeue();`

### Insert functionality
First increase the variable that stores the size of the list.
Then increse the variable that stores the tail of the Queue.
Safe the current content in a temporally allocated variable.
Now Reallocate the Array that stores the content with the temporally
allocated array, use size as the new definied size.
Now the value that should be added to the Array that stores the content
can be added by referencing by tail.

## How to cook a binary search tree
### Blueprint
`struct Node { int value; Node* left; Node* right; };` 

`struct Node* createStructure(int x);`

`struct Node* insertNode(struct Node* node, int x);`

### Insert functionality
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


## How to cook a double linked list
### Blueprint
`struct Node { int value; Node* next; Node* prev; };`

`insertBeginning(Node* head, int data);`

`insertAfter(Node* before, int data);`

`deleteAfter(Node* node);`

`delteBeginnign();`

### Insert functionality
It needs do be diffierenciated between insert content at the beginning and insert content between and at the end.
For the beginning we need two parameters, the content that should be inserted and the head pointer.
The head Node can either be set globally or provided as a parameter of the `insertBeginning` function.

#### Insert at the beginning
If the list is NULL, we need to allocate new space in the memory in this function.
Next we need to specify the different pointers of the struct. 
Set the value to the value provided in the parameter. 
Set the next Node to the provided head Node.
Set the prev Node to NULL.
If the head is not NULL and was set earlier in runtime, the prev Node for head should
be the new Node which we allocated memory for. 
Afterwards assign the new Node to the head Node.

#### Insert inbetween or at the end
For this function it is also necassary to get the previous Node of the Node we want to add.
Now again allocate memory first. 
Set the data of the allocated node to the provided data by the parameter.
Set the next node the previous node to the newily allocated node.
Basiclly copy all the pointer from the previouse Node and set them 
to the Node we are allocating. If the next Node is not null also set the 
previouse reference of the next Node to the new Node.

## How to cook a heap
### Blueprint
`void heapify(int array[], int i);`

`void swap(int *a, int *b);`

`void print(int array[]);`

### Insert functionality
#### Heapify
First create a heapify methode to make sure the rules for either a max-heap or a min-heap are correct.
The heapify method should compare the number that should be added to the parent note. Done through dividing the index by 2.
For example if it's a max heap swap whenever the child node is larger than the parent node.
The 2Dimnesional heap structure as a tree is brought to 1Dimension by 2*i and 2*i+1, which means the elment next to the next and
next to the next of the next.

## How to cook a Hashtable
### Blueprint
`struct Hashtable { Hashitem** list; };`

`struct Hashitem { int key; char* value};`

`Hashtable* createHashtable();`

`void insert(Hashtable* table, char* value);`

`void delete(Hashtable* table, char* value);`

`char* get(Hashtable* table, int key);`
### Insert functionality
To insert one item in the hashtable the hash key and a value.
The key is generated by the hashfunction, which defines a random key for
the related value. The value is inserted in the pointer list of the hashtable strucutre.

## How to cook binary heap tree

# Literatur

[Aho, Algorhitmen and Datastrucutes](https://users.dcc.uchile.cl/~voyanede/cc4102/dS&A%20Book%20By%20Alfred%20-Aho.pdf)

Learning Data Structures and Algorithms is essential, allowing us to learn how to manage and manipulate data efficiently.
Steps you should follow to learn about data structures and algorithms.
=> Choose a programming language and master it: Take your first step in the field of DSA by learning any programming language of your choice. If you are an absolute beginner, having some basic knowledge of the programming languages, like C++, JAVA, or Python, is recommended. Learn about the syntax, basic inbuilt methods, conditional statements, loops, etc.
=> Learn about time and space complexities: This part is much more important, and many students skip by thinking it is a challenging topic and irrelevant, but I recommend you learn it. Learn About types of complexity and their different notations.Complexities are measured in terms of the size of inputs. Also, learn about the concept of asymptotic notations in complexities.
=> Learn about different types of Data structures and algorithms: We are finally starting to learn different data structures and algorithms.

The sequence that you can follow.
=> Arrays: "Arrays are a good starting point for your journey into DSA, as they are a fundamental topic." Arrays are a list of similar elements.
=> Strings: A string is a collection of characters. There are many string operations and methods you can learn.
=> Sorting Algorithms: These are important topics every programmer should know. Sorting algorithms like Merge, Quick, sort, bubble, Insertion, and heap sort are trendy.
=> Searching algorithms: In Searching algorithms, you should learn both Liner search and Binary search algorithms.
=> Linked lists: Another important concept every beginner should learn. Students find it a little tricky, but it is fun to learn about them.
=> Divide and conquer: In this algorithm, we learn how to divide a big problem into smaller ones to solve it easily.
=> Stack: Another data structure that works on the principle of FIFO.
=> Queue: This data structure works on the LIFO principle.
=> Trees: Until here, we only learned about linear data structure, but trees are non-linear data structures and much easier to learn.
=> Graphs: The graph Data structure has many traversal and searching algorithms.
=> Greedy Algorithms: This algorithm works on the principle of local optimization technique.
=> Recursion: Recursion is a technique in which a function calls itself to solve a problem by breaking it down into smaller subproblems.
=> Backtracking: It is a related technique that can be learned after recursion.
=> Dynamic programming: It is an algorithmic technique for solving optimization problems efficiently.
After these topics, you also can learn different intermediate-level algorithms and data structures like BST, Tries, Segment Trees, B-Tree, etc.
=> Practice multiple questions: This is the most important learning process. In this step, discipline is the key. Try to start with easy problems and then medium and hard ones. Try to do more and more questions.
=> Try to participate in coding competitions: This is the time to test yourself among other coders. Try to participate in coding competitions that will show your standing among others. It also tells you where you are lagging

