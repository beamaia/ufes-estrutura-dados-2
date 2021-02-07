#ifndef UF
#define UF

#include <stdbool.h>

int* unionFindInit (int N);

int getID (int p, int* id);

void putID (int p, int* id, int value);

void createUnion (int p, int q, int* id, int N);

bool connected (int p, int q, int* id);

bool allObjectsConnected (int* id, int N);

void showUnionFind (int* id, int N);

void freeUnionFind (int* id);
#endif