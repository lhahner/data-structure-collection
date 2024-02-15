#include <stdlib.h>
#include <stdio.h>

struct Node {
	int value;
	struct Node* left;
	struct Node* right;
};

struct Node* createNewStructure(int x){
	struct Node* tmp = malloc(sizeof(struct Node));
	tmp->value = x;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

struct Node* insertNode(struct Node* node, int x){
	if(node == NULL){
		return createNewStructure(x);
	}
	else if(x < node->value){
		node->left = insertNode(node->left, x);
	}
	else if(x > node->value) {
		node->right = insertNode(node->right, x);
	}
	return node;
}

void preOrder(struct Node* node){
	if(node != NULL){
		printf("%d\n", node->value);
		
		preOrder(node->left);
		preOrder(node->right);
	}

}

void main(){
	struct Node* root = NULL;
	root = insertNode(root, 2);
	insertNode(root, 4);
	insertNode(root, 3);
	insertNode(root, 2);

	preOrder(root);

}
