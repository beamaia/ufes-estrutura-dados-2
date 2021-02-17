#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "bst.h"

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

    printf("Recursive pre-order traversal:\n");
    rec_preorder(tree, showKey);
    printf("\nRecursive in-order traversal:\n");
    rec_inorder(tree, showKey);
    printf("\nRecursive post-order traversal:\n");
    rec_postorder(tree, showKey);
    printf("\n");

    freeBST(tree);
    free(numbers);

    return 0;
}