#include "stack.h"
void main(){
    int i;
    SqStack *s;
    s = InitStack(s);
    for(i = 0 ; i < 20 ; i++){
        int elem = rand()%100;
        Push(s,elem);
    }
    print(s);
    FreeStack(s);
}