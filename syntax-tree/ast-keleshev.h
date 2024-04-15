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
char *getOperation(opr printOperation);
int isOperation(char *t);
AST *insert(AST *term, char *val);
/**
 * @cite from AhO page 318
 */
leaf(int op, char *val);
#endif