#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#define bool int
#define true 1
#define false 0
#define Tree
extern char* yytext;

typedef struct Ast
{
    int line;
    char* name;
    struct Ast* pleft;
    struct Ast* pright;
    union
    {
        bool bl;
        int intgr;
        char* str;
    };
}ast;

/* num:变长参数中语法节点的个数 */
ast* new_ast(char *name, int num, ...);
void print_tree(ast* node, int level);