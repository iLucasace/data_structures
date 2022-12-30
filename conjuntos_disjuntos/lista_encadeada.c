#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct __nó {
    int valor;
    struct __nó *prox;
    struct __nó *repr;
} Nó;

Nó *conjuntos[TAM];

void MAKE_SET(Nó **conjuntos);
Nó *FIND_SET(Nó **conjuntos, int i);
void UNION(Nó **conjuntos, int x, int y);

void main() {
    MAKE_SET(conjuntos);
    UNION(conjuntos, 3, 8);
    UNION(conjuntos, 0, 3);

    UNION(conjuntos, 1, 4);
    UNION(conjuntos, 2, 1);
    UNION(conjuntos, 1, 7);

    for(int aux = 0; aux < TAM; aux++) {
        printf("Valor -> %d / Representante -> %d\n", conjuntos[aux]->valor, conjuntos[aux]->repr->valor);
    }
    printf("\n");
}

void MAKE_SET(Nó **conjuntos) {
    for(int aux = 0; aux < TAM; aux++) {
        conjuntos[aux] = (Nó*)malloc(sizeof(Nó));
        conjuntos[aux]->valor = aux;
        conjuntos[aux]->repr = conjuntos[aux];
        conjuntos[aux]->prox = NULL;
    }
}

Nó *FIND_SET(Nó **conjuntos, int i) {
    return conjuntos[i]->repr;
}

void UNION(Nó **conjuntos, int x, int y) {
    Nó *rx = FIND_SET(conjuntos, x);
    Nó *ry = FIND_SET(conjuntos, y);

    if(rx->repr == ry->repr)
        return;

    Nó *aux = rx;
    while(aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = ry;

    while(ry != NULL) {
        ry->repr = rx;
        ry = ry->prox;
    }
}