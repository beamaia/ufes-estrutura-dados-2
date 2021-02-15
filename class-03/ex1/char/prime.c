#define PRIME_H

#include "prime.h"
#include <stdlib.h>
#include <stdio.h>

#define false 0
#define true 1

char* arrayInit (int N) {
    // If array[i] == 0 -> a prime number
    // If array[i] == 1 -> not a prime number
    char* array = (char*) malloc (sizeof(char) * N + 1);

    array[0] = 1;
    array[1] = 1;

    for (int i = 2; i < N + 1; i++) {
        // Suppose it's a prime number
        array[i] = 0;
        
    }

    return array;
}

int isPrime (char value) {
    if (value == '1')
        return false;
    return true;
}

void changeMultiples (char* array, int arrayLen, int value) {
    int i = value * 2;
    while (i < arrayLen) {
        if (isPrime(array[i])) {
            array[i] = '1';
        }

        i += value;
    }
}
void freeArray (char *array) {
    free(array);
}

void showPrime (char* array, int arrayLen) {
    for (int i = 2; i < arrayLen; i++) {
        if (isPrime(array[i]))
            printf("%c ", array[i]);
    }
}

