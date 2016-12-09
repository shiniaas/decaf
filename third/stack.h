/*implement a stack in c*/
#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 2

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElemType;
typedef int Status;

typedef struct SqStack{
    ElemType *base;
    ElemType *top;
    int stackSize;
}SqStack;

//init statck
SqStack* InitStack(SqStack *s){
    s = (SqStack*)malloc(sizeof(SqStack));
    if(!s)
    {
        exit(-1);
    }
    s->base = (ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
    return s;
}

//free stack
Status FreeStack(SqStack *s){
    if(!s)
    {
        return 0;
    }
    else
    {
        free(s->base);
        free(s);
        return 1;
    }
}


//push element into stack
Status Push(SqStack *s, ElemType e){
    assert(s);
    //stack is full, need more space
    if(s->top - s->base >= s->stackSize)
    {
        s->base = (ElemType*)realloc(s->base, (s->stackSize + STACK_INCREMENT)*sizeof(ElemType));
        if(!s->base)
        {
            exit(1);
        }
        s->top = s->base + s->stackSize;
        s->stackSize += STACK_INCREMENT;
    }
    *(s->top) = e;
    ++(s->top);
    return 1;
}

//pop out elem from stack
Status Pop(SqStack *s, ElemType *e){
    assert(s);
    if(s->base == s->top)
    {
        return 0;
    }
    e = s->top;
    --(s->top);
    return 1;
}


