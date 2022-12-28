typedef struct __nó {
    struct __nó *prox;
    int valor;
} Nó;

typedef struct {
    Nó *ant;
    Nó *atual;
} RetornoBusca;

void inserir(Nó *cab, int valor);
void remover(Nó *cab, int valor);
RetornoBusca *busca(Nó *cab, int k);
void imprimir(Nó *cab);