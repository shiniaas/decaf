#ifndef __TREE.H__
#define __TREE.h__
#include "symtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#define bool int
#define true 1
#define false 0
#define Tree
extern char* yytext;

int curscope = 0;

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
}Ast;

Declaration* Isfunc(char* name); //判断name是否是一个函数
int CheckFunType(Declaration* pD, Ast* pnode);
int Getactualnum(Ast* p);
void CheckType(Ast* p);
int CheckVarExist(char* varname);
int CheckClassExist(char* classname);
int CheckClass(Ast* pnode, char* classname);
int CheckExist(char* p);
char* GetType(char* varname);

/* num:变长参数中语法节点的个数 */
//全局符号表的建立
Symtable symglobal = {GLOBAL};
int infunc = 0;
Declaration* pcurclass = NULL; //记录this指针属于哪一个类
Declaration* pcurfunc = NULL; //用于return判断

vector<char*> vtype; //用于类型判断

Ast* new_ast(char* name, int num, ...)
{
    va_list valist; //变长参数列表
    Ast* phead = (Ast*)malloc(sizeof(Ast));
    Ast* ptemp = NULL;
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
        ptemp = va_arg(valist, Ast*);
        phead->pleft = ptemp;
        phead->line = ptemp->line; //父亲节点的行号等于左孩子的行号
        
        if(num >= 2)
        {
            for(int i = 0; i < num-1 ; ++i)
            {
                ptemp->pright = va_arg(valist, Ast*);
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
        else if(strcmp(phead->name, "int") == 0)
        {
            phead->intgr = atoi(yytext);
        }
        else if(strcmp(phead->name, "bool") == 0)
        {
            phead->bl = strcmp(yytext, "true")==0?true:false;
        }
        else if(strcmp(phead->name, "string") == 0)
        {
            char *str=(char*)malloc(strlen(yytext)+1);
            strcpy(str,yytext);
            phead->str=str;
        }
    }
    return phead;
}

void Creat_Symtable(Ast* node, int level)
{
    if(node != NULL)
    {
//        printf("in line %d\n", node->line);
        if(node->line != -1)
        {
            if(strcmp(node->name, "PLBBB") == 0)
            {
                curscope = curscope+1;
                if(curscope > 3)    //需开辟Local域
                {
                    Declaration* pD = new Declaration;
                    pD->name = NULL;
                    pD->type = NULL;
                    pD->func = 0;
                    pD->pSym = new Symtable;
                    pD->pSym->type = LOCAL;
                    Symstack.top()->vDeclaration.push_back(pD);
                    Symstack.push(pD->pSym);
                }
            }
            else if(strcmp(node->name, "PRBBB") == 0)
            {
                if(curscope == 3)
                {
                    curscope = curscope-2;  //函数定义完成之后应该回到CLASS域
                    Symstack.pop();
                    Symstack.pop();
                }
                else
                {
                    curscope = curscope-1;
                    Symstack.pop();
                }
            }
            else if(strcmp(node->name, "ClassDef") == 0) //class的声明
            {
//                printf("in ClassDef\n");
                if(CheckClassExist(node->pleft->pright->str) == 1)
                {
                    printf("Error1 line %d: class %s has existed\n", node->line, node->pleft->pright->str);
                }
                if(strcmp(node->pleft->pright->pright->name, "KEXTENDS") == 0) //继承
                {
                    if(CheckClassExist(node->pleft->pright->pright->pright->str) == 0)
                    {
                        printf("Error2 line %d: class %s not existed\n", node->line, node->pleft->pright->pright->pright->str);
                        Declaration* pD = new Declaration;
                        pD->name = NULL;
                        pD->type = NULL;
                        pD->func = 0;
                        pD->pSym = NULL;
                        pD->father = NULL;
                        Symstack.top()->vDeclaration.push_back(pD);
                        pD->name = (char*)malloc(strlen(node->pleft->pright->str)+1);
                        strcpy(pD->name, node->pleft->pright->str);
                        pD->type = (char*)malloc(6);
                        strcpy(pD->type, "class");
                        pD->pSym = new Symtable;
                        pD->func = 0;
                        pD->pSym->type = CLASS;
                        pcurclass = pD;
                        Symstack.push(pD->pSym);
                    }
                    else    //继承时我们需要把父类的第一层拷贝过去变量，函数
                    {
                        Declaration* pDt = NULL;
                        int count = symglobal.vDeclaration.size();
                        int i = 0;
                        for(i; i < count; i++)
                        {
                            pDt = symglobal.vDeclaration[i];
                            if(pDt->name == NULL)
                            {
                                continue;
                            }
                            else if(strcmp(node->pleft->pright->pright->pright->str, pDt->name) == 0)
                            {
                                break; //pD中保存有信息
                            }
                        }
                        Declaration* pD = new Declaration;
                        pD->name = NULL;
                        pD->type = NULL;
                        pD->func = 0;
                        pD->pSym = NULL;
                        pD->father = NULL;
                        Symstack.top()->vDeclaration.push_back(pD);
                        pD->name = (char*)malloc(strlen(node->pleft->pright->str)+1);
                        strcpy(pD->name, node->pleft->pright->str);
                        pD->type = (char*)malloc(6);
                        strcpy(pD->type, "class");
                        pD->pSym = new Symtable;
                        pD->func = 0;
                        pD->pSym->type = CLASS;
                        pD->father = (char*)malloc(strlen(node->pleft->pright->pright->pright->str)+1);
                        strcpy(pD->father, node->pleft->pright->pright->pright->str);
                        pcurclass = pD;
                        Symstack.push(pD->pSym);
                        count = pDt->pSym->vDeclaration.size(); //需要拷贝的信息的个数,用深拷贝
                        Declaration* pcopy = NULL;
                        for(int i = 0; i < count; i++)
                        {
                            pcopy = new Declaration;
                            pcopy->name = (char*)malloc(strlen(pDt->pSym->vDeclaration[i]->name)+1);
                            strcpy(pcopy->name, pDt->pSym->vDeclaration[i]->name);
                            pcopy->type = (char*)malloc(strlen(pDt->pSym->vDeclaration[i]->type)+1);
                            strcpy(pcopy->type, pDt->pSym->vDeclaration[i]->type);
                            pcopy->func = pDt->pSym->vDeclaration[i]->func;
                            if(pcopy->func == 1) //函数还要拷贝第一层的formal域
                            {
                                pcopy->pSym = new Symtable;
                                pcopy->pSym->type = FORMAL;
                                for(int k = 0; k < pDt->pSym->vDeclaration[i]->pSym->vDeclaration.size(); k++)
                                {
                                    Declaration* pDe = new Declaration;
                                    pcopy->pSym->vDeclaration.push_back(pDe);
                                    if(pDt->pSym->vDeclaration[i]->pSym->vDeclaration[k]->name == NULL)
                                    {
                                        pDe->name = NULL;
                                    }
                                    else
                                    {
                                        pDe->name = (char*)malloc(strlen(pDt->pSym->vDeclaration[i]->pSym->vDeclaration[k]->name)+1);
                                        strcpy(pDe->name, pDt->pSym->vDeclaration[i]->pSym->vDeclaration[k]->name);
                                    }
                                    if(pDt->pSym->vDeclaration[i]->pSym->vDeclaration[k]->type == NULL)
                                    {
                                        pDe->type = NULL;
                                    }
                                    else
                                    {
                                        pDe->type = (char*)malloc(strlen(pDt->pSym->vDeclaration[i]->pSym->vDeclaration[k]->type)+1);
                                        strcpy(pDe->type, pDt->pSym->vDeclaration[i]->pSym->vDeclaration[k]->type);
                                    }
                                    pDe->func = pDt->pSym->vDeclaration[i]->pSym->vDeclaration[k]->func;
                                    pDe->pSym = NULL;
                                }
                            }
                            else
                            {
                                pcopy->pSym = NULL;
                            }
                            pD->pSym->vDeclaration.push_back(pcopy);
                        }
                    }
                }
                else
                {
                    Declaration* pD = new Declaration;
                    pD->name = NULL;
                    pD->type = NULL;
                    pD->func = 0;
                    pD->pSym = NULL;
                    pD->father = NULL;
                    Symstack.top()->vDeclaration.push_back(pD);
                    pD->name = (char*)malloc(strlen(node->pleft->pright->str)+1);
                    strcpy(pD->name, node->pleft->pright->str);
                    pD->type = (char*)malloc(6);
                    strcpy(pD->type, "class");
                    pD->pSym = new Symtable;
                    pD->func = 0;
                    pD->pSym->type = CLASS;
                    pcurclass = pD;
                    Symstack.push(pD->pSym);
                }
//                printf("exit classdef\n");
            }
            else if(strcmp(node->name, "FunctionDef") == 0) //函数的声明
            {
//                printf("in functiondef\n");
                infunc = 1;
                Declaration* pD = new Declaration;
                pD->name = NULL;
                pD->type = NULL;
                pD->pSym = NULL;
                pD->func = 1;
                Symstack.top()->vDeclaration.push_back(pD);
                Ast* pnode = node->pleft;
                while(pnode != NULL)
                {
                    if(strcmp(pnode->name, "Type") == 0)    //函数返回值类型
                    {
                        pD->type = (char*)malloc(sizeof(strlen(pnode->pleft->str)+1));
                        strcpy(pD->type, pnode->pleft->str);
                    }
                    else if(strcmp(pnode->name, "IDENTIFIER") == 0) //函数名
                    {
                        if(CheckVarExist(pnode->str) == 1)
                        {
                            printf("Error3 line %d: %s has been declared\n", node->line, pnode->str);
                        }
                        pD->name = (char*)malloc(sizeof(strlen(pnode->str)+1));
                        strcpy(pD->name, pnode->str);
                    }
                    pnode = pnode->pright;
                }
                pD->pSym = new Symtable;
                pD->pSym->type = FORMAL;
                Symstack.push(pD->pSym);
                pcurfunc = pD;
//                printf("exit funcdef\n");
            }
            else if(infunc == 1 && strcmp(node->name, "OLB") == 0)
            {
                curscope = curscope + 1;
                //增加隐含参数this指针
                Declaration* pD = new Declaration;
                pD->name = (char*)malloc(sizeof("this")+1);
                strcpy(pD->name, "this");
                pD->type = (char*)malloc(sizeof("class ")+strlen(pcurclass->name)+1);
                strcpy(pD->type, "class ");
                strcat(pD->type, pcurclass->name);
                pD->pSym = NULL;
                pD->func = 0;
                Symstack.top()->vDeclaration.push_back(pD);
            }
            else if(infunc == 1 && strcmp(node->name, "ORB") == 0)
            {
                infunc = 0; //参数声明结束
                //将local链到this指针之后
                Declaration* pD = new Declaration; //空的delaration用于链接后面部分
                pD->name = NULL;
                pD->type = NULL;
                pD->func = 0;
                pD->pSym = new Symtable;
                pD->pSym->type = LOCAL;
                Symstack.top()->vDeclaration.push_back(pD);
                Symstack.push(pD->pSym);
            }
            else if(strcmp(node->name, "Variable") == 0)    //变量处理
            {
//                printf("in variable\n");
                Declaration* pD = new Declaration;
                pD->name = NULL;
                pD->type = NULL;
                pD->pSym = NULL;
                pD->func = 0;
                Symstack.top()->vDeclaration.push_back(pD);
                if(node->pleft->pleft->pright == NULL) //type 为int bool string 或 void
                {
                    if(CheckVarExist(node->pleft->pright->str) == 1)
                    {
                        printf("Error3 line %d: %s has been declared\n", node->line, node->pleft->pright->str);
                    }
                    pD->type = (char*)malloc(sizeof(node->pleft->pleft->str)+1);
                    strcpy(pD->type, node->pleft->pleft->str);
                    pD->name = (char*)malloc(sizeof(node->pleft->pright->str)+1);
                    strcpy(pD->name, node->pleft->pright->str);
                }
                else if(strcmp(node->pleft->pleft->name, "KCLASS") == 0) //type 为class类型
                {
                    if(strcmp(pcurclass->name, node->pleft->pleft->pright->str) == 0)
                    {
                        printf("Error4 line:%d using class %s in itself is not allowed\n", node->line, pcurclass->name);
                    }
                    if(CheckClassExist(node->pleft->pleft->pright->str) == 0)
                    {
                        printf("Error5 line:%d class %s not declarated\n", node->line, node->pleft->pright->str);
                    }
                    if(CheckVarExist(node->pleft->pright->str) == 1)
                    {
                        printf("Error3 line %d: %s has been declared\n", node->line, node->pleft->pright->str);
                    }
                    pD->type = (char*)malloc(strlen("class ")+strlen(node->pleft->pleft->pright->str)+1);
                    strcpy(pD->type, "class ");
                    strcat(pD->type, node->pleft->pleft->pright->str);
                    pD->name = (char*)malloc(sizeof(node->pleft->pright->str)+1);
                    strcpy(pD->name, node->pleft->pright->str);
                    
                }
                else    //type为数组类型
                {
                    Ast* pnode = node->pleft;
                    int count = 0;
                    while(pnode->pleft!=NULL)
                    {
                        pnode = pnode->pleft;
                        count = count+1;
                    }
                    count = count-1;
                    if(pnode->pright == NULL)
                    {
                        if(CheckVarExist(node->pleft->pright->str) == 1)
                        {
                            printf("Error3 line %d: %s has been declared\n", node->line, node->pleft->pright->str);
                        }
                        pD->type = (char*)malloc(1+2*count+strlen(pnode->str)+1);
                        strcpy(pD->type, pnode->str);
                        for(int i = 0; i < count; i++)
                        {
                            strcat(pD->type, "[]");
                        }
                        pD->name = (char*)malloc(sizeof(node->pleft->pright->str)+1);
                        strcpy(pD->name, node->pleft->pright->str);
                    }
                    else
                    {
                        if(CheckVarExist(node->pleft->pright->str) == 1)
                        {
                            printf("Error3 line %d: %s has been declared\n", node->line, node->pleft->pright->str);
                        }
                        pD->type = (char*)malloc(1+2*count+strlen(pnode->pright->str)+6+1); //class数组
                        strcpy(pD->type, "class ");
                        strcat(pD->type, pnode->pright->str);
                        for(int i = 0; i < count; i++)
                        {
                            strcat(pD->type, "[]");
                        }
                        pD->name = (char*)malloc(sizeof(node->pleft->pright->str)+1);
                        strcpy(pD->name, node->pleft->pright->str);
                    }
                }
//                printf("exit variable\n");
            }
            else if(strcmp(node->name, "SimpleStmt") == 0)//检查错误1
            {
//                printf("in simplestmt\n");
                if(strcmp(node->pleft->name, "Call") == 0 && strcmp(node->pleft->pleft->name, "IDENTIFIER") == 0)   //直接函数调用
                {
                    vtype.clear();
                    char* varname = node->pleft->pleft->str;
                    //需要查找变量的类型
                    Declaration* pD = Isfunc(varname);
                    if(pD == NULL)
                    {
                        printf("Error7 line:%d %s is not a function\n", node->line, varname);
                    }
                    else
                    {
                        int paranum = pD->pSym->vDeclaration.size()-2;
                        int actualnum = Getactualnum(node->pleft->pleft->pright->pright);
                        if(paranum != actualnum)
                        {
                            printf("Error8 line:%d parameter num not matched\n", node->line);
                        }
                        else    //checktype
                        {
                            int match = CheckFunType(pD, node->pleft->pleft->pright->pright);
                            if(match == -1)
                            {
                                printf("Error9 line:%d some parameter not declrated\n", node->line);
                            }
                            else if(match == 0)
                            {
                                printf("Error10 line:%d parameter type not matched\n", node->line);
                            }
                        }
                    }
                }
                else if(strcmp(node->pleft->name, "Call") == 0) //从类中调用函数
                {
                    if(node->pleft->pleft->pleft->pleft == NULL)
                    {
                        printf("1\n");
                    }
                    char* pc = GetType(node->pleft->pleft->pleft->pleft->str);
                    if(pc == NULL)
                    {
                        printf("Error11 line:%d %s not declarated\n", node->line, node->pleft->pleft->pleft->pleft->str);
                    }
                    else if(strcmp(pc, "class") == 0)
                    {
                        printf("Error12 line:%d %s is class\n", node->line, node->pleft->pleft->pleft->pleft->str);
                    }
                    else if(strstr(pc, "class ") == NULL)    //说明该变量类型不是类
                    {
                        
                        printf("Error6 line:%d the type of %s is not class\n", node->line, node->pleft->pleft->pleft->pleft->str);
                    }
                    else
                    {
                        pc = pc+6; //去掉前面的class
                        if(strcmp(pc, pcurclass->name) == 0)
                        {
                            printf("Error4 line:%d using class %s in itself is not allowed\n", node->line, pcurclass->name);
                        }
                        else
                        {
                            int rint = CheckClass(node->pleft, pc);
                            if(rint == 0)
                            {
                                printf("Error5 line:%d class %s not declarated\n", node->line, pc);
                            }
                            else if(rint == 1)
                            {
                                printf("Error11 line:%d no data member named %s in %s\n", node->line, node->pleft->pleft->pright->pright->str, node->pleft->pleft->pleft->pleft->str);
                            }
                            else if(rint == 2)
                            {
                                printf("Error17 line:%d no function member named %s in %s\n", node->line, node->pleft->pleft->pright->pright->str, node->pleft->pleft->pleft->pleft->str);
                            }
                            else        //检查参数个数之类的错误
                            {
                                vtype.clear();
                                Declaration* pD = NULL;
                                int flag = 0;   //表明是否找到这个类
                                int count = symglobal.vDeclaration.size();
                                for(int i = 0; i < count; i++)
                                {
                                    pD = symglobal.vDeclaration[i];
                                    if(strcmp(pc, pD->name) == 0)
                                    {
                                        flag = 1;
                                        break;
                                    }
                                }
                                if(flag == 1) //找到了这个类
                                {
                                    char* member = node->pleft->pleft->pright->pright->str;
                                    Symtable* pS = pD->pSym;
                                    count = pS->vDeclaration.size();
                                    for(int i = 0; i < count; i++)
                                    {
                                        pD = pS->vDeclaration[i];
                                        if(strcmp(member, pD->name) == 0 && pD->func == 1)
                                        {
                                            flag = 2;
                                            break;
                                        }
                                    }
                                }
                                if(flag == 2)   //pD保存了该函数的声明
                                {
//                                    printf("%d\n", pD->pSym->vDeclaration.size());
                                    int paranum = pD->pSym->vDeclaration.size()-2;
                                    int actualnum = Getactualnum(node->pleft->pleft->pright->pright->pright->pright);
                                    if(paranum != actualnum)
                                    {
                                        printf("Error8 line:%d parameter num not matched\n", node->line);
                                    }
                                    else    //checktype
                                    {
                                        int match = CheckFunType(pD, node->pleft->pleft->pright->pright->pright->pright);
                                        if(match == -1)
                                        {
                                            printf("Error9 line:%d some parameter not declrated\n", node->line);
                                        }
                                        else if(match == 0)
                                        {
                                            printf("Error10 line:%d parameter type not matched\n", node->line);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else if(strcmp(node->pleft->name, "LValue") == 0)   //赋值表达式
                {
//                    printf("Identifier\n");
                    if(strcmp(node->pleft->pleft->name,"IDENTIFIER")== 0 && CheckExist(node->pleft->pleft->str) == 0)
                    {
                        printf("Error11 line:%d %s not declarated\n", node->line, node->pleft->pleft->str);
                    }
                    else
                    {
                        vtype.clear();
                        CheckType(node->pleft);
                        int count = vtype.size();
                        int flag = 0; //1表示有冲突
                        for(int i = 0; i < count-1; i++)
                        {
                            if(strcmp(vtype[i], vtype[i+1]) != 0)
                            {
                                flag = 1;
                                break;
                            }
                        }
                        if(flag == 1)
                        {
                            printf("Error13 line:%d type not matched\n", node->line);
                        }
                    }
                }
//                printf("exit simplestmt\n");
            }
            else if(strcmp(node->name, "ReturnStmt") == 0)  //用于判断函数返回值
            {
                if(node->pleft->pright == NULL)
                {
                    if(strcmp(pcurfunc->type, "void") != 0)
                    {
                        printf("Error14 line:%d return type not matched\n", node->line);
                    }
                }
                else if(strcmp(node->pleft->pright->pleft->name, "Constant") == 0)
                {
                    
                    if(strcmp(node->pleft->pright->pleft->pleft->name, pcurfunc->type) != 0)
                    {
                        printf("Error14 line:%d return type not matched\n", node->line);
                    }
                }
                else
                {
                    char* pc = GetType(node->pleft->pright->pleft->pleft->str);
                    if(pc == NULL || strcmp(pc, pcurfunc->type) != 0)
                    {
                        printf("Error14 line:%d return type not matched\n", node->line);
                    }
                }
            }
        }
        Creat_Symtable(node->pleft, level+1);
        Creat_Symtable(node->pright, level);
    }
}

Declaration* Isfunc(char* name)
{
    stack<Symtable*> stacktemp = Symstack;
    Declaration* pD = NULL;
    int count = stacktemp.size();
    int num = 0;
    int i, j;
    for(i = 0; i < count; i++)
    {
        num = stacktemp.top()->vDeclaration.size();
        for(j = 0; j < num; j++)
        {
            pD = stacktemp.top()->vDeclaration[j];
            if(pD->name == NULL)
            {
                continue;
            }
            else if(strcmp(pD->name, name) == 0)
            {
                if(pD->func == 1)
                {
                    return pD;
                }
                else
                {
                    return NULL;
                }
            }
        }
        stacktemp.pop();
    }
    return NULL;
}

int CheckFunType(Declaration* pD, Ast* pnode)
{
    stack<Ast*> s;
    Ast* pt = pnode;
    int curpos = 1; //表明当前检查的参数的位置
    char* pc = NULL;
    while(pt!=NULL || !s.empty())
    {
        while(pt!=NULL)
        {
            if(strcmp(pt->name, "LValue") == 0)
            {
                pc = GetType(pt->pleft->str);
                if(!pc)
                {
                    return -1;
                }
                if(strcmp(pc, pD->pSym->vDeclaration[curpos]->type) == 0)
                {
                    curpos++;
                }
                else
                {
                    return 0;
                }
            }
            else if(strcmp(pt->name, "Constant") == 0)
            {
                if (strcmp(pt->pleft->name, pD->pSym->vDeclaration[curpos]->type) == 0)
                {
                    curpos++;
                }
                else
                {
                    return 0;
                }
            }

            s.push(pt);
            pt = pt->pleft;
        }
        if(!s.empty())
        {
            pt = s.top();
            s.pop();
            pt = pt->pright;
        }
    }
    return 1;
}

int Getactualnum(Ast* p)
{
    int num = 0;
    if(p == NULL)
    {
        return 0;
    }
    else if(strcmp(p->name, "Expr") == 0)
    {
        num = 1;
    }
    return Getactualnum(p->pleft)+Getactualnum(p->pright)+num;
}

void CheckType(Ast* p) //检测类型是否匹配, 需要判断类中数据成员
{
    if(p != NULL)
    {
        if(p->line != -1)
        {
            if((strcmp(p->name, "Constant") == 0))
            {
                vtype.push_back(p->pleft->name);
            }
            else if(strcmp(p->name, "LValue") == 0)
            {
                if(p->pleft->pright!=NULL && strcmp(p->pleft->pright->name, "PPOINT") == 0)
                {
                    //类中成员调用
                    char* ctype = GetType(p->pleft->pleft->pleft->str);
                    if (ctype == NULL)
                    {
                        printf("Error15 line:%d %s is not declarated\n", p->line, p->pleft->pleft->pleft->str);
                    }
                    else if(strstr(ctype, "class ") == NULL)
                    {
                        printf("Error16 line:%d %s is not a class type\n", p->line, p->pleft->pleft->pleft->str);
                    }
                    else
                    {
                        ctype = ctype+6; //去掉前面的class
                        if(strcmp(ctype, pcurclass->name) == 0)
                        {
                            printf("Error4 line:%d using class %s in itself is not allowed\n", p->line, pcurclass->name);
                        }
                        else
                        {
                            int rint = CheckClass(p, ctype);
                            if(rint == 0)
                            {
                                printf("Error5 line:%d class %s not declarated\n", p->line, ctype);
                            }
                            else if(rint == 1)
                            {
                                printf("Error11 line:%d no data member named %s in %s\n", p->line, p->pleft->pright->pright->str, p->pleft->pleft->pleft->str);
                            }
                            else if(rint == 2)
                            {
                                printf("Error17 line:%d no function member named %s in %s\n", p->line, p->pleft->pright->pright->str, p->pleft->pleft->pleft->str);
                            }
                            else        //检查参数个数之类的错误
                            {
                                Declaration* pD = NULL;
                                int flag = 0;   //表明是否找到这个类
                                int count = symglobal.vDeclaration.size();
                                for(int i = 0; i < count; i++)
                                {
                                    pD = symglobal.vDeclaration[i];
                                    if(strcmp(ctype, pD->name) == 0)
                                    {
                                        flag = 1;
                                        break;
                                    }
                                }
                                if(flag == 1) //找到了这个类
                                {
                                    char* member = p->pleft->pright->pright->str;
                                    Symtable* pS = pD->pSym;
                                    count = pS->vDeclaration.size();
                                    for(int i = 0; i < count; i++)
                                    {
                                        pD = pS->vDeclaration[i];
                                        if(strcmp(member, pD->name) == 0 && pD->func == 0)
                                        {
                                            flag = 2;
                                            break;
                                        }
                                    }
                                }
                                if(flag == 2)   //pD保存了该变量
                                {
                                    vtype.push_back(pD->type);
                                }
                            }
                        }
                    }
                }
                else if(strcmp(p->pleft->name, "IDENTIFIER") == 0)
                {
                    char* ctype = GetType(p->pleft->str);
                    if(ctype == NULL)
                    {
                        //printf("line:%d class %s not declarated\n", p->line, ctype);
                    }
                    else if(strstr(ctype, "class ") == NULL)
                    {
                        vtype.push_back(ctype);
                    }
                }
            }
            else if(strcmp(p->name, "Call") == 0 && strcmp(p->pleft->name, "IDENTIFIER") == 0)   //直接函数调用
            {
                char* varname = p->pleft->str;
                //需要查找变量的类型
                Declaration* pD = Isfunc(varname);
                if(pD == NULL)
                {
                    printf("Error7 line:%d %s is not a function\n", p->line, varname);
                }
                else
                {
                    int paranum = pD->pSym->vDeclaration.size()-2;
                    int actualnum = Getactualnum(p->pleft->pright->pright);
                    if(paranum != actualnum)
                    {
                        printf("Error8 line:%d parameter num not matched\n", p->line);
                    }
                    else    //checktype
                    {
                        int match = CheckFunType(pD, p->pleft->pright->pright);
                        if(match == -1)
                        {
                            printf("Error9 line:%d some parameter not declrated\n", p->line);
                        }
                        else if(match == 0)
                        {
                            printf("Error10 line:%d parameter type not matched\n", p->line);
                        }
                        else
                        {
                            vtype.push_back(pD->type);
                        }
                    }
                }
            }
            else if(strcmp(p->name, "Call") == 0) //类中函数调用
            {
                if(p->pleft->pleft->pleft == NULL)
                {
                    printf("1\n");
                }
                char* pc = GetType(p->pleft->pleft->pleft->str);
                if(pc == NULL)
                {
                    printf("Error11 line:%d %s not declarated\n", p->line, p->pleft->pleft->pleft->str);
                }
                else if(strcmp(pc, "class") == 0)
                {
                    printf("Error12 line:%d %s is class\n", p->line, p->pleft->pleft->pleft->str);
                }
                else if(strstr(pc, "class ") == NULL)    //说明该变量类型不是类
                {
                    printf("Error6 line:%d the type of %s is not class\n", p->line, p->pleft->pleft->pleft->str);
                }
                else
                {
                    pc = pc+6; //去掉前面的class
                    if(strcmp(pc, pcurclass->name) == 0)
                    {
                        printf("Error4 line:%d using class %s in itself is not allowed\n", p->line, pcurclass->name);
                    }
                    else
                    {
                        int rint = CheckClass(p, pc);
                        if(rint == 0)
                        {
                            printf("Error5 line:%d class %s not declarated\n", p->line, pc);
                        }
                        else if(rint == 1)
                        {
                            printf("Error11 line:%d no data member named %s in %s\n", p->line, p->pleft->pright->pright->str, p->pleft->pleft->pleft->str);
                        }
                        else if(rint == 2)
                        {
                            printf("Error12 line:%d no function member named %s in %s\n", p->line, p->pleft->pright->pright->str, p->pleft->pleft->pleft->str);
                        }
                        else        //检查参数个数之类的错误
                        {
                            Declaration* pD = NULL;
                            int flag = 0;   //表明是否找到这个类
                            int count = symglobal.vDeclaration.size();
                            for(int i = 0; i < count; i++)
                            {
                                pD = symglobal.vDeclaration[i];
                                if(strcmp(pc, pD->name) == 0)
                                {
                                    flag = 1;
                                    break;
                                }
                            }
                            if(flag == 1) //找到了这个类
                            {
                                char* member = p->pleft->pright->pright->str;
                                Symtable* pS = pD->pSym;
                                count = pS->vDeclaration.size();
                                for(int i = 0; i < count; i++)
                                {
                                    pD = pS->vDeclaration[i];
                                    if(strcmp(member, pD->name) == 0 && pD->func == 1)
                                    {
                                        flag = 2;
                                        break;
                                    }
                                }
                            }
                            if(flag == 2)   //pD保存了该函数的声明
                            {
                                int paranum = pD->pSym->vDeclaration.size()-2;
                                int actualnum = Getactualnum(p->pleft->pright->pright->pright->pright);
                                if(paranum != actualnum)
                                {
                                    printf("Error8 line:%d parameter num not matched\n", p->line);
                                }
                                else    //checktype
                                {
                                    int match = CheckFunType(pD, p->pleft->pright->pright->pright->pright);
                                    if(match == -1)
                                    {
                                        printf("Error9 line:%d some parameter not declrated\n", p->line);
                                    }
                                    else if(match == 0)
                                    {
                                        printf("Error10 line:%d parameter type not matched\n", p->line);
                                    }
                                    else
                                    {
                                        vtype.push_back(pD->type);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        CheckType(p->pleft);
        CheckType(p->pright);
    }
}


int CheckVarExist(char* varname)
{
    Symtable* pS = Symstack.top();
    Declaration* pD = NULL;
    int count = pS->vDeclaration.size();
    for(int i = 0; i < count; i++)
    {
        pD = pS->vDeclaration[i];
        if(pD->name == NULL)
        {
            continue;
        }
        else if(strcmp(varname, pD->name) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int CheckClassExist(char* classname) //检查声明的时候类是否存在
{
    Declaration* pD = NULL;
    int count = symglobal.vDeclaration.size();
    int i = 0;
    for(i; i < count; i++)
    {
        pD = symglobal.vDeclaration[i];
        if(pD->name == NULL)
        {
            continue;
        }
        else if(strcmp(classname, pD->name) == 0)
        {
            return 1; //存在该类
        }
    }
    return 0;
}

int CheckClass(Ast* pnode, char* classname) //0表示不存在该类，1表示不存在数据成员，2表示不存在函数成员，3表示存在
{
    int isfunc = 0; //需要判断调用数据成员还是函数成员
    if(strcmp(pnode->name, "Call") == 0)
    {
        isfunc = 1; //表明是函数调用
    }
    char* varname = pnode->pleft->pleft->pleft->str;
    //需要查找变量的类型
    
    Declaration* pD = NULL;
    int flag = 0;   //表明是否找到这个类
    int count = symglobal.vDeclaration.size();
    for(int i = 0; i < count; i++)
    {
        pD = symglobal.vDeclaration[i];
        if(strcmp(classname, pD->name) == 0)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0)   //不存在这个类
    {
        return 0;
    }
    else
    {
        char* member = pnode->pleft->pright->pright->str;
        Symtable* pS = pD->pSym;
        count = pS->vDeclaration.size();
        for(int i = 0; i < count; i++)
        {
            pD = pS->vDeclaration[i];
            if(strcmp(member, pD->name) == 0 && pD->func == isfunc)
            {
                return 3;
            }
        }
    }
    if(isfunc == 1)
    {
        flag = 2;
    }
    return flag;
}

char* GetType(char* varname)
{
    stack<Symtable*> stacktemp = Symstack;
    Declaration* pD = NULL;
    int count = stacktemp.size();
    int num = 0;
    int i, j;
    for(i = 0; i < count; i++)
    {
        num = stacktemp.top()->vDeclaration.size();
        for(j = 0; j < num; j++)
        {
            pD = stacktemp.top()->vDeclaration[j];
            if(pD->name == NULL)
            {
                continue;
            }
            else if(strcmp(pD->name, varname) == 0)
            {
                return pD->type;
            }
        }
        stacktemp.pop();
    }
    return NULL;
}

int CheckExist(char* p)    //检查变量是否存在，找到返回1，否则返回0
{
    stack<Symtable*> stacktemp = Symstack;
    Symtable* pS;
    int flag = 0;   //是否找到
    int count = stacktemp.size();
    for(int i = 0; i < count; i++)
    {
        pS = stacktemp.top();
        int num = pS->vDeclaration.size();
        for(int j = 0; j < num; j++)
        {
            if(pS->vDeclaration[j]->name == NULL)
            {
                continue;
            }
            else if(strcmp(pS->vDeclaration[j]->name, p) == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            break;
        }
        stacktemp.pop();
    }
    if(flag == 1)
    {
        return 1;
    }
    return 0;
}

void print_symtable(Symtable* Sp, int level)
{
    Symtable* p = Sp;
    if(p == NULL)
    {
        return;
    }
    int k = p->vDeclaration.size();
    for(int i = 0; i<k ;i++)
    {
        if(p->vDeclaration[i]->name == NULL)
        {
            ;
        }
        else
        {
            for(int k = 0; k<level; k++)
            {
                printf("  ");
            }
            switch(p->type)
            {
                case GLOBAL:
                    printf("(global) ");
                    break;
                case CLASS:
                    printf("(class) ");
                    break;
                case FORMAL:
                    printf("(formal) ");
                    break;
                default:
                    printf("(local) ");
            }
            if(p->vDeclaration[i]->func == 1)
            {
                printf("function ");
            }
            printf("%s", p->vDeclaration[i]->type==NULL?"class":p->vDeclaration[i]->type);
            printf(" %s\n", p->vDeclaration[i]->name);
        }
        print_symtable(p->vDeclaration[i]->pSym, level+1);
    }
}
#endif