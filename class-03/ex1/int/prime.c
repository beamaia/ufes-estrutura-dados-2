#define PRIME_H

#include "prime.h"
#include <stdlib.h>
#include <stdio.h>

#define false 0
#define true 1

int* arrayInit (int N) {
    // If array[i] == 0 -> a prime number
    // If array[i] == 1 -> not a prime number
    int* array = (int*) malloc (sizeof(int) * (N + 1));

    array[0] = 1;
    array[1] = 1;

    for (int i = 2; i < N + 1; i++) {
        // Suppose the number is prime
        array[i] = 0;
    }

    return array;
}

void changeMultiples (int* array, int arrayLen, int value) {
    int i = value * 2;

    while (i < arrayLen) {
        array[i] = 1;
        i += value;
    }
}

int isPrime (int value) {
    if (value)
        return false;
    return true;
}

void freeArray (int *array) {
    free(array);
}

