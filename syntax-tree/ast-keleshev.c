#include <stdlib.h>
#include <stdio.h>
#include "ast-keleshev.h"

struct AST
{
    Node *root;
};

struct Node
{
    int number;
    opr operation;
    Node *left;
    Node *right;
};

int main()
{
    AST *term = new_AST();
    term->root = new_Node();

    term->root->operation = ADD;

    term->root->left = new_Node();
    term->root->right = new_Node();
    term->root->left->number = 2;
    term->root->right->number = 2;

    displayTree(term);
    return 1;
}

AST *new_AST()
{
    AST *ptr = malloc(sizeof(AST));
    return ptr;
}

Node *new_Node()
{
    Node *n = malloc(sizeof(Node));
    return n;
}

void displayTree(AST *ast)
{
    printf(" %s \n", printOperation(ast->root->operation));
    printf("\/   \\ \n");
    printf("%d   %d", ast->root->left->number, ast->root->right->number);
}

char *printOperation(opr printOperation)
{
    switch (printOperation)
    {
    case MUL:
        return "MUL";
    case ADD:
        return "ADD";
    case DIV:
        return "DIV";
    case SUB:
        return "SUB";
    default:
        return NULL;
    }
}