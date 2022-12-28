
#include "clid.h"

void main() {
    int V[MAX];
    int f, r;

    esvazia(V, &f, &r);
    enfila(V, &f, &r, 10);
    enfila(V, &f, &r, 20);
    enfila(V, &f, &r, 30);

    desenfila(V, &f, &r);
}