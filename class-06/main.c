#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "item.h"

extern void sort(Item* a, int lo, int hi);

int main (int argc, char* argv[]) {
    if (argc != 2)
        exit(1);

    int N = atoi(argv[1]);
    int *array = (int*) malloc (sizeof(int) * N);

    // reads input
    for (int i = 0; i <N; i++)
        scanf("%d", &array[i]);
    
    // checks how long the sort takes
    clock_t start = clock();
    sort(array, 0, N);
    clock_t end = clock();

    double seconds = ((double) end - start) / CLOCKS_PER_SEC;

    // shows vector sorted
    for (int i = 0; i < N; i++)
        printf("%d\n", array[i]);

    // print time
    printf("%lf\n", seconds);
    free(array);

    return 0;
}
