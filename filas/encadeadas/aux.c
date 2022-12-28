#include <stdio.h>
#include <stdlib.h>

#include "aux.h"

void esvazia(Fila *fila) {
    fila->fre = NULL;
    fila->ret = NULL;
}

void enfila(Fila *fila, int valor) {
    Nó *novo = (Nó*)malloc(sizeof(Nó));
    novo->valor = valor;
    novo->prox = NULL;

    if(fila->ret != NULL)
        fila->ret->prox = novo;
    else
        fila->fre = novo;

    fila->ret = novo;
}

void desenfila(Fila *fila) {
    if(fila->fre != NULL) {
        Nó *aux = fila->fre;
        fila->fre = fila->fre->prox;
        free(aux);
        if(fila->fre == NULL)
            fila->ret = NULL;
    } else
        printf("ERRO: Fila vazia!\n");
}

void imprimir(Fila *fila) {
    Nó* aux = fila->fre;
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}