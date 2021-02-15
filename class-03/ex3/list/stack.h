#ifndef STACK_H
#define STACK_H

typedef struct item Item;
typedef struct stack Stack;

Item* initItem (); 

Item* addItem (void* item, int type);

Stack* initStack (void);

void push (Stack* s, Item* aux);

Item* pop (Stack* s);

void showItem (Item* it);

void show (Stack* s);
double returnResult (Item* num2Item, Item* num1Item, Item* opItem);

// void freeItem (Item* it);

void freeItems (Item* it);

void freeStack (Stack* s);


#endif