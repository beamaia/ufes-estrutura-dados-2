#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "bst.h"
#include "stack.h"

int main (int argc, char* argv[]) {
    BST* tree = initEmptyBST();

    tree = insertKey(tree, 5);
    tree = insertKey(tree, 2);
    tree = insertKey(tree, 15);
    tree = insertKey(tree, 3);
    tree = insertKey(tree, 4);
    tree = insertKey(tree, 1);
    tree = insertKey(tree, 10);
    tree = insertKey(tree, 20);
    
    showTreeTextualNote(tree);
    printf("\n");

    Stack* stack = initStack(5);
    push(stack, tree, 5);
    push(stack, getRightTree(tree), 5);
    push(stack, getLeftTree(tree), 5);
    printf("Show stack\n");
    showStack(stack);
    printf("\n");

    BST* aux1 = pop(stack);
    push(stack, getRightTree(aux1), 5);
    push(stack, getLeftTree(aux1), 5);
    printf("Show stack\n");
    showStack(stack);
    printf("\n");
    
    freeBST(tree);
    free(stack);

    return 0;
}