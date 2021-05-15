#include <stdio.h>
#include <stdlib.h>
#include "exercicio08.h"

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

int busca(ARVORE* raiz, int dado){

   if(raiz == NULL){

       return 0;

    }else if(raiz->dado == dado){

        return 1;

    }else if(dado <= raiz -> dado){

        return busca(raiz->arvoreleft, dado);

    }else{

        return busca(raiz->arvoreright, dado);

    }

}

// exercicio 8 do livro
int retorna_nivel_pelo_valor(ARVORE* raiz, int x){

    if(raiz){

        if(x == raiz->dado){

            return 0;

        }

        int numAux;

        if(x < raiz -> dado){

            numAux = retorna_nivel_pelo_valor(raiz->arvoreleft, x);

        }else{

            numAux = retorna_nivel_pelo_valor(raiz -> arvoreright, x);

        }

        return -1 == numAux ? numAux : numAux + 1;

    }

    return -1;

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
