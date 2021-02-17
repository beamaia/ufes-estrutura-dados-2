#ifndef STACK_H
#define STACK_H
#include "bst.h"

typedef struct stack Stack;

Stack* initStack (int size);
void push (Stack* s, BST* node, int max);
BST* pop (Stack* s);
void showStack (Stack* s);
void freeStack (Stack* s);

#endif