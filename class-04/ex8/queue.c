#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "bst.h"

struct queue {
    int start;
    int qty;
    BST** trees;
};

Queue* initQueue (int size) {
    Queue* q = (Queue*) malloc (sizeof(Queue));
    q->start = 0;
    q->qty = 0;
    q->trees = (BST**) malloc (sizeof(BST*) * size);

    for (int i = 0; i < size; i++) {
        q->trees[i] = NULL;
    }

    return q;
}

void enqueue (Queue* q, BST* tree, int size) {
    if (q == NULL || q->qty >= size) {
        printf("Invalid queue!\n");
        return;
    }

    int pos = (q->start + q->qty) % size;

    q->trees[pos] = tree;
    q->qty++;
}

// Retira o primeiro aluno da fila e atualiza fila->qtd
BST* dequeue (Queue* q, int size) {
    if (q == NULL || q->qty == 0) {
        printf("Pilha invalida ou vazia!\n");
        return NULL;
    }
   
    BST* tree = q->trees[q->start];
    q->start = (q->start + 1) % size;
    q->qty--;

    return tree;
}

void showQueue (Queue* q, int size) {
    int pos = 0;

    if (q == NULL)
        return;

    for (int i = 0; i < q->qty; i++) {
        pos = (q->start + i) % size;
        showKey(q->trees[pos]);
    }
}

void bfsTraverse(BST *tree, int size, void (*visit)(BST*)) {
    Queue* queue = initQueue(size);
    BST* aux = tree;

    enqueue(queue, aux, size);

    while (queue->qty > 0) {
        BST* aux2 = dequeue(queue, size);
        visit(aux2);
        
        if (!emptyBST(getLeftTree(aux2))) {
            enqueue(queue, getLeftTree(aux2), size);
        }
        if (!emptyBST(getRightTree(aux2))) {
            enqueue(queue, getRightTree(aux2), size);
        }
    }

    freeQueue(queue, size);
}

void freeQueue (Queue* q, int size) {
    if (q == NULL)
        return;
    
    free(q->trees);
    free(q);
}
