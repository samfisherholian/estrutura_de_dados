#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>// testando essa bliblioteca aqui

typedef struct queue QUEUE;


struct queue {

    int tamanhoArray;
    int front;
    int tamanho;
    int tail;
    int *array;

};

// cria a fila
QUEUE* creaQueue(int capacidade){

    QUEUE* queue = (QUEUE*) malloc(sizeof(QUEUE));

    queue ->tamanhoArray = capacidade;
    queue -> front = queue -> tamanho = 0;

    queue->tail = capacidade -1;
    queue -> array = (int*) malloc(queue->tamanhoArray * sizeof(int));

    return queue;
}


bool isFull(QUEUE* queue){

    return (queue->tamanho ==  queue->tamanhoArray)? true : false;
    
}


bool isEmpety(QUEUE* queue){

    return (queue->tamanho == 0)? true : false;

}

// funcao que insere um elemento na calda
bool push(QUEUE* queue, int x){

    if(isFull(queue)){

        printf("a fila esta cheia :( \n");

        return false; 

    }    
    
    queue->tail = (queue->tail + 1) % queue->tamanhoArray;

    queue->array[queue->tail] = x;

    queue->tamanho++; 
  
    return true;
}
// remove um elemento da fila
int remover(QUEUE* queue){

    if(isEmpety(queue)){

        printf("erro: fila vazia :(\n");

        return 0;
    }
        int elemento = queue->array[queue->front];

        queue->front = (queue->front + 1) % queue->tamanhoArray; 

        queue->tamanho--;

    return 1;

}

int front(QUEUE* queue){

    if(isEmpety(queue)){

        printf("erro\n");

        return 0;

    }else{

        return queue->array[queue->front];

    }

}

int tail(QUEUE* queue){

    if(isEmpety(queue)){

        printf("erro\n");

        return 0;

    }else{

        return queue->array[queue->tail];

    }

}


void printQueue(QUEUE* queue){

    int i;

    int numelementos = (queue->tail + queue->tamanho - queue->front) % queue->tamanho + 1;

    printf("a fila eh :");
    for(i = 0; i < numelementos; i++){

        int indice = (queue->front + i) % queue->tamanho;

        printf(" %i ", queue->array[indice]);


    }

    printf("\n");

}

int main(){


    QUEUE* queue = creaQueue(10);

    isEmpety(queue)? printf("esta vazia\n") : printf("nao esta vazia \n");

    push(queue, 2);

    push(queue, 1);

    push(queue, 3);

    printQueue(queue);

    printf("a frente eh: %i\n", front(queue));

    printf("removendo um elemento da fila...\n");
    remover(queue);
    

    printf("a frente eh %i\n", front(queue));

    push(queue, 4);

    push(queue, 5);

    push(queue, 6);

    push(queue, 7);

    push(queue, 8);

    push(queue, 9);

    push(queue, 30);

    push(queue, 17);

    push(queue, 40);

    printf("a cauda eh: %i\n", tail(queue));


    printQueue(queue);


    return 0;
}
