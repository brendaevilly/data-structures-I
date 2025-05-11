#ifndef LS_DP_ENCADEADA
#define LS_DP_ENCADEADA

typedef struct no No;

No *createNo();

No *criarLista();
No *inserirElementoInicio(No* lista);
No * inserirElementoFinal(No* lista);
No *inserirElementoOrdenado(No* lista);
No *removerElemento(No* lista, int valor);
No *buscarElemento(No* lista, int valor);
No *buscarElementoComVizinhos(No* lista, int valor);
void mostrarLista(No *lista);
void liberarLista(No *lista);

#endif