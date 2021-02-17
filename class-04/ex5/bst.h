#ifndef BST_H
#define BST_H

typedef struct bst BST;

BST* initEmptyBST (void);
BST* insertKey (BST* tree, int key);
int emptyBST (BST* tree);
int getNodeKey (BST* tree);
BST* getLeftTree (BST* tree);
BST* getRightTree (BST* tree);
int height (BST* tree);
void freeBST (BST* tree);
void showTreeTextualNote (BST* tree);
void showKey (BST* tree);
void rec_preorder(BST* tree, void (*visit)(BST*));
void rec_inorder(BST* tree, void (*visit)(BST*));
void rec_postorder(BST* tree, void (*visit)(BST*));

#endif