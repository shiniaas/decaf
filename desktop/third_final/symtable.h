#ifndef __SYMTABLE.H__
#define __SYMTABLE.H__
#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>
#define INF 0x7FFFFFFF
using namespace std;

enum COLOR {RED, BLACK};
enum Object {GLOBAL, CLASS, FORMAL, LOCAL};

class Symtable;
class Declaration;

//新加的symtable加入到当前栈顶的树中
stack<Symtable*> Symstack;

class Symtable
{
public:
    enum Object type;
    vector<Declaration*> vDeclaration;
};

class Declaration
{
public:
    char* name;
    char* type;
    int func; //1表明是函数
    Symtable* pSym;
};

#endif