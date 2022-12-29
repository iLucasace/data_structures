typedef struct __nó {
    int valor;
    struct __nó *prox;
    struct __nó *ant;
} Nó;

void inserir(Nó *cab, int valor);
void remover(Nó *cab, int valor);
Nó *buscar(Nó *cab, int valor);
void imprimir(Nó *cab);