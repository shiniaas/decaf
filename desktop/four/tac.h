#include "tree.h"
#include "symtable.h"
#include <map>

#define varandnum map<string, int>



class TacNode
{
public:
    char cmd[50];
    char d[20];
    char r1[20];
    char r2[20];
};

class Functy
{
public:
    char* name;
    vector<TacNode*> TacList;
};

class Vtable
{
public:
    Vtable* father;
    char* name;
    int addr;   //记录alloc的地址，用于访问成员变量和函数
    vector<Functy*> FunList;
    vector<TacNode*> TacList;
};

class classvarname
{
public:
    char* name;
    char* type;
};

class label
{
public:
    int num;
    int scope;
};

class whilelabel
{
public:
    int num;
    int backnum;
    int scope;
};

class forlabel
{
public:
    int num;
    int backnum;
    int scope;
    vector<TacNode*> vT;
};

vector<Vtable*> table;
vector<label*> vlabel;
vector<whilelabel*> vwhilelabel;
vector<forlabel*> vforlabel;
void create_vtable(Symtable* phead);
void print_vtable();
int Get_class_var(Declaration* pD);
int TranslateExpr(Ast* pnode);
int curnum = 1;
int curlabel = 1;
int cur_classnum = -1;
int cur_scope = 0;
int in_func = 0;
int simplestmtnum = 0;

Vtable* ptable = NULL;
Functy* pcurFuncty = NULL;
stack<varandnum> numstack; //函数形参和局部变量被抽象为标号
vector<TacNode*> vleft; //获取等式右边的变量
vector<classvarname*> vclass;
char* Get_var_class(char* p);

int Get_lable()
{
    return curlabel++;
}
int Get_num(string name)
{
    int ret = 0;
    if(name=="")
    {
        return curnum++;
    }
    stack<varandnum> stemp = numstack;
    while(!stemp.empty())
    {
        varandnum v = stemp.top();
        if(v.count(name)!=0)
        {
            return v[name];
        }
        stemp.pop();
    }
    varandnum* pv = new varandnum;
    ret = curnum++;
    (*pv)[name] = ret;
    numstack.push(*pv);
    return ret;
}

void create_vtable(Symtable* phead)
{
    int vtable_size = symglobal.vDeclaration.size();
    TacNode* pT = NULL;
    Vtable* pV = NULL;
    Declaration* pD = NULL, *pDt = NULL;
    int i = 0, j = 0;
    for(i = 0; i<vtable_size; i++)
    {
        pD = phead->vDeclaration[i];
        pV = new Vtable;
        table.push_back(pV);
        pT = new TacNode;
        pV->TacList.push_back(pT);
//        strcpy(pT->cmd, "VTABLE(_");
//        strcat(pT->cmd, pD->name);
//        strcat(pT->cmd, "){\n");
        if(pD->father == NULL)  //判断是否是继承
        {
            pT = new TacNode;
            pV->TacList.push_back(pT);
            strcpy(pT->cmd, "  <empty>\n");
        }
        else
        {
            pT = new TacNode;
            pV->TacList.push_back(pT);
            strcpy(pT->cmd, "  _");
            strcat(pT->cmd, pD->father);
            strcat(pT->cmd, "\n");
        }
        pV->name = (char*)malloc(strlen(pD->name)+1);
        strcpy(pV->name, pD->name);
        pT = new TacNode;
        pV->TacList.push_back(pT);
        strcpy(pT->cmd, "  ");
        strcat(pT->cmd, pD->name);
        strcat(pT->cmd, "\n");
        pT = new TacNode;
        pV->TacList.push_back(pT);
        for(j = 0; j < pD->pSym->vDeclaration.size(); j++)
        {
            pDt = pD->pSym->vDeclaration[j];
            if(pDt->func == 1) //是函数
            {
                pT = new TacNode;
                pV->TacList.push_back(pT);
                strcpy(pT->cmd, "  _");
                strcat(pT->cmd, pD->name);
                strcat(pT->cmd, ".");
                strcat(pT->cmd, pDt->name);
                strcat(pT->cmd, ";\n");
            }
        }
//        pT = new TacNode;
//        pV->TacList.push_back(pT);
//        strcpy(pT->cmd, "}\n");
        //构造对应的new函数
        Functy* pF = NULL;
        pF = new Functy;
        pV->FunList.push_back(pF);
        pF->name = (char*)malloc(sizeof(4));
        strcpy(pF->name, "New");
//        pT = new TacNode;
//        pF->TacList.push_back(pT);
//        strcpy(pT->cmd, "FUNCTION(_");
//        strcat(pT->cmd, pD->name);
//        strcat(pT->cmd, "_");
//        strcat(pT->cmd, pF->name);
//        strcat(pT->cmd, "){\n");
//        pT = new TacNode;
//        pF->TacList.push_back(pT);
//        strcpy(pT->cmd, "_");
//        strcat(pT->cmd, pD->name);
//        strcat(pT->cmd, "_");
//        strcat(pT->cmd, pF->name);
//        strcat(pT->cmd, ":\n");
        int t1 = Get_num("");
        pT = new TacNode;
        pF->TacList.push_back(pT);
        int varnum = Get_class_var(pD);
        sprintf(pT->cmd, "  _T%d=%d\n", t1, (varnum+1)*4);
        pT = new TacNode;
        pF->TacList.push_back(pT);
        sprintf(pT->cmd, "  parm _T%d\n", t1);
        int t2 = Get_num("");
        pT = new TacNode;
        pF->TacList.push_back(pT);
        sprintf(pT->cmd, "  _T%d=call _Alloc\n", t2);
        pV->addr = t2;
        int t3 = Get_num("");
        pT = new TacNode;
        pF->TacList.push_back(pT);
        sprintf(pT->cmd, "  _T%d=0\n", t3);
        for(int i=0; i<varnum; i++)
        {
            pT = new TacNode;
            pF->TacList.push_back(pT);
            sprintf(pT->cmd, "  *(_T%d+%d)=_T%d\n", t2, (i+1)*4, t3);
        }
        int t4 = Get_num("");
        pT = new TacNode;
        pF->TacList.push_back(pT);
        sprintf(pT->cmd, "  _T%d=VTBL<%s>\n", t4, pD->name);
        pT = new TacNode;
        pF->TacList.push_back(pT);
        sprintf(pT->cmd, "  *(_T%d+0)=_T%d\n", t2, t4);
        pT = new TacNode;
        pF->TacList.push_back(pT);
        sprintf(pT->cmd, "  return _T%d\n", t2);
    }
}


//需要用到栈结构，类的成员变量用addr+偏移地址表示，局部变量和函数参数用_T表示
void create_tac(Ast* node)
{
    if(node != NULL)
    {
        if(node->line != -1)
        {
            if(strcmp(node->name, "PLBBB") == 0)
            {
                cur_scope = cur_scope+1;
            }
            else if(strcmp(node->name, "PRBBB") == 0)
            {
                if(cur_scope == 3)
                {
                    cur_scope = cur_scope-2;  //函数定义完成之后应该回到CLASS域
                }
                else
                {
                    cur_scope = cur_scope-1;
                }
                if(vlabel.size() != 0)
                {
                    label* pl = vlabel[vlabel.size()-1];
                    if(pl->scope == cur_scope)
                    {
                        TacNode* pT = new TacNode;
                        pcurFuncty->TacList.push_back(pT);
                        sprintf(pT->cmd, "label%d\n", pl->num);
                        vlabel.pop_back();
                    }
                }
                else if(vwhilelabel.size()!=0)
                {
                    whilelabel* pw = vwhilelabel[vwhilelabel.size()-1];
                    if(pw->scope == cur_scope)
                    {
                        TacNode* pT = new TacNode;
                        pcurFuncty->TacList.push_back(pT);
                        
                        sprintf(pT->cmd, "  goto label%d\n", pw->backnum);
                        pT = new TacNode;
                        pcurFuncty->TacList.push_back(pT);
                        sprintf(pT->cmd, "label%d\n", pw->num);
                        vwhilelabel.pop_back();
                    }
                }
                else if(vforlabel.size()!=0)
                {
                    forlabel* pf = vforlabel[vforlabel.size()-1];
                    if(pf->scope == cur_scope)
                    {
                        TacNode* pT = NULL;
                        int i = 0;
                        for(i = 0; i<pf->vT.size(); i++)
                        {
                            pT = pf->vT[i];
                            pcurFuncty->TacList.push_back(pT);
                        }
                        pT = new TacNode;
                        pcurFuncty->TacList.push_back(pT);
                        
                        
                        
                        sprintf(pT->cmd, "  goto label%d\n", pf->backnum);
                        pT = new TacNode;
                        pcurFuncty->TacList.push_back(pT);
                        sprintf(pT->cmd, "label%d\n", pf->num);
                        vforlabel.pop_back();
                    }
                }
            }
            else if(in_func == 1 && strcmp(node->name, "OLB") == 0)
            {
                cur_scope = cur_scope + 1;
            }
            else if(in_func == 1 && strcmp(node->name, "ORB") == 0)
            {
                in_func = 0; //参数声明结束
            }
            else if(strcmp(node->name, "ClassDef") == 0) //class的声明
            {
                ++cur_classnum;
            }
            else if(strcmp(node->name, "FunctionDef") == 0) //函数的声明
            {
                in_func = 1;
                while(!numstack.empty())    //清空形参和局部变量栈
                {
                    numstack.pop();
                }
                vclass.clear();
                Vtable* pV = table[cur_classnum];
                pcurFuncty = new Functy;
                pcurFuncty->name = NULL;
                pV->FunList.push_back(pcurFuncty);
                Ast* pnode = node->pleft;
                while(pnode != NULL)
                {
                    if(strcmp(pnode->name, "IDENTIFIER") == 0) //函数名
                    {
                        pcurFuncty->name = (char*)malloc(sizeof(strlen(pnode->str)+1));
                        strcpy(pcurFuncty->name, pnode->str);
                    }
                    pnode = pnode->pright;
                }
            }
            else if(strcmp(node->name, "Variable") == 0)
            {
                if(cur_scope >= 3 && strcmp(node->pleft->pleft->name, "KCLASS") != 0)
                {
                    int t = Get_num(node->pleft->pright->str);
                    TacNode* pT = new TacNode;
                    pcurFuncty->TacList.push_back(pT);
                    
                    
                    
                    sprintf(pT->cmd, "  _T%d=0\n", t);
                }
                else if(cur_scope >= 3) //类成员变量的声明
                {
                    int t = Get_num(node->pleft->pright->str);
                    TacNode* pT = new TacNode;
                    pcurFuncty->TacList.push_back(pT);
                    
                    
                    
                    sprintf(pT->cmd, "  _T%d=call_%s_New\n", t, node->pleft->pleft->pright->str);
                    classvarname *pc = new classvarname;
                    pc->type = (char*)malloc(strlen(node->pleft->pleft->pright->str)+1);
                    strcpy(pc->type,node->pleft->pleft->pright->str);
                    pc->name = (char*)malloc(strlen(node->pleft->pright->str)+1);
                    strcpy(pc->name,node->pleft->pright->str);
                    vclass.push_back(pc);
                }
            }
            else if(strcmp(node->name, "SimpleStmt") == 0)
            {
                if(simplestmtnum > 0)
                {
                    simplestmtnum--;
                }
                else if(strcmp(node->pleft->name, "Call") == 0 && strcmp(node->pleft->pleft->name, "IDENTIFIER") == 0)   //直接函数调用
                {
                    Ast* p = node->pleft->pleft->pright->pright->pleft;
                    vector<int> constant_num;
                    while(p!=NULL)
                    {
                        if(strcmp(p->name, "Expr") == 0) //表达式
                        {
                            if(strcmp(p->pleft->name, "Constant") == 0)  //参数为常量
                            {
                                int t = Get_num("");
                                constant_num.push_back(t);
                                TacNode* pT = new TacNode;
                                pcurFuncty->TacList.push_back(pT);
                                
                                
                                
                                sprintf(pT->cmd, "  _T%d=%d\n", t, p->pleft->pleft->intgr);
                            }
                        }
                        p = p->pright;
                    }
                    int k = 0;
                    p = node->pleft->pleft->pright->pright->pleft;
                    while(p!=NULL)
                    {
                        if(strcmp(p->name, "Expr") == 0)
                        {
                            if(strcmp(p->pleft->name, "Constant") == 0)  //参数为常量
                            {
                                TacNode* pT = new TacNode;
                                pcurFuncty->TacList.push_back(pT);
                                sprintf(pT->cmd, "  parm _T%d\n", constant_num[k++]);
                            }
                            else if(strcmp(p->pleft->name, "LValue") == 0)
                            {
                                //判断是否是局部变量
                                stack<varandnum> stemp = numstack;
                                int var_num = 0;
                                while(!stemp.empty())
                                {
                                    varandnum v = stemp.top();
                                    if(v.count(p->pleft->pleft->str)!=0)
                                    {
                                        var_num = v[p->pleft->pleft->str];
                                        break;
                                    }
                                    stemp.pop();
                                }
                                if(var_num!=0)  //说明是局部变量
                                {
                                    TacNode* pT = new TacNode;
                                    pcurFuncty->TacList.push_back(pT);
                                    sprintf(pT->cmd, "  parm _T%d\n", var_num);
                                }
                                else    //类的成员变量
                                {
                                    int t1 = table[cur_classnum]->addr;
                                    int i = 0, count = 0;
                                    Declaration* pD = symglobal.vDeclaration[cur_classnum];
                                    for(i = 0; i<pD->pSym->vDeclaration.size(); i++)
                                    {
                                        if(pD->pSym->vDeclaration[i]->func == 0)
                                        {
                                            ++count;
                                            if(strcmp(pD->pSym->vDeclaration[i]->name, p->pleft->pleft->name) == 0)
                                            {
                                                break;
                                            }
                                        }
                                    }
                                    TacNode* pT = new TacNode;
                                    pcurFuncty->TacList.push_back(pT);
                                    sprintf(pT->cmd, "  parm *(_T%d+%d)\n", t1, count*4);
                                }
                            }
                        }
                        p = p->pright;
                    }
                    TacNode* pT = new TacNode;
                    pcurFuncty->TacList.push_back(pT);
                    sprintf(pT->cmd, "  call _%s\n", node->pleft->pleft->str);
                }
                else if(strcmp(node->pleft->name, "Call") == 0) //从类中调用函数
                {
                    Ast* p = node->pleft->pleft->pright->pright->pright->pright->pleft;
                    vector<int> constant_num;
                    while(p!=NULL)
                    {
                        if(strcmp(p->name, "Expr") == 0) //表达式
                        {
                            if(strcmp(p->pleft->name, "Constant") == 0)  //参数为常量
                            {
                                int t = Get_num("");
                                constant_num.push_back(t);
                                TacNode* pT = new TacNode;
                                pcurFuncty->TacList.push_back(pT);
                                
                                sprintf(pT->cmd, "  _T%d=%d\n", t, p->pleft->pleft->intgr);
                            }
                        }
                        p = p->pright;
                    }
                    int k = 0;
                    p = node->pleft->pleft->pright->pright->pright->pright->pleft;
                    TacNode* pT = new TacNode;
                    pcurFuncty->TacList.push_back(pT);
                    sprintf(pT->cmd, "  parm _T%d\n", Get_num(node->pleft->pleft->pleft->pleft->str));
                    while(p!=NULL)
                    {
                        if(strcmp(p->name, "Expr") == 0)
                        {
                            if(strcmp(p->pleft->name, "Constant") == 0)  //参数为常量
                            {
                                TacNode* pT = new TacNode;
                                pcurFuncty->TacList.push_back(pT);
                                sprintf(pT->cmd, "  parm _T%d\n", constant_num[k++]);
                            }
                            else if(strcmp(p->pleft->name, "LValue") == 0)
                            {
                                //判断是否是局部变量
                                stack<varandnum> stemp = numstack;
                                int var_num = 0;
                                while(!stemp.empty())
                                {
                                    varandnum v = stemp.top();
                                    if(v.count(p->pleft->pleft->str)!=0)
                                    {
                                        var_num = v[p->pleft->pleft->str];
                                        break;
                                    }
                                    stemp.pop();
                                }
                                if(var_num!=0)  //说明是局部变量
                                {
                                    TacNode* pT = new TacNode;
                                    pcurFuncty->TacList.push_back(pT);
                                    sprintf(pT->cmd, "  parm _T%d\n", var_num);
                                }
                                else    //类的成员变量
                                {
                                    int t1 = table[cur_classnum]->addr;
                                    int i = 0, count = 0;
                                    Declaration* pD = symglobal.vDeclaration[cur_classnum];
                                    for(i = 0; i<pD->pSym->vDeclaration.size(); i++)
                                    {
                                        if(pD->pSym->vDeclaration[i]->func == 0)
                                        {
                                            ++count;
                                            if(strcmp(pD->pSym->vDeclaration[i]->name, p->pleft->pleft->name) == 0)
                                            {
                                                break;
                                            }
                                        }
                                    }
                                    TacNode* pT = new TacNode;
                                    pcurFuncty->TacList.push_back(pT);
                                    sprintf(pT->cmd, "  parm *(_T%d+%d)\n", t1, count*4);
                                }
                            }
                        }
                        p = p->pright;
                    }
                    pT = new TacNode;
                    pcurFuncty->TacList.push_back(pT);
                    sprintf(pT->cmd, "  call _%s\n", node->pleft->pleft->pright->pright->str);
                }
                else if(strcmp(node->pleft->name, "LValue") == 0)   //赋值表达式
                {
                    TacNode* pT = NULL;
                    vleft.clear();
                    int addr = TranslateExpr(node->pleft->pright->pright->pleft); //获取等号右边的变量
                    for(int i = 0; i<vleft.size(); i++)
                    {
                        pT = new TacNode;
                        pcurFuncty->TacList.push_back(pT);
                        strcpy(pT->cmd, vleft[i]->cmd);
                    }
                    pT = new TacNode;
                    pcurFuncty->TacList.push_back(pT);
                    int addr1 = Get_num(node->pleft->pleft->str);
                    sprintf(pT->cmd, "  _T%d=_T%d\n", addr1, addr);
                }
                //                printf("exit simplestmt\n");
            }
            else if(strcmp(node->name, "IfStmt") == 0)  //if语句
            {
                label* pl = new label;
                vlabel.push_back(pl);
                pl->scope = cur_scope;
                TacNode* pT = NULL;
                vleft.clear();
                int addr = TranslateExpr(node->pleft->pright->pright->pleft->pleft);
                for(int i = 0; i<vleft.size(); i++)
                {
                    pT = new TacNode;
                    pcurFuncty->TacList.push_back(pT);
                    strcpy(pT->cmd, vleft[i]->cmd);
                }
                int lablenumtrue = Get_lable();
                pT = new TacNode;
                pcurFuncty->TacList.push_back(pT);
                sprintf(pT->cmd, "  if _T%d goto label%d\n", addr, lablenumtrue);
                int lablenum = Get_lable();
                pT = new TacNode;
                pcurFuncty->TacList.push_back(pT);
                sprintf(pT->cmd, "  goto label%d\n", lablenum);
                pl->num = lablenum;
                pT = new TacNode;
                pcurFuncty->TacList.push_back(pT);
                sprintf(pT->cmd, "label%d\n", lablenumtrue);
                
            }
            else if(strcmp(node->name, "WhileStmt") == 0)
            {
                whilelabel* pw;
                pw = new whilelabel;
                vwhilelabel.push_back(pw);
                pw->scope = cur_scope;
                TacNode* pT = NULL;
                vleft.clear();
                int addr = TranslateExpr(node->pleft->pright->pright->pleft->pleft);
                for(int i = 0; i<vleft.size(); i++)
                {
                    pT = new TacNode;
                    pcurFuncty->TacList.push_back(pT);
                    strcpy(pT->cmd, vleft[i]->cmd);
                }
                int labelnumtrue = Get_lable();
                int labelnumback = Get_lable();
                pT = new TacNode;
                pcurFuncty->TacList.push_back(pT);
                sprintf(pT->cmd, "  label%d\n", labelnumback);
                pw->backnum = labelnumback;
                pT = new TacNode;
                pcurFuncty->TacList.push_back(pT);
                sprintf(pT->cmd, "  if _T%d goto label%d\n", addr, labelnumtrue);
                int labelnum = Get_lable();
                pT = new TacNode;
                pcurFuncty->TacList.push_back(pT);
                sprintf(pT->cmd, "  goto label%d\n", labelnum);
                pw->num = labelnum;
                pT = new TacNode;
                pcurFuncty->TacList.push_back(pT);
                sprintf(pT->cmd, "label%d\n", labelnumtrue);
                
            }
            else if(strcmp(node->name, "ForStmt") == 0)
            {
                simplestmtnum = 2;
                forlabel* pf;
                pf = new forlabel;
                vforlabel.push_back(pf);
                pf->scope = cur_scope;
                TacNode* pT = NULL;
                vleft.clear();
                int addr = TranslateExpr(node->pleft->pright->pright->pleft); //获取等号右边的变量
                for(int i = 0; i<vleft.size(); i++)
                {
                    pT = new TacNode;
                    pcurFuncty->TacList.push_back(pT);
                    strcpy(pT->cmd, vleft[i]->cmd);
                }
                pT = new TacNode;
                pcurFuncty->TacList.push_back(pT);
                int addr1 = Get_num(node->pleft->pright->pright->pleft->pleft->str);
                sprintf(pT->cmd, "  _T%d=_T%d\n", addr1, addr);
                
                
                
                vleft.clear();
                int labelfor = Get_lable();
                pT = new TacNode;
                pcurFuncty->TacList.push_back(pT);
                sprintf(pT->cmd, "label%d\n", labelfor);
                pf->backnum = labelfor;
                int booladdr = TranslateExpr(node->pleft->pright->pright->pright->pright->pleft->pleft);
                for(int i = 0; i<vleft.size(); i++)
                {
                    pT = new TacNode;
                    pcurFuncty->TacList.push_back(pT);
                    strcpy(pT->cmd, vleft[i]->cmd);
                }
                vleft.clear();
                int labelnumtrue = Get_lable();
                pT = new TacNode;
                pcurFuncty->TacList.push_back(pT);
                sprintf(pT->cmd, "  if _T%d goto label%d\n", booladdr, labelnumtrue);
                int lablenum = Get_lable();
                pT = new TacNode;
                pcurFuncty->TacList.push_back(pT);
                sprintf(pT->cmd, "  goto label%d\n", lablenum);
                
                pf->num = lablenum;
                
                pT = new TacNode;
                pcurFuncty->TacList.push_back(pT);
                sprintf(pT->cmd, "label%d\n", labelnumtrue);
                
                for(int i = 0; i<vleft.size(); i++)
                {
                    pT = new TacNode;
                    pcurFuncty->TacList.push_back(pT);
                    strcpy(pT->cmd, vleft[i]->cmd);
                }
                vleft.clear();
                
                int addr2 = TranslateExpr(node->pleft->pright->pright->pright->pright->pright->pright->pleft->pright->pright->pleft); //获取等号右边的变量
                for(int i = 0; i<vleft.size(); i++)
                {
                    pT = new TacNode;
                    pf->vT.push_back(pT);
                    strcpy(pT->cmd, vleft[i]->cmd);
                }
                pT = new TacNode;
                pf->vT.push_back(pT);
                int addr3 = Get_num(node->pleft->pright->pright->pright->pright->pright->pright->pleft->pleft->str);
                sprintf(pT->cmd, "  _T%d=_T%d\n", addr3, addr2);
                
                
            }
            else if(strcmp(node->name, "ReturnStmt") == 0)  //用于判断函数返回值
            {
                TacNode* pT = NULL;
                if(node->pleft->pright == NULL)
                {
                    pT = new TacNode;
                    pcurFuncty->TacList.push_back(pT);
                    sprintf(pT->cmd, "  %s\n", "return");
                }
                else if(strcmp(node->pleft->pright->pleft->name, "Constant") == 0)
                {
                    int addr = Get_num("");
                    pT = new TacNode;
                    pcurFuncty->TacList.push_back(pT);
                    sprintf(pT->cmd, "  _T%d=%d\n", addr, node->pleft->pright->pleft->pleft->intgr);
                    pT = new TacNode;
                    pcurFuncty->TacList.push_back(pT);
                    sprintf(pT->cmd, "  return _T%d\n", addr);
                }
                else
                {
                    int addr = Get_num(node->pleft->pright->pleft->pleft->str);
                    pT = new TacNode;
                    pcurFuncty->TacList.push_back(pT);
                    sprintf(pT->cmd, "  return _T%d\n", addr);
                }
            }
        }
        create_tac(node->pleft);
        create_tac(node->pright);
    }
}

int TranslateExpr(Ast* pnode)   //返回值为地址
{
    if(pnode!=NULL)
    {
        if(strcmp(pnode->name, "Constant") == 0)
        {
            int addr = Get_num("");
            TacNode* pT = new TacNode;
            sprintf(pT->cmd, "  _T%d=%d\n", addr, pnode->pleft->intgr);
            vleft.push_back(pT);
            return addr;
        }
        else if(strcmp(pnode->name, "LValue") == 0)
        {
            if(strcmp(pnode->pleft->name, "Expr") == 0) //类中成员变量
            {
                char* cclass = Get_var_class(pnode->pleft->pleft->pleft->str);
                Declaration* pD = NULL;
                int i = 0;
                int count = 0;
                for(i = 0; i<symglobal.vDeclaration.size(); i++)
                {
                    if(strcmp(symglobal.vDeclaration[i]->name, cclass) == 0)
                    {
                        break;
                    }
                }
                pD = symglobal.vDeclaration[i];
                for(i = 0; i<pD->pSym->vDeclaration.size(); i++)
                {
                    if(pD->pSym->vDeclaration[i]->func == 0)
                    {
                        ++count;
                        if(strcmp(pD->pSym->vDeclaration[i]->name, pnode->pleft->pright->pright->str) == 0)
                        {
                            break;
                        }
                    }
                }
                int addr = Get_num("");
                int addr1 = Get_num(pnode->pleft->pleft->pleft->str);
                TacNode* pT = new TacNode;
                vleft.push_back(pT);
                sprintf(pT->cmd, "  _T%d=*(_T%d+%d)\n", addr, addr1,count*4);
                return addr;
            }
            else
            {
                int addr = Get_num(pnode->pleft->str);
                int addr1 = Get_num("");
                TacNode* pT = new TacNode;
                sprintf(pT->cmd, "  _T%d=_T%d\n", addr1, addr);
                vleft.push_back(pT);
                return addr1;
            }
        }
        else if(strcmp(pnode->name, "Call") == 0)   //函数调用
        {
            if(strcmp(pnode->pleft->name, "IDENTIFIER") == 0)   //直接函数调用
            {
                Ast* p = pnode->pleft->pright->pright->pleft;
                vector<int> constant_num;
                while(p!=NULL)
                {
                    if(strcmp(p->name, "Expr") == 0) //表达式
                    {
                        if(strcmp(p->pleft->name, "Constant") == 0)  //参数为常量
                        {
                            int t = Get_num("");
                            constant_num.push_back(t);
                            TacNode* pT = new TacNode;
                            vleft.push_back(pT);
                            sprintf(pT->cmd, "  _T%d=%d\n", t, p->pleft->pleft->intgr);
                        }
                    }
                    p = p->pright;
                }
                int k = 0;
                p = pnode->pleft->pright->pright->pleft;
                while(p!=NULL)
                {
                    if(strcmp(p->name, "Expr") == 0)
                    {
                        if(strcmp(p->pleft->name, "Constant") == 0)  //参数为常量
                        {
                            TacNode* pT = new TacNode;
                            vleft.push_back(pT);
                            sprintf(pT->cmd, "  parm _T%d\n", constant_num[k++]);
                        }
                        else if(strcmp(p->pleft->name, "LValue") == 0)
                        {
                            //判断是否是局部变量
                            stack<varandnum> stemp = numstack;
                            int var_num = 0;
                            while(!stemp.empty())
                            {
                                varandnum v = stemp.top();
                                if(v.count(p->pleft->pleft->str)!=0)
                                {
                                    var_num = v[p->pleft->pleft->str];
                                    break;
                                }
                                stemp.pop();
                            }
                            if(var_num!=0)  //说明是局部变量
                            {
                                TacNode* pT = new TacNode;
                                vleft.push_back(pT);
                                sprintf(pT->cmd, "  parm _T%d\n", var_num);
                            }
                            else    //类的成员变量
                            {
                                int t1 = table[cur_classnum]->addr;
                                int i = 0, count = 0;
                                Declaration* pD = symglobal.vDeclaration[cur_classnum];
                                for(i = 0; i<pD->pSym->vDeclaration.size(); i++)
                                {
                                    if(pD->pSym->vDeclaration[i]->func == 0)
                                    {
                                        ++count;
                                        if(strcmp(pD->pSym->vDeclaration[i]->name, p->pleft->pleft->name) == 0)
                                        {
                                            break;
                                        }
                                    }
                                }
                                TacNode* pT = new TacNode;
                                vleft.push_back(pT);
                                sprintf(pT->cmd, "  parm *(_T%d+%d)\n", t1, count*4);
                            }
                        }
                    }
                    p = p->pright;
                }
                TacNode* pT = new TacNode;
                vleft.push_back(pT);
                int addr = Get_num("");
                sprintf(pT->cmd, "  _T%d=call _%s\n", addr, pnode->pleft->str);
                return addr;
            }
            else    //类中函数调用
            {
                Ast* p = pnode->pleft->pright->pright->pright->pright->pleft;
                vector<int> constant_num;
                while(p!=NULL)
                {
                    if(strcmp(p->name, "Expr") == 0) //表达式
                    {
                        if(strcmp(p->pleft->name, "Constant") == 0)  //参数为常量
                        {
                            int t = Get_num("");
                            constant_num.push_back(t);
                            TacNode* pT = new TacNode;
                            vleft.push_back(pT);
                            sprintf(pT->cmd, "  _T%d=%d\n", t, p->pleft->pleft->intgr);
                        }
                    }
                    p = p->pright;
                }
                int k = 0;
                p = pnode->pleft->pright->pright->pright->pright->pleft;
                TacNode* pT = new TacNode;
                vleft.push_back(pT);
                sprintf(pT->cmd, "  parm _T%d\n", Get_num(pnode->pleft->pleft->pleft->str));
                while(p!=NULL)
                {
                    if(strcmp(p->name, "Expr") == 0)
                    {
                        if(strcmp(p->pleft->name, "Constant") == 0)  //参数为常量
                        {
                            TacNode* pT = new TacNode;
                            vleft.push_back(pT);
                            sprintf(pT->cmd, "  parm _T%d\n", constant_num[k++]);
                        }
                        else if(strcmp(p->pleft->name, "LValue") == 0)
                        {
                            //判断是否是局部变量
                            stack<varandnum> stemp = numstack;
                            int var_num = 0;
                            while(!stemp.empty())
                            {
                                varandnum v = stemp.top();
                                if(v.count(p->pleft->pleft->str)!=0)
                                {
                                    var_num = v[p->pleft->pleft->str];
                                    break;
                                }
                                stemp.pop();
                            }
                            if(var_num!=0)  //说明是局部变量
                            {
                                TacNode* pT = new TacNode;
                                vleft.push_back(pT);
                                sprintf(pT->cmd, "  parm _T%d\n", var_num);
                            }
                            else    //类的成员变量
                            {
                                int t1 = table[cur_classnum]->addr;
                                int i = 0, count = 0;
                                Declaration* pD = symglobal.vDeclaration[cur_classnum];
                                for(i = 0; i<pD->pSym->vDeclaration.size(); i++)
                                {
                                    if(pD->pSym->vDeclaration[i]->func == 0)
                                    {
                                        ++count;
                                        if(strcmp(pD->pSym->vDeclaration[i]->name, p->pleft->pleft->name) == 0)
                                        {
                                            break;
                                        }
                                    }
                                }
                                TacNode* pT = new TacNode;
                                vleft.push_back(pT);
                                sprintf(pT->cmd, "  parm *(_T%d+%d)\n", t1, count*4);
                            }
                        }
                    }
                    p = p->pright;
                }
                pT = new TacNode;
                vleft.push_back(pT);
                int addr = Get_num("");
                sprintf(pT->cmd, "  _T%d=call _%s\n", addr, pnode->pleft->pright->pright->str);
            }
        }
        
        else if(pnode->pright!=NULL && strcmp(pnode->pright->name, "OADD") == 0)
        {
            int addr1 = TranslateExpr(pnode->pleft);
            int addr2 = TranslateExpr(pnode->pright->pright->pleft);
            int addr = Get_num("");
            TacNode* pT = new TacNode;
            sprintf(pT->cmd, "  _T%d=_T%d+_T%d\n", addr, addr1, addr2);
            vleft.push_back(pT);
            return addr;
        }
        else if(pnode->pright!=NULL && strcmp(pnode->pright->name, "OSUB") == 0)
        {
            int addr1 = TranslateExpr(pnode->pleft);
            int addr2 = TranslateExpr(pnode->pright->pright->pleft);
            int addr = Get_num("");
            TacNode* pT = new TacNode;
            sprintf(pT->cmd, "  _T%d=_T%d-_T%d\n", addr, addr1, addr2);
            vleft.push_back(pT);
            return addr;
        }
        else if(pnode->pright!=NULL && strcmp(pnode->pright->name, "OMUL") == 0)
        {
            int addr1 = TranslateExpr(pnode->pleft);
            int addr2 = TranslateExpr(pnode->pright->pright->pleft);
            int addr = Get_num("");
            TacNode* pT = new TacNode;
            sprintf(pT->cmd, "  _T%d=_T%d*_T%d\n", addr, addr1, addr2);
            vleft.push_back(pT);
            return addr;
        }
        else if(pnode->pright!=NULL && strcmp(pnode->pright->name, "ODIV") == 0)
        {
            int addr1 = TranslateExpr(pnode->pleft);
            int addr2 = TranslateExpr(pnode->pright->pright->pleft);
            int addr = Get_num("");
            TacNode* pT = new TacNode;
            sprintf(pT->cmd, "  _T%d=_T%d/_T%d\n", addr, addr1, addr2);
            vleft.push_back(pT);
            return addr;
        }
        else if(pnode->pright!=NULL && strcmp(pnode->pright->name, "OIDIV") == 0)
        {
            int addr1 = TranslateExpr(pnode->pleft);
            int addr2 = TranslateExpr(pnode->pright->pright->pleft);
            int addr = Get_num("");
            TacNode* pT = new TacNode;
            sprintf(pT->cmd, "  _T%d=_T%d%%_T%d\n", addr, addr1, addr2);
            vleft.push_back(pT);
            return addr;
        }
        else if(pnode->pright!=NULL && strcmp(pnode->pright->name, "OLT") == 0)
        {
            int addr1 = TranslateExpr(pnode->pleft);
            int addr2 = TranslateExpr(pnode->pright->pright->pleft);
            int addr = Get_num("");
            TacNode* pT = new TacNode;
            sprintf(pT->cmd, "  _T%d=_T%d<_T%d\n", addr, addr1, addr2);
            vleft.push_back(pT);
            return addr;
        }
        else if(pnode->pright!=NULL && strcmp(pnode->pright->name, "OLE") == 0)
        {
            int addr1 = TranslateExpr(pnode->pleft);
            int addr2 = TranslateExpr(pnode->pright->pright->pleft);
            int addr = Get_num("");
            TacNode* pT = new TacNode;
            sprintf(pT->cmd, "  _T%d=_T%d<=_T%d\n", addr, addr1, addr2);
            vleft.push_back(pT);
            return addr;
        }
        else if(pnode->pright!=NULL && strcmp(pnode->pright->name, "OGT") == 0)
        {
            int addr1 = TranslateExpr(pnode->pleft);
            int addr2 = TranslateExpr(pnode->pright->pright->pleft);
            int addr = Get_num("");
            TacNode* pT = new TacNode;
            sprintf(pT->cmd, "  _T%d=_T%d>_T%d\n", addr, addr1, addr2);
            vleft.push_back(pT);
            return addr;
        }
        else if(pnode->pright!=NULL && strcmp(pnode->pright->name, "OGE") == 0)
        {
            int addr1 = TranslateExpr(pnode->pleft);
            int addr2 = TranslateExpr(pnode->pright->pright->pleft);
            int addr = Get_num("");
            TacNode* pT = new TacNode;
            sprintf(pT->cmd, "  _T%d=_T%d>=_T%d\n", addr, addr1, addr2);
            vleft.push_back(pT);
            return addr;
        }
        else if(pnode->pright!=NULL && strcmp(pnode->pright->name, "OEQU") == 0)
        {
            int addr1 = TranslateExpr(pnode->pleft);
            int addr2 = TranslateExpr(pnode->pright->pright->pleft);
            int addr = Get_num("");
            TacNode* pT = new TacNode;
            sprintf(pT->cmd, "  _T%d=_T%d_T%d\n", addr, addr1, addr2);
            vleft.push_back(pT);
            return addr;
        }
        else if(pnode->pright!=NULL && strcmp(pnode->pright->name, "ONE") == 0)
        {
            int addr1 = TranslateExpr(pnode->pleft);
            int addr2 = TranslateExpr(pnode->pright->pright->pleft);
            int addr = Get_num("");
            TacNode* pT = new TacNode;
            sprintf(pT->cmd, "  _T%d=_T%d!=_T%d\n", addr, addr1, addr2);
            vleft.push_back(pT);
            return addr;
        }
        else if(pnode->pright!=NULL && strcmp(pnode->pright->name, "OAND") == 0)
        {
            int addr1 = TranslateExpr(pnode->pleft);
            int addr2 = TranslateExpr(pnode->pright->pright->pleft);
            int addr = Get_num("");
            TacNode* pT = new TacNode;
            sprintf(pT->cmd, "  _T%d=_T%d&&_T%d\n", addr, addr1, addr2);
            vleft.push_back(pT);
            return addr;
        }
        else if(pnode->pright!=NULL && strcmp(pnode->pright->name, "OOR") == 0)
        {
            int addr1 = TranslateExpr(pnode->pleft);
            int addr2 = TranslateExpr(pnode->pright->pright->pleft);
            int addr = Get_num("");
            TacNode* pT = new TacNode;
            sprintf(pT->cmd, "  _T%d=_T%d||_T%d\n", addr, addr1, addr2);
            vleft.push_back(pT);
            return addr;
        }
    }
}

char* Get_var_class(char* p)
{
    classvarname* pc = NULL;
    int count = vclass.size();
    for(int i = 0; i < count; i++)
    {
        pc = vclass[i];
        if(strcmp(pc->name, p) == 0)
        {
            return pc->type;
        }
    }
    return NULL;
}

int Get_class_var(Declaration* pD)
{
    int num = pD->pSym->vDeclaration.size();
    int i = 0, count = 0;
    for(i = 0; i<num; i++)
    {
        if(pD->pSym->vDeclaration[i]->func != 0)
        {
            ++count;
        }
    }
    return count;
}

void print_vtable()
{
    
    FILE* file = fopen("tac_out.txt", "w");
    if(file == NULL)
    {
        printf("open file filed\n");
        exit(-1);
    }
    int num = table.size();
    int i = 0, j = 0, k = 0;
    for(i = 0; i<num; i++)
    {
        fprintf(file, "VTABLE(_%s){\n", table[i]->name);
        for(j = 0; j < table[i]->TacList.size(); j++)
        {
            fprintf(file, "%s", table[i]->TacList[j]->cmd);
        }
        fprintf(file, "}\n");
    }
    for(i = 0; i<num; i++)
    {
        for(j = 0; j < table[i]->FunList.size(); j++)
        {
            fprintf(file, "FUNCTION(_%s_%s){\n_%s_%s:\n", table[i]->name, table[i]->FunList[j]->name, table[i]->name, table[i]->FunList[j]->name);
            
            for(k = 0; k < table[i]->FunList[j]->TacList.size(); k++)
            {
                fprintf(file, "%s", table[i]->FunList[j]->TacList[k]->cmd);
            }
            fprintf(file, "}\n");
        }
    }
}