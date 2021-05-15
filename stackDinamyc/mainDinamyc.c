#include <stdio.h>
#include <stdlib.h>
#include "stackDinamyc.h"


int main(){


    STACKDINAMYC* stack = createStack(10);

    isEmpty(stack)? printf("esta vazia \n") : printf("nao esta vaziaz \n");

    printf("inserindo algumas valores \n");
    push(stack, 2);
    push(stack, 3);
    push(stack, 5);

    printf("o topo eh %i\n", topStack(stack));


    printStackDi(stack);

    pop(stack);

    printStackDi(stack);

    push(stack, 8);
    push(stack, 9);
    push(stack, 10);
    push(stack, 1);
    push(stack, 6);
    push(stack, 7);
    push(stack, 15);
    push(stack, 14);
    push(stack, 13);

    printStackDi(stack);

    return 0;
}