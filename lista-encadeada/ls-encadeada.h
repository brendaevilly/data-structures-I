#ifndef LSENCADEADA_H
#define LSENCADEADA_H

typedef struct no No;

No *criaLista();
No *insereNoInicio(No *lista);
void mostraLista(No *lista);
No *inseroNoFim(No *lista);
No *inserirElementoOrdenado(No* lista);
void liberarLista(No *lista);
No *buscarElemento(No *lista, int valor);

#endif