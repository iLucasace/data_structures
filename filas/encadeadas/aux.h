typedef struct __nó {
    int valor;
    struct __nó *prox;
} Nó;

typedef struct {
    Nó *fre;
    Nó *ret;
} Fila;

void esvazia(Fila *fila);
void enfila(Fila *fila, int valor);
void desenfila(Fila *fila);
void imprimir(Fila *fila);