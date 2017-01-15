#include <stdio.h>

/*变量符号表的结点*/
typedef struct svar
{
    char* name;
    char* type;
    struct svar* next;
}svar;

/*函数参数作用域表*/
typedef struct spara
{
    svar* psvar;
}spara;

/*local域参数作用表*/
typedef struct slocal
{
    svar* psvar;
    vector<struct slocal*> equallocal; //和当前local平级的local
    struct slocal* deeplocal; //比当前local更深的local
}slocal;

/*函数符号表的结点*/
typedef struct sfunc
{
    char* name;
    char* rtype;
    spara* pspara;
    svar* psvar;
    vector<slocal*> vlocal;
    struct sfunc* next;
}sfunc;

/*类符号表的结点*/
typedef struct sclass
{
    char *name;
    svar* psvar;
    sfunc* psfunc;
    struct sclass* next;
}sclass;

/*全局符号表的结点*/
typedef struct sglob
{
    sclass* psclass;
}sglob;

sclass* Getclass_tail(sglob* p)
{
    sclass* ptemp = p->psclass;
    if(ptemp == NULL)
    {
        return NULL;
    }
    while(ptemp->next != NULL)
    {
        ptemp = ptemp->next;
    }
    return ptemp;
}

sfunc* Getfunc_tail(sclass* p)
{
    sfunc* ptemp = p->psfunc;
    if(ptemp == NULL)
    {
        return NULL;
    }
    while(ptemp->next != NULL)
    {
        ptemp = ptemp->next;
    }
    return ptemp;
}

svar* Getpara_tail(spara* p)
{
    svar* ptemp = p->psvar;
    if(ptemp == NULL)
    {
        return NULL;
    }
    while(ptemp->next != NULL)
    {
        ptemp = ptemp->next;
    }
    return ptemp;
}

svar* Getfuncvar_tail(svar* p)
{
    if(p == NULL)
    {
        return NULL;
    }
    while(p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

svar* Getlocalvar_tail(slocal* p)
{
    svar* ptemp = p->psvar;
    if(ptemp == NULL)
    {
        return NULL;
    }
    while(ptemp->next != NULL)
    {
        ptemp = ptemp->next;
    }
    return ptemp;
}

svar* Getclassvar_tail(svar *p)
{
    if(p == NULL)
    {
        return NULL;
    }
    while(p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

slocal* Getlocal_tail(slocal* p)
{
    while(p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

slocal* Getcurlocal(slocal* p)
{
    while(p->deeplocal != NULL)
    {
        p = p->deeplocal;
    }
    return p;
}

