#include <stdio.h>
#include <stdlib.h>
#include "likendstack.h"

struct stack {

    int dado;
    struct stack* next;
};

//adiciona um elemento no no topo da pilha
int push(STACK ** pilha, int valor){

    STACK* noPilha = (STACK*) malloc(sizeof(STACK));
    
    if(noPilha){

        noPilha->dado = valor;

        noPilha->next = *pilha;

        *pilha = noPilha;

        return 1;

    }

    return 0;

}
//remove um elemento do ultimo no da pilha
int pop(STACK ** pilha){


    if(isEmpety(*pilha)){

        printf("não é possivel remover o topo, pois a pilhas está vazia");

        return 0;

    }else{

        STACK* temp = *pilha; 

        *pilha = (*pilha)->next; 

        int removida = temp->dado;

        free(temp); 

        return removida;
    }

}
//retorna o topo da pilha
int topStack(STACK* pilha){

    return pilha->dado;

}
//verifica se esta vazia
int isEmpety(STACK* pilha){

    if(pilha == NULL){

        return 1;

    }

    return 0;

}
//destroi todos os elementos da pilha
void clear_Stack(STACK** pilha){

    STACK* atual = *pilha;
    STACK* next = NULL;

    while(atual != NULL){

        next = atual->next;

        free(atual);
        
        atual = next;

    }

    *pilha = NULL;

}
// printa todos os elementos da pilha
void printStack(STACK* pilha){

    printf("stack is\n");
    while(pilha != NULL){
       
       printf("%i \n",pilha->dado);

       pilha = pilha->next;

    }

}
