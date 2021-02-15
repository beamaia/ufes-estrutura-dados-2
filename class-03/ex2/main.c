#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main (int argc, char* argv[]) {
    if (argc != 3) {
        exit(1);
    }

    int N = atoi(argv[1]);
    int M = atoi(argv[2]);

    List* list = initList(N);
    removeNodes(list, M);
    showValue(list);
    freeValue(list);

    return 0;
}