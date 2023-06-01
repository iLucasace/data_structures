#include <stdio.h>
#include <stdlib.h>

#define BRANCO 0
#define CINZA 1
#define PRETO 2

typedef struct __nó {
    int valor;
    int peso;
    struct __nó *prox;
} Nó;

void inicializa_lista(int nos, Nó **lista){
    for(int i = 0; i < nos; i++){
        lista[i] = NULL;
    }
}

void inserir_lista(Nó **lista, int A, int B, int peso){
    Nó *novo = (Nó*)malloc(sizeof(Nó));
    novo->valor = A;
    novo->peso = peso;
    novo ->prox = lista[B];
    lista[B] = novo;
}

void imprimir_lista(Nó **lista, int nos) {
    for(int i = 0; i < nos; i++){
        printf("\nNó %d: ", i +1);
        Nó *aux = lista[i];
        while(aux != NULL){
            printf("%d -> ", aux->valor + 1);
            aux = aux->prox;
            }
    }
    printf("\n\n");
}

void todos_graus(int nos, Nó **lista){
    printf("\nGraus:\n");
    int contador = 0;
    for(int i = 0; i < nos; i++){
        Nó *aux = lista[i];
        while(aux != NULL){
            contador++;
            aux = aux->prox;
        }

        printf("g(%d) = %d\n", i, contador);
        contador = 0;
    }
    printf("\n");
}

int grau_no(int nos, int grau_no, Nó **lista){
    int contador = 0;
    
    Nó *aux = lista[grau_no];
    while(aux != NULL){
        contador++;
        aux = aux->prox;
    }

    return contador;
}

void vertice_isolado(int nos, Nó **lista) {
    int contador = 0, quantidade = 0;
    for(int i = 0; i < nos; i++){
        contador = grau_no(nos, i, lista);
        
        if(contador == 0){
            printf("O vértice %d está isolado.\n", i);
            quantidade++;
        }
    }

    printf("\nA quantidade de vértices isolados é %d.\n", quantidade);
}

void loop(int nos, Nó **lista){
    int contador = 0;

    for(int i = 0; i < nos; i++){
        Nó *aux = lista[i];

        while(aux != NULL){
            if(aux->valor == i){
                printf("Há um loop no vértice %d.\n", i);
                contador++;
                break;
            }

            aux = aux->prox;
        }
    }

    printf("A quantidade de loops é %d.\n\n", contador);
}

void regular(int nos, Nó **lista){
    int grau_vertice = grau_no(nos, 0, lista);
    
    for(int i = 1; i < nos; i++){
        if(grau_no(nos, i, lista) != grau_vertice){
            printf("Grafo não é regular.\n\n");
            return;
        }
    }

    printf("Grafo é regular!\n\n");
}

void grau_minimo(int nos, Nó **lista){
    int grau_min = grau_no(nos , 0, lista);
    
    for(int i = 0; i < nos; i++){
        int grau_vertice = grau_no(nos, i, lista);
        if(grau_vertice < grau_min){
            grau_min = grau_vertice;
        }
    }

    printf("O grau mínimo é %d.\n\n", grau_min);
}

void grau_maximo(int nos, Nó **lista){
    int grau_max = grau_no(nos , 0, lista);
    
    for(int i = 0; i < nos; i++){
        int grau_vertice = grau_no(nos, i, lista);
        if(grau_vertice > grau_max){
            grau_max = grau_vertice;
        }
    }

    printf("O grau máximo é %d.\n", grau_max);
}

void adiciona_arestas(int nos, int tipo, Nó **lista){
    int A, B, peso;
    scanf("%d %d", &A, &B);

    if(nos > A > nos || nos > B > nos){
        return;
    }

    if(tipo == 0){
        peso = 0;

        inserir_lista(lista, A - 1, B - 1, peso);
        inserir_lista(lista, B - 1, A - 1, peso);

    } else if(tipo == 1){
        scanf("%d", &peso);

        inserir_lista(lista, A - 1, B - 1, peso);
        inserir_lista(lista, B - 1, A - 1, peso);

    } else if(tipo == 2){
        peso = 0;

        inserir_lista(lista, A - 1, B - 1, peso);

    } else if(tipo == 3){
        scanf("%d", &peso);

        inserir_lista(lista, A - 1, B - 1, peso);
    }
}

int arestas_paralelas(int nos, Nó** lista) {
    for (int i = 0; i < nos; i++) {
        Nó* atual = lista[i];
        while (atual != NULL) {
            Nó* prox = atual->prox;
            while (prox != NULL) {
                if (atual->valor == prox->valor) {
                    return 1; // Arestas paralelas encontradas
                }
                prox = prox->prox;
            }
            atual = atual->prox;
        }
    }
    return 0; // Não há arestas paralelas
}

void completo(int nos, Nó** lista) {
    if (arestas_paralelas(nos, lista)) {
        printf("Grafo não é completo.\n");
        return;
    }

    for (int i = 0; i < nos; i++) {
        Nó* atual = lista[i];
        int grau = 0;
        while (atual != NULL) {
            grau++;
            atual = atual->prox;
        }
        if (grau != nos - 1) {
            printf("Grafo não é completo.\n");
            return;
        }
    }

    printf("Grafo é completo.\n");
}

void adiciona_no(int nos, Nó ***lista) {
    *lista = (Nó**)realloc(*lista, (nos + 1) * sizeof(Nó*));

    (*lista)[nos - 1] = NULL;
}

void remove_no(int no, Nó **lista) {
    int nos = no - 1;
    for (int i = 0; i < nos; i++) {
        Nó *atual = lista[i];
        Nó *anterior = NULL;

        while (atual != NULL) {
            if (atual->valor == nos) {
                if (anterior != NULL) {
                    anterior->prox = atual->prox;
                } else {
                    lista[i] = atual->prox;
                }

                Nó *temp = atual;
                atual = atual->prox;
                free(temp);
            } else {
                anterior = atual;
                atual = atual->prox;
            }
        }
    }

    free(lista[nos]);
    lista[nos] = NULL;
}

void remover_aresta(int nos, int noOrigem, int noDestino, int tipo, Nó **lista){
    if(tipo == 0 || tipo == 1){
        Nó *atualOrigem = lista[noOrigem - 1];
        Nó *antOrigem = NULL;

        while (atualOrigem != NULL && atualOrigem->valor != noDestino - 1) {
            antOrigem = atualOrigem;
            atualOrigem = atualOrigem->prox;
        }

        if(atualOrigem != NULL){
            if(antOrigem != NULL){
                antOrigem->prox = atualOrigem->prox;
            } else {
                lista[noOrigem - 1] = atualOrigem->prox;
            }
            free(atualOrigem);
        }

        Nó *atualDestino = lista[noOrigem - 1];
        Nó *antDestino = NULL;

        while (atualDestino != NULL && atualDestino->valor != noDestino - 1) {
            antDestino = atualDestino;
            atualDestino = atualDestino->prox;
        }

        if(atualDestino != NULL){
            if(antDestino != NULL){
                antDestino->prox = atualDestino->prox;
            } else {
                lista[noDestino - 1] = atualDestino->prox;
            }
            free(atualDestino);
        }
        

    } else if(tipo == 2 || tipo == 3) {
        Nó *atualOrigem = lista[noOrigem];
        Nó *antOrigem = NULL;

        while (atualOrigem != NULL && atualOrigem->valor != noDestino) {
            antOrigem = atualOrigem;
            atualOrigem = atualOrigem->prox;
        }

        if(atualOrigem != NULL){
            if(antOrigem != NULL){
                antOrigem->prox = atualOrigem->prox;
            } else {
                lista[noOrigem] = atualOrigem->prox;
            }
            free(atualOrigem);
        }
    }
}

void bfs(int nos, Nó** lista, int no_inicial) {
    int* d = (int*)malloc(nos * sizeof(int)); // Distância do nó inicial para os demais
    int* pi = (int*)malloc(nos * sizeof(int)); // Nó pai na árvore de busca em largura
    int* cor = (int*)malloc(nos * sizeof(int)); // Cor dos nós
    int* Q = (int*)malloc(nos * sizeof(int)); // Fila para controlar o acesso aos nós
    int frente = 0, tras = 0; // Ponteiros para a frente e trás da fila

    // Inicializa os vetores d, pi e cor
    for (int i = 0; i < nos; i++) {
        d[i] = -1;
        pi[i] = -1;
        cor[i] = BRANCO;
    }

    // Define o nó inicial
    d[no_inicial] = 0;
    cor[no_inicial] = CINZA;
    Q[tras++] = no_inicial;

    while (frente != tras) {
        int u = Q[frente++];
        printf("Explorando nó: %d\n", u + 1);

        Nó* aux = lista[u];
        while (aux != NULL) {
            int v = aux->valor;
            if (cor[v] == BRANCO) {
                cor[v] = CINZA;
                d[v] = d[u] + 1;
                pi[v] = u;
                Q[tras++] = v;
            }
            aux = aux->prox;
        }
        cor[u] = PRETO;

        // Imprime os vetores d, pi, cor e Q após cada iteração
        printf("Vetor d: ");
        for (int i = 0; i < nos; i++) {
            printf("%d ", d[i]);
        }
        printf("\n");

        printf("Vetor pi: ");
        for (int i = 0; i < nos; i++) {
            printf("%d ", pi[i]);
        }
        printf("\n");

        printf("Vetor cor: ");
        for (int i = 0; i < nos; i++) {
            printf("%d ", cor[i]);
        }
        printf("\n");

        printf("Fila Q: ");
        for (int i = 0; i < tras; i++) {
            printf("%d ", Q[i] + 1);
        }
        printf("\n\n");
    }

    free(d);
    free(pi);
    free(cor);
    free(Q);
}

void imprimir_vetores(int *d, int *f, int *cor, int *pi, int nos) {
    printf("Vetor d: ");
    for(int i = 0; i < nos; i++) {
        printf("%d ", d[i]);
    }
    printf("\n");

    printf("Vetor f: ");
    for(int i = 0; i < nos; i++) {
        printf("%d ", f[i]);
    }
    printf("\n");

    printf("Vetor cor: ");
    for(int i = 0; i < nos; i++) {
        printf("%d ", cor[i]);
    }
    printf("\n");

    printf("Vetor pi: ");
    for(int i = 0; i < nos; i++) {
        printf("%d ", pi[i]);
    }
    printf("\n\n");
}

void dfs_visit(Nó **lista, int u, int *cor, int *d, int *f, int *pi, int *tempo, int nos) {
    (*tempo)++;
    d[u] = *tempo;
    cor[u] = CINZA; // Marcar o nó como visitado (cor cinza)
    printf("Visitando nó: %d\n", u + 1);

    imprimir_vetores(d, f, cor, pi, nos);

    Nó *vizinho = lista[u];
    while(vizinho != NULL) {
        int v = vizinho->valor;
        if(cor[v] == BRANCO) { // Se o vizinho ainda não foi visitado
            pi[v] = u;
            dfs_visit(lista, v, cor, d, f, pi, tempo, nos);
        }
        vizinho = vizinho->prox;
    }

    cor[u] = PRETO; // Marcar o nó como finalizado (cor preta)
    (*tempo)++;
    f[u] = *tempo;

    imprimir_vetores(d, f, cor, pi, nos);
}

void dfs(Nó **lista, int nos) {
    int *cor = (int*)malloc(nos * sizeof(int));
    int *d = (int*)malloc(nos * sizeof(int));
    int *f = (int*)malloc(nos * sizeof(int));
    int *pi = (int*)malloc(nos * sizeof(int));
    int tempo = 0;

    for(int i = 0; i < nos; i++) {
        cor[i] = BRANCO;
        pi[i] = -1;
    }

    for(int i = 0; i < nos; i++) {
        if(cor[i] == BRANCO) {
            dfs_visit(lista, i, cor, d, f, pi, &tempo, nos);
        }
    }

    imprimir_vetores(d, f, cor, pi, nos);
}
    
int main(){
    int nos, arestas, tipo;
    scanf("%d %d %d", &nos, &arestas, &tipo);

    Nó *lista[nos];
    inicializa_lista(nos, lista);

    for(int i = 0; i < arestas; i++){
        int A, B, peso;
        scanf("%d %d", &A, &B);

        if(tipo == 0){
            peso = 0;

            inserir_lista(lista, A - 1, B - 1, peso);
            inserir_lista(lista, B - 1, A - 1, peso);

        } else if(tipo == 1){
            scanf("%d", &peso);

            inserir_lista(lista, A - 1, B - 1, peso);
            inserir_lista(lista, B - 1, A - 1, peso);

        } else if(tipo == 2){
            peso = 0;

            inserir_lista(lista, A - 1, B - 1, peso);

        } else if(tipo == 3){
            scanf("%d", &peso);

            inserir_lista(lista, A - 1, B - 1, peso);
        }
    }

    imprimir_lista(lista, nos);
    loop(nos, lista);

    if (arestas_paralelas(nos, lista)) {
        printf("Há arestas paralelas.\n");
    } else {
        printf("Não há arestas paralelas.\n");
    }

    vertice_isolado(nos, lista);

    todos_graus(nos, lista);
    grau_maximo(nos, lista);
    grau_minimo(nos, lista);
    
    completo(nos, lista);
    regular(nos, lista);


    printf("--------------------\nBFS:\n\n");
    bfs(nos, lista, 1 - 1);
    printf("--------------------\nDFS:\n\n");
    dfs(lista, nos);

}