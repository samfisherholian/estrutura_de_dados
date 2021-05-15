#include <stdio.h>
#include <stdlib.h>
#include "exercicio03.h"

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

// exercicio 3 do livro
int apenasUmfilho(ARVORE* raiz){

    if(!raiz || !raiz -> arvoreright && !raiz -> arvoreleft){

        return 0;
    }

    return !(raiz ->arvoreleft && raiz->arvoreright) + apenasUmfilho(raiz -> arvoreleft) + apenasUmfilho(raiz -> arvoreright);

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
