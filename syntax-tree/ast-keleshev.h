#ifndef AST_KELESHEV
typedef struct AST AST;
typedef struct Node Node;
typedef enum opr
{
    MUL,
    ADD,
    DIV,
    SUB
} opr;
AST *new_AST();
Node *new_Node();
void displayTree(AST *ast);
char *printOperation(opr printOperation);
int isOperation(char *t);
AST *insert(AST *term, char *val);
#endif