#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#define SZ2 (sz + sz)
#define MIN(X,Y) ((X<Y) ? (X) : (Y))
#define CUTOFF 12

void insertSort(Item *a, int lo, int hi) {
    for (int i = lo+1; i <= hi; i++) {
        for (int j = i; j > lo && a[j] < a[j-1]; j--) {
            exch(a[j], a[j-1]);
        }   
    }
}

// merge with bottom-down + cut-off
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

void show (Item* a, int hi) {
    for (int i = 0; i < hi; i++)
        printf("%d ", a[i]);
    
    printf("\n");
}

void sort (Item* a, int lo, int hi) {
    int n = hi;
    int y = n - 1;
    Item* aux = (Item*) malloc (sizeof(Item) * n);
    for (int sz = 1; sz < n; sz = SZ2) {
        for (lo = 0; lo < n - sz; lo += SZ2) {
            int x = lo + SZ2 - 1;
            if ((n-sz) <= (lo + CUTOFF - 1)) { 
                insertSort(a, lo, MIN(x, y));
            } else   {    
                merge(a, aux, lo, lo+sz-1, MIN(x, y));
            }
        }
    }

    free(aux);
}