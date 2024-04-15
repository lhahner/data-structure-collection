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
    char *operation;
    Node *left;
    Node *right;
};

int main()
{
    char *expr = "2+2";
    for (int i = 0; i < sizeof(expr); i++)
    {
        AST *term = insert(term, (char)expr[i]);
    }
    return 1;
}

AST *insert(AST *term, char *val)
{
    if (term == NULL)
    {
        if (isOperation(val) == 0)
        {
            term = new_AST();
            term->root = new_Node();
            /**
             * @todo adding the root element for an operation and
             * adding a leaf element as roof
             */
            return term;
        }
        else
        {
            // return the tree if the first member was not an opeartion.
            return NULL;
        }
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
    printf(" %s \n", getOperation(ast->root->operation));
    printf("\/   \\ \n");
    printf("%d   %d", ast->root->left->number, ast->root->right->number);
}

char *getOperation(opr printOperation)
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
