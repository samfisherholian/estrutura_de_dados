#ifndef _EXERCICIO08_
#define _exercicio08_

#include <stdio.h>
#include <stdlib.h>

typedef struct arvore ARVORE;

ARVORE* arvore_no(int dado);
ARVORE* inserir (ARVORE* raiz, int dado);
int busca(ARVORE* raiz, int dado);
int retorna_nivel_pelo_valor(ARVORE* raiz, int x);
void imprime(ARVORE* raiz);


#endif