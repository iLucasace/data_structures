#include <stdio.h>
#include <stdlib.h>

#include "aux.h"

//lista encadeada não ordenada com nó cabeça auxiliar...
void main() {
    Nó *cab = (Nó*)malloc(sizeof(Nó));
    cab->prox = NULL;

    inserir(cab, 18);
    inserir(cab, 5);
    inserir(cab, 24);
    imprimir(cab);

    remover(cab, 5);
    imprimir(cab);

    remover(cab, 10);
}