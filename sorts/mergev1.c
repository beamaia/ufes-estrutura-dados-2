#include <stdio.h>
#include <stdlib.h>
#include "item.h"

// merge without optimization 
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

void merge_sort (Item* a, Item* aux, int lo, int hi) {
    if (hi <= lo) 
        return;
    
    int mid = lo + (hi - lo) / 2;
    merge_sort(a, aux, lo, mid);
    merge_sort(a, aux, mid+1, hi);
    merge(a, aux, lo, mid, hi);
}

void sort (Item* a, int lo, int hi) {
    int n = hi;
    Item* aux = (Item*) malloc (sizeof(Item) * n);
    merge_sort(a, aux, lo, hi-1);
    free(aux);
}