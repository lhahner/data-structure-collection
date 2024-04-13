#include <stdlib.h>
#include <stdio.h>
#include "ast-keleshev.h"
#include <regex.h>

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
    insert(term, "2+2");
    return 1;
}

AST *insert(AST *term, char *val)
{
    if (term == NULL)
    {
        return NULL;
    }
    else
    {
        if (isOperation(val) == 0)
        {
            printf("insert AST");
            return term;
        }
    }
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

int isOperation(char *t)
{
    regmatch_t *__restrict__ pmatch;
    regex_t reegex;
    int isCompiled = regcomp(&reegex, "[+-/*]", 0);
    if (isCompiled == 0)
    {
        int isMatch = regexec(&reegex, t, 0, NULL, 0);
        if (isMatch == 0)
        {
            return 0;
        }
    }
    else
    {
        // error in Regex compilation
        return 1;
    }

    return 0;
}
