#include <stdio.h>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

struct sVariable{
    string type;
    string name;
};

struct sFunction{
    string name;
    string rtype;
    vector<sVariable> parameter; //参数列表
};

struct sClass{
    string name;
    vector<sVariable> var;
    vector<sFunction> fun;
};

struct sLocal{
    vector<sVariable> var;
    vector<sFunction> fun;
};

struct Global{
    vector<sClass> cla;
};