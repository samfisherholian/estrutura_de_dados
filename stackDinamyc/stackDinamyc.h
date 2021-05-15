#ifndef _STACKDINAMYC_

#define _stackdinamyc_
// irei chamar todas as funcoes aqui.

typedef struct stackdinamyc STACKDINAMYC;   


STACKDINAMYC* createStack(int tamanho);
int push(STACKDINAMYC* stack,int dado);
int isEmpty(STACKDINAMYC* stack);
int pop(STACKDINAMYC* stack);
void printStackDi(STACKDINAMYC* stack);
int topStack(STACKDINAMYC* stack);
int isFull(STACKDINAMYC* stack);

#endif