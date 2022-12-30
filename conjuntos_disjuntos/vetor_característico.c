#include <stdio.h>
#include <stdlib.h>

#define TAM 10
int vetor[TAM];

void MAKE_SET(int *vetor);
int FIND_SET(int *vetor, int i);
void UNION(int *vetor, int x, int y);

void main() {
    MAKE_SET(vetor);
    UNION(vetor, 3, 8);
    UNION(vetor, 0, 3);
    UNION(vetor, 1, 4);

    for(int aux = 0; aux < TAM; aux++) {
        printf("Valor -> %d / Representante -> %d\n", aux, vetor[aux]);
    }
    printf("\n");
}

void MAKE_SET(int *vetor) {
    for(int aux = 0; aux < TAM; aux++) {
        vetor[aux] = aux;
    }
}

int FIND_SET(int *vetor, int i) {
    return vetor[i];
}

void UNION(int *vetor, int x, int y) {
    int rx = FIND_SET(vetor, x);
    int ry = FIND_SET(vetor, y);

    if(rx == ry) 
        return;

    for(int aux = 0; aux < TAM; aux++) {
        if(vetor[aux] == ry)
            vetor[aux] = rx;
    }
}