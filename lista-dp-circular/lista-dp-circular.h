#ifndef LISTA_DP_CIRCULAR
#define LISTA_DP_CIRCULAR

    typedef struct no No;
    No *criarLista();
    No *createNo();
    No *inserirOrdenado(No *lista, int valor);
    No *removerElemento(No *lista, int valor);
    void mostrarLista(No *lista);
    void liberarLista(No *lista);

#endif