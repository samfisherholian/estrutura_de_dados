#ifndef _EXERCICIO01_
#define _exercicio01_

#include <stdio.h>
#include <stdlib.h>

typedef struct arvore ARVORE;

ARVORE* arvore_no(int dado);
ARVORE* inserir (ARVORE* raiz, int dado);
int pares(ARVORE* raiz);
void imprime(ARVORE* raiz);

#endif