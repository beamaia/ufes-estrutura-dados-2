#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "uf.h"

int main(int argc, char *argv[]) {

    int N = atoi((argv[1]));

    clock_t start, end;
    double timeTaken;    

    int* id = unionFindInit(N);

    int p, q, show;
    while (scanf("%d %d", &p, &q) == 2) {
        if (p >= N || q >= N)
            printf("That value is not valid!\n");
        else if (!connected(p, q, id)) {
            start = clock();
    
            createUnion(p, q, id, N);
            printf("Union created between %d and %d\n", p, q);
            end = clock();
            timeTaken = ((double) (end - start)) / CLOCKS_PER_SEC;
            
            printf("create union took %f seconds to execute\n", timeTaken);
        } else {
            printf("Objects are connected\n");
        }

        if (allObjectsConnected(id, N)) {
            printf("All objects are connected!\n");
            break;
        }
    }

    return 0;
}

