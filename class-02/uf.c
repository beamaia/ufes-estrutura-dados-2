#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "uf.h"

struct uf {
    int *id;
    int N;
};

UF* unionFindInit (int N) {
    UF *id = (UF*) malloc (sizeof(UF));
    id->N = N;
    int* array = (int*) malloc (sizeof(int) * N);
    id->id = array;

    for (int i = 0; i < N; i++) 
        array[i] = i;
    
    return id;
}

int getID (UF *id, int i) {
    return id->id[i];
}

void putID (UF* id, int i, int j) {
    id->id[i] = j;
}

int getRoot (UF *id, int i) {
    while (getID(id, i) != i)  {
        i = getID(id, i);
    }

    return i;
}

bool connected (UF* id, int p, int q) {
    return getRoot(id, p) == getRoot(id, q);   
}

void createUnion (UF* id, int p, int q) {
    int i = getRoot(id, p);
    int j = getRoot(id, q);
    putID(id, i, j);
}

bool allObjectsConnected (UF* id) {
    for (int i = 0; i < id->N - 1; i++) {
        if (getRoot(id, i) != getRoot(id, i+1)) 
            return false;
    }

    return true;
}

void showUnionFind (UF* id) {
    for (int i = 0; i < id->N; i++){
        printf("%d ", getID(id, i));
    }

    printf("\n");
}

void freeUnionFind(UF* id) {
    free(id->id);
    free(id);
}