#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "prime.h"

int main(int argc, char *argv[]) {
    int N = atoi(argv[1]);

    if (N >= 2) {
        int *array = arrayInit(N);

        for (int i = 2; i < N + 1; i++) {
            if (isPrime(array[i])) {
                changeMultiples (array, N + 1, i);
                // printf("Prime: %d\n", i);
            }
            // else
            //     printf("Not prime: %d\n", i);
        } 

        freeArray(array);
    }

    return 0;
}

