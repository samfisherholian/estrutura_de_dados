#include <stdio.h>
#include <stdlib.h>
#include "stackDinamyc.h"


struct stackdinamyc{


    int top;
    int tamanhoArray;
    int *array;

};

// cria a pilha
STACKDINAMYC* createStack(int tamanho){

    STACKDINAMYC* stack = (STACKDINAMYC*) malloc(sizeof(STACKDINAMYC));

    stack->tamanhoArray = tamanho;

    stack->top = -1;

    stack->array = (int*) malloc(sizeof(int) * stack->tamanhoArray);

    return stack;

}
//verifica se a pilha esta vazia
int isFull(STACKDINAMYC* stack){

    if(stack->top == stack->tamanhoArray -1){

        return 1;

    }else{

        return 0;

    }

}
//adiciona uma valor no topo da pilha
int push(STACKDINAMYC* stack,int dado){ 


    if(isFull(stack)){

        printf("impssivel insererir um novo elemento, pilha cheia\n");

        return 0;

    }else {


        stack->top++;

        stack->array[stack->top] = dado;

        return 1;

    }

}
//verifica se estar vazia
int isEmpty(STACKDINAMYC* stack){

    if(stack->top == -1){

        return 1;

    }else{

        return 0;

    }


}
//remove um elemento do topo da pilha
int pop(STACKDINAMYC* stack){


    if(isEmpty(stack)){

        printf("lista vazia, impossivel remover\n");

        return 0;

    }else{

        stack->array[stack->top--];

        return 1;

    }

}
//printa os elementos da pilha
void printStackDi(STACKDINAMYC* stack){

    int i;

    printf("stack is\n");

    for(i = stack->top; i >= 0; i--){

        printf("%i \n",stack->array[i]);

    }


}
//retorna o topo da pilha
int topStack(STACKDINAMYC* stack){

       return stack->array[stack->top];

}
