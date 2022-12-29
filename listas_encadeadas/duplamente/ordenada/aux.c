#include <stdio.h>
#include <stdlib.h>

#include "aux.h"

void inserir(Nó *cab, int valor) {
    Nó *pont = buscar(cab, valor);

    if(pont->valor != valor || pont == cab) {
        Nó *novo = (Nó*)malloc(sizeof(Nó));
        Nó *aux = pont->ant;

        novo->valor = valor;
        novo->prox = pont;
        novo->ant = aux;
        aux->prox = novo;
        pont->ant = novo;
    } else
        printf("ERRO: Valor já inserido!\n");
}

void remover(Nó *cab, int valor) {
    Nó *pont = buscar(cab, valor);

    if(pont != cab && pont->valor == valor) {
        pont->ant->prox = pont->prox;
        pont->prox->ant = pont->ant;
        free(pont);
    } else {
        printf("ERRO: Valor não está na lista!\n");
    }
}

Nó *buscar(Nó *cab, int valor) {
    cab->valor = valor;
    Nó *pont = cab->prox;

    while(pont->valor < valor) {
        pont = pont->prox;
    }
    
    return pont;
}

void imprimir(Nó *cab) {
    Nó *aux = cab->prox;
    while(aux != cab) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}