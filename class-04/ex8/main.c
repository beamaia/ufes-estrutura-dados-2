#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "bst.h"
#include "queue.h"

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

    // srand (time(NULL));
    srand(42);
    
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

    showTreeTextualNote (tree);
    printf("\n");
    
    printf("\nRecursive pre-order traversal:\n");
    bfsTraverse(tree, N, showKey);
    printf("\n");

    freeBST(tree);
    free(numbers);

    return 0;
}