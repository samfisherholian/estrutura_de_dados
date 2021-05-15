#ifndef _LIKENDSTACK_
#define _likendstack_

typedef struct stack STACK;

int push(STACK ** pilha, int valor);
int pop(STACK ** pilha);
void printStack(STACK* pilha);
int topStack(STACK* pilha);
int isEmpety(STACK* pilha);
void clear_Stack(STACK** pilha);

#endif
