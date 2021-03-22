#include "item.h"

// Bubble sort
extern void sort(Item* a, int lo, int hi) {
    for (int i = 0; i < hi - 1; i++) {
        for (int j = 0; j < hi - 1 - i; j++) {
            compexch(a[j], a[j + 1]);
        }
    }
}