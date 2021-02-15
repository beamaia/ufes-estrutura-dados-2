#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct cell Cell;
struct cell {
    int num;
    Cell* next;
};

struct list {
    Cell* first,
        * last;
};

List* initList (int N) {
    List* list = (List*) malloc (sizeof(List));
    list->first = list->last = NULL;

    for (int i = N; i > 0; i--) {
        fillList(list, i);
    }

    list->last->next = list->first;
    return list;

} 

void fillList (List* list, int N) {
    // N is added to the beginning of the number
    Cell* newCell = (Cell*) malloc (sizeof(Cell));
    
    newCell->num = N;
    newCell->next = list->first;
    list->first = newCell;

    if (list->last == NULL) {
        list->last = newCell;
    }
}

void removeNodes (List* list, int M) {
    Cell* aux = list->first, * ant = NULL;

    while (ant != aux) {
        
        for (int i = 0; i < M - 1; i++)  {
            ant = aux;
            aux = aux->next;
        }

        if(aux == ant)
            break;

        if (aux == list->last) {
            ant->next = aux->next;
            list->last = ant;
            free(aux);
            aux = ant->next;
        } else if (aux == list->first) {
            ant->next = aux->next;
            list->first = ant->next;
            free(aux);
            aux = ant->next;
        } else {
            ant->next = aux->next;
            free(aux);
            aux = ant->next;
        }
    } 
}

void showValue (List* list) {
    printf("%d\n", list->first->num);
}

void freeValue (List* list) {
    free(list->first);
    free(list);
}