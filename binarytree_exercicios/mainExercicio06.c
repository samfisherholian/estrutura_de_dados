#include <stdio.h>
#include <stdlib.h>
#include "exercicio06.h"

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

    printf("%i\n",folhas_maiores_que(RAIZ, 6));
    
    return 0;
}
