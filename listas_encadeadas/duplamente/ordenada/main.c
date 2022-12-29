#include <stdlib.h>

#include "aux.h"

void main() {
    Nó *cab = (Nó*)malloc(sizeof(Nó));
    cab->ant = cab;
    cab->prox = cab;

    inserir(cab, 10);
    inserir(cab, 5);
    inserir(cab, 20);
    imprimir(cab);

    remover(cab, 10);
    imprimir(cab);
}