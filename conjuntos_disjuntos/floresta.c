#include <stdio.h>

#define TAM 10

int pai[TAM];
int rank[TAM];

void MAKE_SET();
int FIND_SET(int valor);
void UNION(int x, int y);

void main() {
    MAKE_SET();
    UNION(3, 8);
    UNION(0, 3);

    UNION(1, 4);
    UNION(2, 1);
    UNION(1, 7);

    for(int aux = 0; aux < TAM; aux++) {
        printf("Valor -> %d / Pai -> %d\n", aux, pai[aux]);
    }
    printf("\n");
}

void MAKE_SET() {
    for(int aux = 0; aux < TAM; aux++) {
        pai[aux] = aux;
        rank[aux] = aux;
    }
}

int FIND_SET(int valor) {
    if(valor != pai[valor])
        pai[valor] = FIND_SET(pai[valor]);
    else
        return pai[valor];
}

void UNION(int x, int y) {
    int rx = FIND_SET(x);
    int ry = FIND_SET(y);

    if(rx == ry)
        return;
    
    if(rank[rx] > rank[ry]) {
        pai[ry] = rx;
    } else {
        pai[rx] = ry;

        if(rank[rx] == rank[ry])
            rank[ry] = rank[ry] + 1;
    }
}