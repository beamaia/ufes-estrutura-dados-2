#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

struct bst {
    int key;
    BST* left;
    BST* right;
};
 
BST* initEmptyBST (void) {
    return NULL;
}

static int emptyBST (BST* tree) {
    return tree == NULL;
}

// static int getNodeKey (BST* tree) {
//     return tree->key;
// }

BST* insertKey (BST* tree, int key) {
    if (emptyBST(tree)) {
        tree = (BST*) malloc (sizeof(BST));
        tree->key = key;
        tree->left = tree->right = NULL;
    } else {
        int treeKey = tree->key;

        if (key < treeKey) {
            tree->left = insertKey(tree->left, key);
        } else if (key > treeKey) {
            tree->right = insertKey(tree->right, key);
        }
    }
    return tree;
}


static int max (int a, int b) {
    return (a > b) ? a : b;
}

int height (BST* tree) {
    if (emptyBST(tree)) {
        return -1;
    } else {
        return 1 + max (height(tree->left), height(tree->right));
    }
}

void freeBST (BST* tree) {
    if (!emptyBST(tree)) {
        freeBST(tree->left);
        freeBST(tree->right);
        free(tree);
    }
}

void showTreeTextualNote (BST* tree) {
    printf("<");

    if (!emptyBST(tree)) {
        printf(" %d ", tree->key);
        showTreeTextualNote(tree->left);
        showTreeTextualNote(tree->right);
    }

    printf("> ");
}