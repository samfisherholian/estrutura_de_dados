#include <stdio.h>
#include <stdlib.h>
#include "exercicio07.h"

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

// exercicio 7 do livro
int soma_xy(ARVORE* raiz, int x, int y){

    if(raiz != NULL){
    
        int contador = raiz -> dado >= x && raiz -> dado <= y ? raiz-> dado : 0;

        if(raiz -> dado <= y){

            contador += soma_xy(raiz -> arvoreright, x, y);

        }

        if(raiz -> dado >= x){

            contador += soma_xy(raiz -> arvoreleft, x, y);

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
