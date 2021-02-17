#ifndef BST_H
#define BST_H

typedef struct bst BST;

BST* initEmptyBST (void);
BST* insertKey (BST* tree, int key);
int height (BST* tree);
void freeBST (BST* tree);
void showTreeTextualNote (BST* tree);

#endif