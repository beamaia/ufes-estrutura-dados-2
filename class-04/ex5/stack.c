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

void addStackPreOrder (BST* tree, int size, void (*visit)(BST*)) {
    if (emptyBST(tree)) 
        return;

    Stack* auxStack = initStack(size);
    BST* aux;

    push(auxStack, tree, size);

    while (auxStack->top > -1) {
        aux = pop(auxStack);
        
        if (!emptyBST(aux)){
            visit(aux);

            if(!emptyBST(getRightTree(aux)))
                push(auxStack, getRightTree(aux), size);

            if(!emptyBST(getLeftTree(aux)))
                push(auxStack, getLeftTree(aux), size);
        }
    }
    

    freeStack(auxStack);
}

void addStackInOrder (BST* tree, int size, void (*visit)(BST*)) {
    if (emptyBST(tree)) 
        return;

    Stack* auxStack = initStack(size);
    BST* aux = tree;


    while (!emptyBST(aux) || (auxStack->top > -1)) {

        while (!emptyBST(aux)) {
            push(auxStack, aux, size);
            aux = getLeftTree(aux);
        }

        aux = pop(auxStack);
        visit(aux);

        aux = getRightTree(aux);
    }
    
    freeStack(auxStack);
}

void addStackPostOrder (BST* tree, int size, void (*visit)(BST*)) {
   if (emptyBST(tree)) 
        return;

    Stack* auxStack = initStack(size);
    BST* aux = tree;

    do {
        while (!emptyBST(aux)) {
            if (!emptyBST(getRightTree(aux)))
                push(auxStack, getRightTree(aux), size);
            
            push(auxStack, aux, size);
            aux = getLeftTree(aux);
        }

        aux = pop(auxStack);

        if (!emptyBST(getRightTree(aux)) && auxStack->top > -1 && auxStack->nodes[auxStack->top] == getRightTree(aux)) {
            pop(auxStack);
            push(auxStack, aux, size);
            aux = getRightTree(aux);
        } else {
            visit(aux);
            aux = NULL;
        }
    } while (auxStack->top > -1);
    
    freeStack(auxStack);
}

void freeStack (Stack* s) {
    if (s == NULL)
        return;
    
    free(s->nodes);
    free(s);
}