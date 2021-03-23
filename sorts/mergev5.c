#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#define SZ2 (sz + sz)
#define MIN(X,Y) ((X<Y) ? (X) : (Y))

// merge with bottom-down
void merge (Item *a, Item *aux, int lo, int mid, int hi) {
    for (int k = lo; k <= hi; k++) {
        aux[k] = a[k];
    }

    int i = lo, j = mid+1;

    for (int k = lo; k <= hi; k++) {
        if (i > mid)
            a[k] = aux[j++];
        else if (j > hi) 
            a[k] = aux[i++];
        else if (aux[j] < aux[i])
            a[k] = aux[j++];
        else    
            a[k] = aux[i++];
    }
}

void sort (Item* a, int lo, int hi) {
    int n = hi;
    int y = n - 1;
    Item* aux = (Item*) malloc (sizeof(Item) * n);
    for (int sz = 1; sz < n; sz = SZ2) {
        for (lo = 0; lo < n - sz; lo += SZ2) {
            int x = lo + SZ2 - 1;
            merge(a, aux, lo, lo+sz-1, MIN(x, y));
        }
    }

    free(aux);
}