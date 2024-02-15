#include <stdlib.h>
#include <stdio.h>

struct Node{
	int key;
	struct Node *left;
	struct Node *right;
};

struct Node* root;
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

struct Node* findMin(struct Node* root){
	if(root == NULL) {
		return NULL;
	}
	else if(root->left != NULL){
		return findMin(root->left);
	}
	return root;

}

struct Node* delete(struct Node* root, int x){

	if(root == NULL){
		return NULL;
	}
	if(x > root->key){
		root->right = delete(root->right, x);
	} else if(x < root->key){
		root->left = delete(root->left, x);
	}
	else {
		if(root->left == NULL && root->right == NULL){
			free(root);
			return NULL;
	
		}
		else if(root->left == NULL || root->right == NULL){
		struct Node* tmp;
			if(root->left == NULL){
				tmp = root->right;
			}
			else {
				tmp = root->left;
			}
			free(root);
			return tmp;
		}
		else {
			struct Node* tmp = findMin(root->right);
			root->key = tmp->key;
			root->right = delete(root->right, tmp->key);
		}
	}
	return root;
}

void main(){
	struct Node* root = NULL;
	root = insertNode(root, 30);
	insertNode(root, 20);
	insertNode(root, 40);
	insertNode(root, 70);
	struct Node* tmp = delete(root, 70);
	preOrder(root);
}
