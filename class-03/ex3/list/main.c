#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#define MAX 200

double isNumber (char value) {
    if (value > '9' || value < '0')
        return -1;
    return (double) value - '0';
}

int main (int argc, char* argv[]) {  
    char string[MAX];
    double numbers[MAX];

    FILE* origin = fopen(argv[1], "r");
    if (origin == NULL)
        exit(1);

    while(fscanf(origin, "%s%*c", string) == 1) {
        Stack* stackNum = initStack();
        Stack* stackOp  = initStack();

        for(int i = 0; i < strlen(string); i++) {
            numbers[i] = isNumber(string[i]);

            if (numbers[i] == -1) {
                if (string[i] == '(') {
                    continue;
                } else if (string[i] == ')') {
                    numbers[i] = returnResult(pop(stackNum), pop(stackNum), pop(stackOp));
                    Item* resultItem = addItem(&numbers[i], 1);
                    push(stackNum, resultItem); 
                } else {
                    Item* item = addItem(&string[i], 0);
                    push(stackOp, item);
                }
            } 
            else {
                Item* item = addItem(&numbers[i], 1);
                push(stackNum, item);
            }
        }
        freeStack(stackNum);
        freeStack(stackOp);
    }   

    fclose(origin);
    return 0;
}