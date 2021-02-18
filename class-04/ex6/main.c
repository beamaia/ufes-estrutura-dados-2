#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "bst.h"
#include "stack.h"

int numberInArray (int* array, int arraySize, int value) {
    for (int i = 0; i < arraySize; i++) {
        if (array[i] == value)
            return 1;
    }

    return 0;
}

int main (int argc, char* argv[]) {
    if (argc != 2)
        exit(1);
    int N = atoi(argv[1]);

    srand (time(NULL));
    // srand(42);

    int random;
    int* numbers  = (int*) malloc(sizeof(int) * N);
    BST* tree = initEmptyBST();

    for (int i = 0; i < N; i++) {
        random = rand() % (N*2);
        if (numberInArray(numbers, i, random))
            i--;
        else {
            numbers[i] = random;
            tree = insertKey(tree, numbers[i]);
        }
    }

    clock_t startRec, endRec;
    clock_t startNRec, endNRec;

    showTreeTextualNote (tree);
    printf("\n");

    printf("\nPre-order traversal:\n");
    startNRec = clock();
    addStackPreOrder(tree, N, showKey);
    endNRec = clock();
    printf("\n");

    startRec = clock();
    rec_preorder(tree, showKey);
    endRec = clock();

    double secRec = ((double) endRec - startRec ) / CLOCKS_PER_SEC ;
    double secNRec = ((double) endNRec - startNRec ) / CLOCKS_PER_SEC ;

    printf("\nRecursive time: %lf\nNon-recursive time: %lf\n", secRec, secNRec);
    
    printf("\n\nIn-order traversal:\n");
    startNRec = clock();
    addStackInOrder(tree, N, showKey);
    endNRec = clock();
    printf("\n");

    startRec = clock();
    rec_inorder(tree, showKey);
    endRec = clock();

    secRec = ((double) endRec - startRec ) / CLOCKS_PER_SEC ;
    secNRec = ((double) endNRec - startNRec ) / CLOCKS_PER_SEC ;

    printf("\nRecursive time: %lf\nNon-recursive time: %lf\n", secRec, secNRec);
    

    printf("\n\nPost-order traversal:\n");
    startNRec = clock();
    addStackPostOrder(tree, N, showKey);
    endNRec = clock();
    printf("\n");

    startRec = clock();
    rec_postorder(tree, showKey);
    endRec = clock();

    secRec = ((double) endRec - startRec ) / CLOCKS_PER_SEC ;
    secNRec = ((double) endNRec - startNRec ) / CLOCKS_PER_SEC ;

    printf("\nRecursive time: %lf\nNon-recursive time: %lf\n", secRec, secNRec);
    ;

    freeBST(tree);
    free(numbers);

    return 0;
}