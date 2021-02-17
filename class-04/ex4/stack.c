#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "bst.h"

struct stack {
    int top;
    BST** nodes;
};

Stack* initStack (int size) {
    Stack* s = (Stack*) malloc(sizeof(Stack));
    s->top = -1;
    s->nodes = (BST**) malloc(sizeof(BST*) * size);
    
    for (int i = 0; i < size; i++)
        s->nodes[i] = NULL;

    return s;
}

void push (Stack* s, BST* node, int max) {
    if (s == NULL) {
        printf("Stack NULL\n");
        return;
    } else if (node == NULL) {
        printf("BST node NULL\n");
        return;
    } else if (s->top >= max) {
        printf("Stack full!\n");
        return;
    }

    s->top++;    
    s->nodes[s->top] = node;
}

BST* pop (Stack* s) {
    if (s == NULL) {
        printf("Stack NULL\n");
        return NULL;
    } else if (s->top == -1) {
        printf("Stack empty!\n");
        return NULL;
    }

    BST* aux = s->nodes[s->top];
    s->top--;
    
    return aux;
}

void showStack (Stack* s) {
    int i;

    if (s == NULL) 
        return;
    
    for (i = s->top; i >= 0; i--) 
        showKey(s->nodes[i]);
}

void freeStack (Stack* s) {
    if (s == NULL)
        return;
    
    free(s->nodes);
    free(s);
}