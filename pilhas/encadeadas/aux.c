#include <stdio.h>
#include <stdlib.h>

#include "aux.h"

void esvazia(Pilha *pilha) {
    pilha->topo = NULL;
}

void push(Pilha *pilha, int valor) {
    Nó *novo = (Nó*)malloc(sizeof(Nó));
    novo->valor = valor;

    novo->prox = pilha->topo;
    pilha->topo = novo;
}

int pop(Pilha *pilha) {
    if(pilha->topo != NULL) {
        Nó *aux = pilha->topo;
        pilha->topo = pilha->topo->prox;
        free(aux);
    } else {
        printf("ERRO: Pilha está vazia!\n");
    }
}

void imprimir(Pilha *pilha) {
    Nó *aux = pilha->topo;
    printf("Pilha:\n");
    while(aux != NULL) {
        printf("%d\n", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}