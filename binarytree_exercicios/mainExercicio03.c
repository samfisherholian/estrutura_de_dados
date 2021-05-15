#include <stdio.h>
#include <stdlib.h>
#include "exercicio03.h"


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

    printf("quantidade de nos com a penas um filho = %i \n", apenasUmfilho(RAIZ));

    
    return 0;
}
