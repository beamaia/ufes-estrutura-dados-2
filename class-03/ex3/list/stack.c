#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

/* 
 * type = 1 -> number
 * type = 0 -> char
 */ 
struct item {
    void *item;
    int type; 
    Item* next;
};

struct stack {
    int top;
    Item* items;
};

Item* initItem () {
    Item* i = (Item*) malloc (sizeof (Item));
    i->item = NULL;
    i->type = -1;
    i->next = NULL;
    return i;
} 

Item* addItem (void* item, int type) {
    Item* aux = initItem();
    aux->type = type;
    aux->item = item;
    aux->next = NULL;
    return aux;
}

double returnResult (Item* num2Item, Item* num1Item, Item* opItem) {
    if (num1Item == NULL || num2Item == NULL || opItem == NULL) {
        printf("num1Item: %d\nnum2Item: %d\nopItem: %d\n", num1Item == NULL, num2Item == NULL, opItem == NULL );
        return 0;
    }
    
    char op = *(char*) opItem->item;
    double num1 = *((double*) num1Item->item);
    double num2 = *((double*) num2Item->item);

    freeItems(opItem);
    freeItems(num1Item);
    freeItems(num2Item);
    if (op == '/' && num2 == 0)
        return 0;

    switch (op) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2; 
    }
}

Stack* initStack (void) {
    Stack* s = (Stack*) malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

void push (Stack* s, Item* aux) {
    if (s == NULL) {
        printf("Stack not initialized\n");
    } else if (aux == NULL) {
        printf("Item NULL\n");
        return;
    } else if (s->top > -1) {
        aux->next = s->items;
    }


    s->items = aux;
    s->top++;
}

Item* pop (Stack* s) {
    if (s == NULL) {
        printf("Stack NULL\n");
        return NULL;
    } else if (s->top == -1) {
        printf("Stack Empty!\n");
        return NULL;
    }

    Item* it = s->items;
    s->items = s->items->next;
    s->top--;
    it->next = NULL;
    return it;
}

void showItem (Item* it) {
    if (it->type == 1) {
        // Type is double
        printf("Type int, value: %lf\n", *((double*) it->item));
    } else if (it->type == 0) {
        // Type is char
        printf("Type char, value: %c\n", *((char*) it->item));
    }   
}

void show (Stack* s) {
    if (s == NULL)
        return;
        
    Item* aux = s->items;

    if (s == NULL) 
        return;
    for (aux = s->items; aux != NULL; aux = aux->next) {
        showItem(aux);
    }
}

void freeItems (Item* it) {
    Item* aux1 = it,* aux2;

    while (aux1 != NULL) {
        aux2 = aux1->next;
        free(aux1);
        aux1 = aux2;
    }
}

void freeStack (Stack* s) {
    freeItems(s->items);
    free(s);
}