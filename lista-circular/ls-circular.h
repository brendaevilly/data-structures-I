#ifndef LS_CIRCULAR_
#define LS_CIRCULAR_

typedef struct no No;

No *createNo();

No *criarListaCircular();
No *inserirElemento(No* lista);
No *buscarElemento(No *lista, int valor);
No *inserirElementoOrdenado(No* lista);
No *removerElemento(No* lista, int valor);
void mostrarLista(No *lista);
void liberarLista(No *lista);
void mostrarElementoInicio(No *lista);
void mostrarElementoFim(No *lista);

#endif