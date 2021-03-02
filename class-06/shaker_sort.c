#include "item.h"
#include <stdio.h>


// Shaker sort / Cocktail sort / Bi-directional bubble sort
extern void sort(Item* a, int lo, int hi) {
    int ordered;

    for (int i = 0; i < hi - 1; i++) {
        // suppose it's orderded
        ordered = 1;

        // exchanges left to right, starting at i
        for (int k = i; k < hi - 1; k++) {
            if (less(a[k + 1], a[k])) {
                exch(a[k], a[k + 1]);
                // not orderded 
                ordered = 0;
            }
        }

        // exchanges right to left, starting at hi - 2
        // not - 1, since the last item can be swapped in the previous for
        for (int j = hi - 2; j > i; j--) {
            if (less(a[j], a[j - 1])) {
                exch(a[j], a[j - 1]);
                // not ordered
                ordered = 0;
            }
        }

        // vector is ordered, therefore no need to continue
        if (ordered)
            break;
    }
}