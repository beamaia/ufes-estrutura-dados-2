#ifndef QUEUE_H
#define QUEUE_H
#include "bst.h"

typedef struct queue Queue;

Queue* initQueue (int size);
void enqueue (Queue* q, BST* tree, int size);
BST* dequeue (Queue* q, int size);
void showQueue (Queue* q, int size);
void freeQueue (Queue* q, int size);

#endif