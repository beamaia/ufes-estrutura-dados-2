#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int* unionFindInit (int N) {
    int* id = (int*) malloc (sizeof(int) * N);

    for (int i = 0; i < N; i++)
        id[i] = i;

    return id;
}

int getID (int p, int* id) {
    return id[p];
}

void putID (int p, int* id, int value) {
    id[p] = value;
}

void createUnion (int p, int q, int* id, int N) {
    int qid = id[q];
    int pid = id[p];

    for (int i = 0; i < N; i++) {
        if (getID(i, id) == pid)
            putID(i, id, qid);
    }
}

bool connected (int p, int q, int* id) {
    return getID(p, id) == getID(q, id);
}

bool allObjectsConnected (int* id, int N) {
    for (int i = 0; i < N - 1; i++) {
        if (getID(i, id) != getID(i+1, id)) 
            return 0;
    }

    return 1;
}

void showUnionFind (int* id, int N) {
    for (int i = 0; i < N; i++){
        printf("%d ", id[i]);
    }

    printf("\n");
}
