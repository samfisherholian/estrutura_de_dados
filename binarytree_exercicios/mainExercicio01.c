#include <stdio.h>
#include <stdlib.h>
#include "exercicio01.h"


int main(){

    ARVORE* RAIZ = NULL;

    RAIZ = inserir(RAIZ, 15);

    RAIZ = inserir(RAIZ, 10);

    RAIZ = inserir(RAIZ, 20);

    RAIZ = inserir(RAIZ, 25);

    RAIZ = inserir(RAIZ, 8);

    RAIZ = inserir(RAIZ, 12);

    imprime(RAIZ);

    printf("\n");

    printf("soma dos nos pares eh = "); printf("%i\n", pares(RAIZ));

    return 0;
}
