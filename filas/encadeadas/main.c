#include <stdlib.h>

#include "aux.h"

void main() {
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    fila->fre = NULL;
    fila->ret = NULL;

    enfila(fila, 44);
    enfila(fila, 23);
    enfila(fila, 31);
    imprimir(fila);

    desenfila(fila);
    imprimir(fila);

    esvazia(fila);
    imprimir(fila);
}