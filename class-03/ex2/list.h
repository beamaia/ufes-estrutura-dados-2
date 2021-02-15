#ifndef LIST_H
#define LIST_H

typedef struct list List;

List* initList (int N); 

void fillList (List* list, int N);

void removeNodes (List* list, int M);

void showValue (List* list);

void freeValue (List* list);

#endif