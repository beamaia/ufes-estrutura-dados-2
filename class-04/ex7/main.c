#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "bst.h"
#include "queue.h"

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

    Queue* queue = initQueue(10);
    enqueue(queue, tree, 10);
    enqueue(queue, getRightTree(tree), 10);
    enqueue(queue, getLeftTree(tree), 10);
    showQueue(queue, 10);
    printf("\n");

    dequeue(queue, 10);

    BST* aux1 = dequeue(queue, 10);
    
    enqueue(queue, getRightTree(aux1), 10);
    enqueue(queue, getLeftTree(aux1), 10);
    showQueue(queue, 10);
    printf("\n");
    
    freeBST(tree);
    freeQueue(queue, 10);

    return 0;
}