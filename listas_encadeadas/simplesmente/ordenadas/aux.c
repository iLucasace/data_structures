#include <stdio.h>
#include <stdlib.h>

#include "aux.h"

void inserir(Nó *cab, int valor) {
    RetornoBusca *cont = busca(cab, valor);
    Nó *atual = cont->atual;
    Nó *ant = cont->ant;

    if(atual == NULL) {
        Nó *novo = (Nó*)malloc(sizeof(Nó));
        novo->valor = valor;
    
        novo->prox = ant->prox;
        ant->prox = novo;
    } else {
        printf("ERRO: %d já está na lista!\n", valor);
    }
}

void remover(Nó *cab, int valor) {
    RetornoBusca *cont = busca(cab, valor);
    Nó *atual = cont->atual;
    Nó *ant = cont->ant;

    if(atual != NULL) {
        ant->prox = atual->prox;
        free(atual);
    } else {
        printf("ERRO: %d não está na lista!", valor);
    }
}

RetornoBusca *busca(Nó *cab, int k) {
    Nó *p = cab->prox;
    Nó *ant = cab;
    Nó *atual = NULL;

    RetornoBusca *retorno = (RetornoBusca*)malloc(sizeof(RetornoBusca));

    while(p != NULL) {
        if(p->valor < k) {
            ant = p;
            p = p->prox;
        } else{
            if(p->valor == k) {
                atual = p;
            }
            p = NULL;
        }
    }

    retorno->ant = ant;
    retorno->atual = atual;
    return retorno;
}

void imprimir(Nó *cab) {
    Nó *p;
    p = cab->prox;
    while(p != NULL) {
        printf("%d ", p->valor);
        p = p->prox;
    }
    printf("\n");
}