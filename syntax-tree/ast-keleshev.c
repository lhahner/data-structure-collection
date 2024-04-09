#include <stdlib.h>
#include <stdio.h>
#include "ast-keleshev.h"

struct AST
{
    enum
    {
        AST_NUMBER,
        AST_ADD,
        AST_MUL
    } tag;
    union
    {
        struct AST_NUMBER
        {
            int number;
        } AST_NUMBER;
        struct AST_ADD
        {
            AST *left;
            AST *right;
        } AST_ADD;
        struct AST_MUL
        {
            AST *left;
            AST *right
        } AST_MUL;
    } data;
};

int main()
{
    AST *term = new_AST(
        (AST){
            AST_ADD,
            {.AST_ADD = (struct AST_ADD){
                 new_AST((AST){
                     AST_NUMBER,
                     {.AST_NUMBER = (struct AST_NUMBER){5}}}),
                 new_AST((AST){
                     AST_NUMBER,
                     {.AST_NUMBER = (struct AST_NUMBER){1}}}),
             }}});

    return 1;
}

AST *new_AST(AST ast)
{
    AST *ptr = malloc(sizeof(AST));
    *ptr = ast;
    return ptr;
}
