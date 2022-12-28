#include <stdio.h>

#define MAX 5

void esvazia(int *V, int *f, int *r) {
    *f = 0;
    *r = 0;
}

void enfila(int *V, int *f, int *r, int k) {
    int pos = (*r % MAX) + 1;

    if(pos != *f) {
        *r = pos;
        V[*r] = k;

        if(*f == 0)
            *f = 1;
    } else {
        printf("\nERRO: Fila cheia!\n");
    }
}

int desenfila(int *V, int *f, int *r) {
    if(*f != 0) {
        int k = V[*f];

        if(*f == *r) {
            esvazia(V, f, r);
        } else {
            *f = (*f % MAX) + 1;
            return k;
        }
    } else {
        printf("\nERRO: Fila vazia!\n");
    }
}