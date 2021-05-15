#ifndef _EXERCICIO02_
#define _exercicio02_

#include <stdio.h>
#include <stdlib.h>

typedef struct arvore ARVORE;

ARVORE* arvore_no(int dado);
ARVORE* inserir (ARVORE* raiz, int dado);
int numFolhas(ARVORE* raiz);
void imprime(ARVORE* raiz);

#endif