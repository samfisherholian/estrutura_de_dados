#ifndef _CONJUNTO_H
#define _conjunto_h

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct no_conj No_conj;

void conjunto_vazio(No_conj** head);
int tamanho_conjunto(No_conj* head);
int insercao(No_conj ** head, int dado);
void imprime_conj(No_conj* head);
int se_vazio(No_conj* head);
void remover(No_conj** head, int elemento);
int se_pertence_conj(No_conj* head, int elemento);
int maior_valor(No_conj* head);
int menor_valor(No_conj* head);
int se_conjunto_iguais(No_conj* headA, No_conj* headB);
No_conj* uniao(No_conj* headA, No_conj* headB);
No_conj* interseccao(No_conj* headA, No_conj* headB);
No_conj* diferenca(No_conj* headA, No_conj* headB);
void testa_conjunto();



#endif