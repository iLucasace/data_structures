#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct __nó {
    int chave;
    struct __nó *prox;
} Nó;

Nó *Lista[TAM];

int hash(int chave);
Nó *busca(int chave);
void insere(int chave);
void imprime();

void main() {
    insere(60);
    insere(15);
    insere(11);
    insere(90);
    insere(85);
    insere(54);
    insere(37);
    insere(78);
    insere(39);
    insere(76);

    imprime();
}

int hash(int chave) {
    return chave % TAM;
}

Nó *busca(int chave) {
    int id = hash(chave);
    Nó *aux = Lista[id];

    while(aux != NULL && aux->chave != chave) {
        aux = aux->prox;
    }

    return aux;
}

void insere(int chave) {
    int id = hash(chave);
    Nó *aux = busca(chave);

    if(aux == NULL) {
        Nó *novo = (Nó*)malloc(sizeof(Nó));
        novo->chave = chave;
        novo->prox = Lista[id];
        Lista[id] = novo;
    } else {
        printf("ERRO: Chave já inserida!\n");
    }
}

void imprime() {
    for(int aux = 0; aux < TAM; aux++) {
        Nó *atual = Lista[aux];

        while(atual != NULL) {
            printf("Indice -> %d / Chave -> %d\n", aux, atual->chave);
            atual = atual->prox;
        }
    }
    printf("\n");
}