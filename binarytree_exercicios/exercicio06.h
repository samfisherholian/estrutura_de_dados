#ifndef _EXERCICIO06_
#define _exercicio06_

#include <stdio.h>
#include <stdlib.h>

typedef struct arvore ARVORE;
ARVORE* arvore_no(int dado);
ARVORE* inserir (ARVORE* raiz, int dado);
int folhas_maiores_que(ARVORE* raiz, int x);
void imprime(ARVORE* raiz);

#endif