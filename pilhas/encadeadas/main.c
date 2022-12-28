#include <stdlib.h>
#include "aux.h"

void main() {
    Pilha *pilha;
    pilha->topo = NULL;

    push(pilha, 44);
    push(pilha, 23);
    push(pilha, 31);
    imprimir(pilha);

    pop(pilha);
    imprimir(pilha);

    esvazia(pilha);
    imprimir(pilha);
}