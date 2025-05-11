#include <stdio.h>
#include <stdlib.h>

#include "ls-dp-encadeada.h"

typedef struct no{
    int info;
    No *prox, *ant;
}No;

No *createNo(){
    No *no = (No *)malloc(sizeof(No));
    if(!no) return NULL;
    return no;
}

No *criarLista(){
    return NULL;
}

No *inserirElementoInicio(No* lista){
    No *novo = createNo(); if(!novo) return lista;
    printf("Novo elemento: "); scanf("%d", &novo->info);
    novo->ant = NULL;
    if(!lista){
        novo->prox = lista;
        return novo;
    }
    novo->prox = lista;
    lista->ant = novo;
    return novo;
}

No * inserirElementoFinal(No* lista){
    No *novo = createNo(); if(!novo) return lista;
    printf("Novo elemento: "); scanf("%d", &novo->info);
    novo->prox = NULL;

    if(!lista){
        novo->ant = lista;
        return novo;
    }

    No *atual = lista;
    while(atual != NULL){
        if(atual->prox == NULL){
            atual->prox = novo;
            novo->ant = atual;
            break;
        }
        atual = atual->prox;
    }

    return lista;
}

No *inserirElementoOrdenado(No* lista){
    No *novo = createNo(); if(!novo) return lista;
    printf("Novo elemento: "); scanf("%d", &novo->info);
    novo->prox = NULL;
    novo->ant = NULL;

    if(!lista) return novo;
    if(novo->info <= lista->info){
        novo->prox = lista;
        lista->ant = novo;
        return novo;
    }

    No *atual = lista;
    No *ante = NULL;
    while(atual != NULL && novo->info >= atual->info){
        ante = atual;
        atual = atual->prox;
    }
    if(atual){
        ante->prox = novo;
        novo->ant = ante;
        novo->prox = atual;
        atual->ant = novo;
    }else{
        ante->prox = novo;
        novo->ant = ante; 
    }
    return lista;
}

No *removerElemento(No* lista, int valor){
    if(!lista) return lista;

    No *atual = lista;
    No *ante = NULL;

    while(atual != NULL && atual->info != valor){
        ante = atual;
        atual = atual->prox;
    }

    if(!atual) return lista;

    if(ante == NULL){
        No *novaCabeca = atual->prox;
        if(novaCabeca) novaCabeca->ant = NULL;
        free(atual);
        return novaCabeca;
    }else{
        No *proximo = atual->prox;
        ante->prox = proximo;
        if(proximo) proximo->ant = ante;
        free(atual);
    }

    return lista;
}

No *buscarElemento(No* lista, int valor){
    if(!lista) return lista;
    No *atual = lista;
    while(atual != NULL){
        if(atual->info == valor){
            return atual;
        }
        atual = atual->prox;
    }

    return NULL;
}

No *buscarElementoComVizinhos(No* lista, int valor){
    return buscarElemento(lista, valor);
}

void mostrarLista(No *lista){
    if(!lista){
        printf("Lista vazia!\n");
        return;
    }
    No *atual = lista;
    while(atual != NULL){
        printf("%d ", atual->info);
        atual = atual->prox;
    }
}
void liberarLista(No *lista){
    No *atual = lista;
    No *proximo = NULL;
    while(atual != NULL){
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
}
