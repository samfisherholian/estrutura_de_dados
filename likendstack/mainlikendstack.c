#include <stdio.h>
#include <stdlib.h>
#include "likendstack.h"

int main(){

    STACK* PILHA = NULL;

    push(&PILHA, 5);
    push(&PILHA, 8);
    push(&PILHA, 9);

    printStack(PILHA);

    printf("this is the top of the stack %i\n", topStack(PILHA));
    
    pop(&PILHA);



    printStack(PILHA);

    push(&PILHA, 10);

    printStack(PILHA);

    printf("this is the top of the stack %i\n",topStack(PILHA));

    clear_Stack(&PILHA);

    isEmpety(PILHA)? printf("a pilha esta vazia\n") : printf("a pilha não esta vazia\n");

    return 0;
}
