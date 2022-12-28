#include <stdio.h>

#include "clid.h"

void main() {
    int V[MAX];
    int topo;

    esvaziar(&topo);
    inserir(V, &topo, 7);
    inserir(V, &topo, 25);
    inserir(V, &topo, 9);
    inserir(V, &topo, 76);
    inserir(V, &topo, 88);

    imprimir(V, &topo);
}