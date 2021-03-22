#include "item.h"

// Selection sort
extern void sort(Item* a, int lo, int hi) {
    int smallest;
    int pos;

    for (int i = 0; i < hi; i++) {
        // suppose that a[i] is the smallest
        // saves position of the "smallest"
        smallest = a[i];
        pos = i;

        for (int j = i; j < hi; j++) {
            // checks if the smallest is smaller than all values after it
            if (less(a[j], smallest)) {
                // found the smallest and saved its position
                smallest = a[j];
                pos = j;
            }
        }
    }
}
