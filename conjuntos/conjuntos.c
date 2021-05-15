#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "conjuntos.h"

#define tipo float

struct no_conj {

    int dado;
    struct no_conj* next;
    
};

int insercao(No_conj** head, int dado){
    
    No_conj* no =(No_conj*) malloc(sizeof(No_conj));


    if(se_pertence_conj(*head, dado)){

        printf("erro o elemento já está no conjunto\n");

        return 0;

    }

    if(no){
            
        no->dado = dado;
        no->next = *head;
        *head = no;
        return 1;
    }
            
    return 0;
}

void imprime_conj(No_conj* head){


    printf("list is..");

    while(head != NULL){
        
        printf("%i,",head->dado);
        head = head ->next;
    }
    
    printf("\n");
}
// tamanho do conjunto de forma recursiva
int tamanho_conjunto(No_conj* head){

    if(head == NULL){
        return 0;
    }
    
    return 1 + tamanho_conjunto(head->next);

}

void conjunto_vazio(No_conj** head){

    No_conj* next = NULL;
    No_conj* secondNO = *head;

    while(secondNO != NULL){
        next = secondNO->next;
        free(secondNO);
        secondNO = next;
    }

    *head = NULL;
}

int se_vazio(No_conj* head){

    return (head == NULL);

}

void remover(No_conj** head, int elemento){
    
    No_conj* temp = *head;
    No_conj* anterior;
    
    // se o nó possuir o dado do elemento a ser deletado
    if(temp != NULL && temp->dado == elemento){

        // o nó sequinte passa a ser a cabeça do nó
        *head = temp->next;
        free(temp);
        return;
    }

    //procura pelo elemento a ser deletado 
    while(temp != NULL && temp->dado != elemento){
        // o nó anterior passa a ser o seguinte
        anterior = temp;
        temp = temp->next;
    }

    if(temp == NULL) return;

    // desivincula o nó
    anterior->next = temp->next;

    free(temp);
}

int se_pertence_conj(No_conj* head, int elemento){

    while(head != NULL){

        if(head->dado == elemento)
            return 1;
        head =  head->next;    

    }

    return 0;
}

int maior_valor(No_conj* head){

    int maior = 0;
    while(head != NULL){

        if(maior < head->dado){

            maior = head->dado;
        }

        head =  head->next;
    }

    return maior;
}


int menor_valor(No_conj* head){

    int menor = INT_MAX;

    while(head != NULL){

        if(menor > head->dado)

            menor = head->dado;
  
        head =  head->next;

    }
         return menor;
}

int se_conjunto_iguais(No_conj* headA, No_conj* headB){

    while(headA != NULL && headB != NULL){

        if(headA->dado != headB->dado){

            return 0;

        }else{

            headA = headA->next;
            headB = headB->next;

        }   

    }

    return (headA == NULL && headB == NULL);
    
}

No_conj* interseccao(No_conj* headA, No_conj* headB){

   No_conj* resultado = NULL;
   No_conj* ti = headA;

   while(ti != NULL){
       if(se_pertence_conj(headB,ti->dado))
            insercao(&resultado,ti->dado);
       ti = ti->next;     
   }

   return  resultado;

}


No_conj* uniao(No_conj* headA, No_conj* headB){

        No_conj* resultado = NULL;
        No_conj* list1 = headA, *list2 = headB;

        while(list1 != NULL){
            insercao(&resultado,list1->dado);
            list1 = list1->next;
        }


        while(list2 != NULL){
            if(!se_pertence_conj(resultado,list2->dado))
                insercao(&resultado, list2->dado);
            list2 = list2 -> next;    
        }

        return resultado;
      
}

No_conj* diferenca(No_conj* headA, No_conj* headB){

        No_conj* resultado = NULL, *aux =  NULL;
        No_conj* list1 = headA, *list2 = headB;

        while(list1 != NULL){
            insercao(&resultado,list1->dado);
            list1 = list1->next;
        }


        while(list2 != NULL){

            if(!se_pertence_conj(list1,list2->dado)){
                remover(&resultado,list2->dado);
            }else{
                insercao(&resultado,list2->dado);
            }

            list2 = list2 -> next;    
        }
        
        return resultado;

}
void testa_conjunto(){

     No_conj* conjA = NULL;

    printf("conjunto A\n");
    insercao(&conjA,5);
    insercao(&conjA,4);
    insercao(&conjA,3);
    insercao(&conjA,2);
    insercao(&conjA,1);
    insercao(&conjA,7);
    imprime_conj(conjA);

    printf("\n");

    printf("maior numero eh %i\n", maior_valor(conjA));
    printf("menor numero eh %i\n", menor_valor(conjA));
    printf("tamanho do conjunto A = %d\n", tamanho_conjunto(conjA));

    printf("\n");

    printf("removendo elemento 7\n");
    remover(&conjA,7);

    printf("\n");

    printf("tamanho do conjunto A atualizado tamanho = %d\n", tamanho_conjunto(conjA));

    imprime_conj(conjA);

    printf("\n");

    printf("conjunto A se uma numero pertence \n");

    se_pertence_conj(conjA,8)? printf("o elemento 8 existe\n"): printf("o elemento 8 nao existe\n");

    No_conj* conjB = NULL;
    
    printf("conjunto B\n");
    insercao(&conjB,1);
    insercao(&conjB,2);
    insercao(&conjB,3);
    imprime_conj(conjB);

    printf("\n");

    se_conjunto_iguais(conjA, conjB)? printf("sao iguais\n"): printf("nao sao iguais\n");

   //interseccao(conjA, conjB);

    printf("\n");

    printf("inserseccao\n");
    No_conj* head = NULL;

    head = interseccao(conjA,conjB);

    imprime_conj(head);

    printf("\n");

    printf("uniao\n");
    uniao(conjA,conjB);

    imprime_conj(uniao(conjA,conjB));

    printf("\n");

    printf("diferenca\n");

    diferenca(conjA,conjB);

    imprime_conj(diferenca(conjA,conjB));


    printf("destruindo o conjunto A");
    conjunto_vazio(&conjA);

    printf("\n");

    printf("destruindo o conjunto B\n");
    conjunto_vazio(&conjB);

    printf("\n");

    printf("imprimindo o conjunto vazio A\n");
    imprime_conj(conjA);

    printf("\n");

    printf("imprimindo o conjunto B\n");
    imprime_conj(conjB);
    
    printf("\n");

    printf("se o conjunto A esta vazio\n");
    se_vazio(conjA)? printf("o conjunto esta vazio\n"): printf("o conjunto nao esta vazio\n");

    printf("\n");

    printf("se o cojunto B esta vazio\n");
    se_vazio(conjB)? printf("o conjunto esta vazio\n"): printf("o conjunto nao esta vazio\n");

    printf("\n");

    No_conj* conjC = NULL;
    No_conj* conjD = NULL;

    insercao(&conjC, 6);
    insercao(&conjC, 2);
    insercao(&conjC, 8);
    insercao(&conjC, 9);

    printf("imprimindo o conjunto C\n");
    imprime_conj(conjC);

    printf("\n");

    printf("maior numero eh %i\n", maior_valor(conjC));
    printf("menor numero eh %i\n", menor_valor(conjC));
    printf("tamanho do conjunto C = %d\n", tamanho_conjunto(conjC));

    printf("\n");

    printf("conjunto C se uma numero pertence \n");

    se_pertence_conj(conjC,8)? printf("o elemento 8 existe\n"): printf("o elemento 8 nao existe\n");

    printf("\n");

    insercao(&conjD, 6);
    insercao(&conjD, 2);
    insercao(&conjD, 8);
    insercao(&conjD, 9);

    printf("\n");

    printf("imprimindo o conjuno D\n");
    imprime_conj(conjD);

    printf("\n");

    printf("verificando se o conjunto c eh igual d\n");
    se_conjunto_iguais(conjC, conjD)? printf("sao iguais\n"): printf("nao sao iguais\n");


    printf("destruindo o conjunto C");
    conjunto_vazio(&conjC);

    printf("\n");

    printf("destruindo o conjunto D\n");
    conjunto_vazio(&conjD);

    printf("\n");

    printf("imprimindo o conjunto vazio C\n");
    imprime_conj(conjC);

    printf("\n");

    printf("imprimindo o conjunto D\n");
    imprime_conj(conjD);
    
    printf("\n");

    printf("se o conjunto C esta vazio\n");
    se_vazio(conjC)? printf("o conjunto esta vazio\n"): printf("o conjunto nao esta vazio\n");

    printf("\n");

    printf("se o cojunto D esta vazio\n");
    se_vazio(conjD)? printf("o conjunto esta vazio\n"): printf("o conjunto nao esta vazio\n");

}
