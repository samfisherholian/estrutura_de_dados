#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queuelist QUEUELIST;

// estrutura da lista
struct queuelist {
    int dado;
    struct queuelist* next;

};


// variaveils globais para front e tail 
QUEUELIST* front =  NULL;

QUEUELIST* tail = NULL;


// reuso da funcao push da lista encadeada sem passagem da estrutura.
int push(int x){

    QUEUELIST* QUEUE = (QUEUELIST*) malloc(sizeof(QUEUELIST*));

    QUEUE -> dado = x;
    QUEUE -> next = NULL;

    if(front == NULL &&  tail == NULL){

        front = tail = QUEUE;

        return 1;

    }

    tail->next = QUEUE;
    tail = QUEUE;

    return 1;

}
// verifica se a fila esta vazia
bool isEmpety(){

    return (front == NULL)? true : false;

}
// retorna o valor do primeiro elemento da fila.
int FRONT(){

    if(isEmpety()){
        
        printf("a fila esta vazia\n");

        return 0;

    }

    return front->dado;

}
// retorna o ultimo valor da fila.
int TAIL(){

    if(isEmpety()){

        printf("a fila esta vazia\n");

    }

    return tail->dado;

}
// remove o elemento da fila
bool pop(){

    QUEUELIST* aux = front;

    if(isEmpety()){

        return false;

    }else if(front == tail){

        front = tail = NULL;

    }else{

        front = front->next;

    }

    free(aux);


}
// printa o elementos da lista
void printlist(){

    QUEUELIST* queue = front;

    printf("list is...");
    while(queue !=  NULL){

        printf(" %i", queue->dado);

        queue = queue -> next;

    }

    printf("\n");

}


int main(){

    isEmpety()? printf("a fila esta vazia\n") : printf("a fila nao esta vazia\n");

    push(2);

    

    isEmpety()? printf("a fila esta vazia\n") : printf("a fila nao esta vazia\n");

    push(4);

    push(6);
    printf("removendo um elemento...\n");
    pop();

    push(10);

    printlist();

    printf("front eh: %i e tail eh: %i\n", FRONT(), TAIL());



    return 0;

}