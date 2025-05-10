#include <stdio.h>
#include <stdlib.h>

#include "ls-encadeada.h"

struct no{
    int info;
    struct no *prox;
};

No *criaLista(){
    return NULL;
}

No *insereNoInicio(No *lista){
    No *novoNo;
    novoNo = (No *)malloc(sizeof(No));

    if(novoNo == NULL){
        printf("Erro ao alocar memoria.\n");
        return lista;
    }

    printf("Novo valor: "); scanf("%d", &novoNo->info);
    novoNo->prox = lista;

    return novoNo;
}

void mostraLista(No *lista){
    if(lista == NULL){
        printf("Lista Vazia.\n");
    }else{
        No *ls = lista;
        while(ls != NULL){
            printf("%d\n", ls->info);
            ls = ls->prox;
        }
    }
}

No *inseroNoFim(No *lista){
    No *novoNo = (No *)malloc(sizeof(No));

    if(novoNo == NULL){
        printf("Erro ao alocar memoria.\n");
        return lista;
    }

    printf("Novo valor: "); scanf("%d", &novoNo->info);
    novoNo->prox = NULL;

    if(lista == NULL){
        return novoNo;
    }

    No *ls = lista;

    while(1){
        if(ls->prox == NULL){
            ls->prox = novoNo;
            break;
        }

        ls = ls->prox;
    }

    return lista;
}

No *inserirElementoOrdenado(No* lista){
    No *novoNo = (No *)malloc(sizeof(No));

    if(novoNo == NULL){
        printf("Erro ao alocar memoria.\n");
        return lista;
    }

    printf("Novo valor: "); scanf("%d", &novoNo->info);
    novoNo->prox = NULL;

    if(lista == NULL || novoNo->info < lista->info){
        novoNo->prox = lista;
        return novoNo;
    }

    No *anterior = NULL;
    No *atual = lista;

    while(atual != NULL && atual->info < novoNo->info){
        anterior = atual;
        atual = atual->prox;
    }

    anterior->prox = novoNo;
    novoNo->prox = atual;

    return lista;
}

No *buscarElemento(No *lista, int valor) {
    No *ls = lista;

    while(ls != NULL){
        if(ls->info == valor){
            return ls;
        }
        ls = ls->prox;
    }

    return NULL;
}


void liberarLista(No *lista){
    No *ls = lista;
    No *proximo;

    while(ls != NULL){
        proximo = ls->prox;
        free(ls);
        ls = proximo;
    }
}