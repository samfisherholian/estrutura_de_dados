#include <stdio.h>
#include <stdlib.h>
#include "exercicio01.h"


struct arvore{

    int dado;
    struct arvore* arvoreleft;
    struct arvore* arvoreright;
};

ARVORE* arvore_no(int dado){

    ARVORE* noarvore = (ARVORE*)malloc(sizeof(ARVORE));
    noarvore -> dado = dado;
    noarvore -> arvoreleft = noarvore -> arvoreright = NULL;

    return noarvore;

}


ARVORE* inserir (ARVORE* raiz, int dado){

    if(raiz == NULL){

        raiz = arvore_no(dado);

    }else if (dado <= raiz -> dado){

        raiz -> arvoreleft = inserir(raiz -> arvoreleft, dado);

    }else {
        
        raiz->arvoreright = inserir(raiz -> arvoreright, dado);

    }

    return raiz;

}


// exercicio 1 do livro
int pares(ARVORE* raiz){

    if(raiz == NULL){

        return 0;

    }else{

        return !(raiz->dado % 2) + pares(raiz->arvoreleft) + pares(raiz->arvoreright);
    }

}

void imprime(ARVORE* raiz){

    printf("<");
    if(raiz != NULL){

        printf("%i", raiz->dado);

        imprime(raiz->arvoreleft);

        imprime(raiz->arvoreright);


    }

    printf(">");

}
//383569.

// segundo envio  384742.