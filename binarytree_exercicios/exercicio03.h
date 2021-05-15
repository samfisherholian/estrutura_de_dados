#ifndef _EXERCICIO03_
#define _exercicio03_

#include <stdio.h>
#include <stdlib.h>

typedef struct arvore ARVORE;

ARVORE* arvore_no(int dado);
ARVORE* inserir (ARVORE* raiz, int dado);
int apenasUmfilho(ARVORE* raiz);
void imprime(ARVORE* raiz);

#endif