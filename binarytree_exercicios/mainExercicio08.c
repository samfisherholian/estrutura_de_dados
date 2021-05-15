#include <stdio.h>
#include <stdlib.h>
#include "exercicio08.h"

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


    printf("nivel da arvore = %i\n", retorna_nivel_pelo_valor(RAIZ, 25));

    return 0;
    
}
