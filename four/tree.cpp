#include "tree.h"
#include "symtable.h"
//全局树的建立

ast* new_ast(char* name, int num, ...)
{
    va_list valist; //变长参数列表
    ast* phead = (ast*)malloc(sizeof(ast));
    ast* ptemp = NULL;
    if(!phead)
    {
        printf("malloc error");
        exit(-1);
    }
    phead->pleft = NULL;
    phead->pright = NULL;
    phead->name = name;
    va_start(valist, num);
    if(num > 0) //非终结符：变长参数为语法树结点，孩子兄弟表示法
    {
        ptemp = va_arg(valist, ast*);
        phead->pleft = ptemp;
        phead->line = ptemp->line; //父亲节点的行号等于左孩子的行号
        
        if(num >= 2)
        {
            for(int i = 0; i < num-1 ; ++i)
            {
                ptemp->pright = va_arg(valist, ast*);
                ptemp = ptemp->pright;
            }
        }
    }
    else    //终结符
    {
        int line = va_arg(valist, int);
        phead->line = line;
        if((strcmp(phead->name, "IDENTIFIER") == 0) || (strcmp(phead->name, "TYPE") == 0))
        {
            char *str=(char*)malloc(strlen(yytext)+1);
            strcpy(str,yytext);
            phead->str=str;
        }
        else if(strcmp(phead->name, "INTCONST") == 0)
        {
            phead->intgr = atoi(yytext);
        }
        else if(strcmp(phead->name, "BOOLCONST") == 0)
        {
            phead->bl = strcmp(yytext, "true")==0?true:false;
        }
        else if(strcmp(phead->name, "STRINGCONST") == 0)
        {
            char *str=(char*)malloc(strlen(yytext)+1);
            strcpy(str,yytext);
            phead->str=str;
        }
    }
    return phead;
}

void print_tree(ast* node, int level)
{
    if(node != NULL)
    {
        for(int i = 0; i < level; i++)
        {
            printf("  ");
        }
        if(node->line != -1)
        {
            printf("%s ", node->name);
            if((strcmp(node->name, "IDENTIFIER") == 0) || (strcmp(node->name, "TYPE") == 0) || (strcmp(node->name, "STRINGCONST") == 0))
            {
                printf(":%s ", node->str);
            }
            else if(strcmp(node->name, "INTCONST") == 0)
            {
                printf(":%d", node->intgr);
            }
            else if(strcmp(node->name, "BOOLCONST") == 0)
            {
                printf(":%d", node->bl);
            }
            else
                printf("(%d)", node->line);
        }
        else
        {
            printf("%s", node->name);
        }
        printf("\n");
        print_tree(node->pleft, level+1);
        print_tree(node->pright, level);
    }
}