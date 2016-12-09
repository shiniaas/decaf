#include "tree.h"
#include "symtable.h"

sglob sGlobal = {NULL};
sclass* pcurclass = NULL;
sfunc* pcurfunc = NULL;
int flagfunc = 0;
int flaglocal = 0;

int curscope = 0; //0:global, 1:class, 2:func, >=3:local
int infunc = 0; //表明是否是在函数的参数表内
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

void print_tree(Ast* node, int level)
{
    if(node != NULL)
    {
        if(node->line != -1)
        {
            if(strcmp(node->name, "PLBBB") == 0)
            {
                curscope = curscope+1;
            }
            else if(strcmp(node->name, "PRBBB") == 0)
            {
                curscope = curscope-1;
            }
            else if(strcmp(node->name, "KCLASS") == 0) //class的声明
            {
                sclass* p = Getclass_tail(&sGlobal);
                if(p == NULL)
                {
                    sGlobal.psclass = (sclass*)malloc(sizeof(sclass));
                    sGlobal.psclass->name = (char*)malloc(sizeof(strlen(node->pright->str)+1));
                    strcpy(sGlobal.psclass->name, node->pright->str);
                    sGlobal.psclass->psvar = NULL;
                    sGlobal.psclass->psfunc = NULL;
                    sGlobal.psclass->next = NULL;
                }
                else
                {
                    p->next = (sclass*)malloc(sizeof(sclass));
                    p->next->name = (char*)malloc(sizeof(strlen(node->pright->str)+1));
                    strcpy(p->next->name, node->pright->str);
                    p->next->psvar = NULL;
                    p->next->psfunc = NULL;
                    p->next->next = NULL;
                }
                pcurclass = Getclass_tail(&sGlobal);
            }
            else if(strcmp(node->name, "FunctionDef") == 0) //函数的声明
            {
                infunc = 1;
                Ast* pnode = node->pleft;
                sfunc* psf = Getfunc_tail(pcurclass);
                if(psf == NULL)
                {
                    pcurclass->psfunc = (sfunc*)malloc(sizeof(sfunc));
                    while(pnode != NULL)
                    {
                        if(strcmp(pnode->name, "Type") == 0)    //rtype
                        {
                            pcurclass->psfunc->rtype = (char*)malloc(sizeof(strlen(pnode->pleft->str)+1));
                            strcpy(pcurclass->psfunc->rtype, pnode->pleft->str);
                        }
                        else if(strcmp(pnode->name, "IDENTIFIER") == 0) //name
                        {
                            pcurclass->psfunc->name = (char*)malloc(sizeof(strlen(pnode->str)+1));
                            strcpy(pcurclass->psfunc->name, pnode->str);
                        }
                        pnode = pnode->pright;
                    }
                    pcurclass->psfunc->pspara = (spara*)malloc(sizeof(spara));
                    pcurclass->psfunc->pspara->psvar = NULL;
                    pcurclass->psfunc->psvar = NULL;
                    pcurclass->psfunc->pslocal = (slocal*)malloc(sizeof(slocal));
                    pcurclass->psfunc->pslocal->psvar = NULL;
                    pcurclass->psfunc->next = NULL;
                }
                else
                {
                    psf->next = (sfunc*)malloc(sizeof(sfunc));
                    while(pnode != NULL)
                    {
                        if(strcmp(pnode->name, "Type") == 0)    //rtype
                        {
                            psf->next->rtype = (char*)malloc(sizeof(strlen(pnode->pleft->str)+1));
                            strcpy(psf->next->rtype, pnode->pleft->str);
                        }
                        else if(strcmp(pnode->name, "IDENTIFIER") == 0) //name
                        {
                            psf->next->name = (char*)malloc(sizeof(strlen(pnode->str)+1));
                            strcpy(psf->next->name, pnode->str);
                        }
                        pnode = pnode->pright;
                    }
                    psf->next->pspara = (spara*)malloc(sizeof(spara));
                    psf->next->pspara->psvar = NULL;
                    psf->next->psvar = NULL;
                    psf->next->pslocal = (slocal*)malloc(sizeof(slocal));
                    psf->next->pslocal->psvar = NULL;
                    psf->next->next = NULL;
                }
                pcurfunc = Getfunc_tail(pcurclass);
            }
            else if(infunc == 1 && strcmp(node->name, "ORB") == 0)
            {
                infunc = 0; //参数声明结束
            }
            else if(strcmp(node->name, "Variable") == 0)
            {
                svar* psv = NULL;
                if(infunc == 1)
                {
                    psv = Getpara_tail(pcurfunc->pspara);
                    if(psv == NULL)
                    {
                        pcurfunc->pspara->psvar = (svar*)malloc(sizeof(svar));
                        pcurfunc->pspara->psvar->type = (char*)malloc(sizeof(node->pleft->pleft->str)+1);
                        strcpy(pcurfunc->pspara->psvar->type, node->pleft->pleft->str);
                        pcurfunc->pspara->psvar->name = (char*)malloc(sizeof(node->pleft->pright->str)+1);
                        strcpy(pcurfunc->pspara->psvar->name, node->pleft->pright->str);
                        pcurfunc->pspara->psvar->next = NULL;
                    }
                    else
                    {
                        psv->next = (svar*)malloc(sizeof(svar));
                        psv->next->type = (char*)malloc(sizeof(node->pleft->pleft->str)+1);
                        strcpy(psv->next->type, node->pleft->pleft->str);
                        psv->next->name = (char*)malloc(sizeof(node->pleft->pright->str)+1);
                        strcpy(psv->next->name, node->pleft->pright->str);
                        psv->next->next = NULL;
                    }
                }
            }
        }
        print_tree(node->pleft, level+1);
        print_tree(node->pright, level);
    }
}

void print_symtable()
{
    printf("print_symtable\n");
    sclass* p = sGlobal.psclass;
    svar* psvart = NULL;
    sfunc* psfunct = NULL;
    while(p != NULL)
    {
        printf("class:%s\n", p->name);
        psfunct = p->psfunc;
        while(psfunct != NULL)
        {
            printf("func:%s %s\n",psfunct->rtype, psfunct->name);
            psvart = psfunct->pspara->psvar;
            while(psvart != NULL)
            {
                printf("para:%s %s\n", psvart->type, psvart->name);
                psvart = psvart->next;
            }
            psfunct = psfunct->next;
        }
        p = p->next;
    }
}