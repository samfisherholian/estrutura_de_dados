#ifndef _EXERCICIO07_
#define _exercicio07_

typedef struct arvore ARVORE;

ARVORE* arvore_no(int dado);
ARVORE* inserir (ARVORE* raiz, int dado);
int busca(ARVORE* raiz, int dado);
int soma_xy(ARVORE* raiz, int x, int y);
void imprime(ARVORE* raiz);

#endif