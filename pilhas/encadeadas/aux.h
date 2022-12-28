typedef struct __nó {
    int valor;
    struct __nó *prox;
} Nó;

typedef struct {
    Nó *topo;
} Pilha;

void esvazia(Pilha *pilha);
void push(Pilha *pilha, int valor);
int pop(Pilha *pilha);
void imprimir(Pilha *pilha);