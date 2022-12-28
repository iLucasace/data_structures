#include <stdio.h>

#include "clid.h"

void esvaziar(int *topo) {
    *topo = 0;
}

void inserir(int *V, int *topo, int k) {
    if(*topo != MAX) {
        (*topo)++;
        V[*topo] = k;
    } else {
        printf("\nERRO: Fila cheia!\n");
    }
}

int remover(int *V, int *topo) {
    if(*topo > 0) {
        int k = V[*topo];
        (*topo)--;
        return k;
    } else {
        printf("\nERRO: Fila vazia!\n");
    }
}

void imprimir(int *V, int *topo) {
    int i = *topo;
    while(i > 0) {
        printf("%d\n", V[i]);
        i--;
    }
    printf("\n");
}