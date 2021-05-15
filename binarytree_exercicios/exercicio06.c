#include <stdio.h>
#include <stdlib.h>
#include "exercicio06.h"


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

// exercicio 6 do livro
int folhas_maiores_que(ARVORE* raiz, int x){

    if(raiz != NULL){

        int contador = (!raiz -> arvoreright && !raiz -> arvoreleft && raiz->dado > x) + folhas_maiores_que(raiz -> arvoreright, x);

        if(x <= raiz->dado){

            contador = contador + folhas_maiores_que(raiz->arvoreleft, x);

        }

        return contador;

    }

    return 0;

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
