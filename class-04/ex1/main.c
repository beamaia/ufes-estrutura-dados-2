#include <stdlib.h>
#include "bst.h"

int main (int argc, char* argv[]) {
    BST* tree = initEmptyBST();
    tree = insertKey(tree, 3);
    tree = insertKey(tree, 1);
    tree = insertKey(tree, 2);
    tree = insertKey(tree, 0);
    tree = insertKey(tree, 10);
    tree = insertKey(tree, 11);
    tree = insertKey(tree, 4);
    showTreeTextualNote(tree);
    freeBST(tree);

    return 0;
}