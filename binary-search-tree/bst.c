#include <stdlib.h>
#include <stdio.h>

struct Node{
	int key;
	struct Node *left;
	struct Node *right;
};

struct Node* createNewNode(int value){
	struct Node* tmp = malloc(sizeof(struct Node));
	tmp->key = value;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

struct Node* insertNode(struct Node* node, int value){
	if(node == NULL){
		return createNewNode(value);
	}
	if(value < node->key){
		node->left = insertNode(node->left, value);
	}
	else if(value > node->key){
		node->right = insertNode(node->right, value);
	}
	return node;
}

void preOrder(struct Node* root){
	if(root != NULL){
		printf(" %d \n", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}

}


void main(){
	struct Node* root = NULL;

	root = insertNode(root, 30);
	insertNode(root, 20);
	insertNode(root, 40);
	insertNode(root, 70);

	preOrder(root);
}
