#include "item.h"

// Insertion sort
extern void sort(Item* a, int lo, int hi) {
    int pos;

    for (int i = 1; i < hi; i++) {
        pos = i;

        // checks if the previous value is more than the a[pos]
        while (less(a[pos], a[pos-1]) && pos > lo) {
            exch(a[pos], a[pos-1]);
            // if smaller, checks if the one before it is smaller
            // therefore pos needs to subtract 1
            pos--;
        }
    }
}