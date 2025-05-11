#include <stdio.h>
#include <stdlib.h>

#include "ls-circular.h"

typedef struct no{
    int info;
    No *prox;
}No;

No *criarListaCircular(){
    return NULL;
}

No *createNo(){
    No *no = (No *)malloc(sizeof(No));
    if(!no) return NULL;
    return no;
}

No *inserirElemento(No* lista){
    No *novo = createNo();
    if(!novo) return lista;
    printf("Novo elemento: "); scanf("%d", &novo->info);
    
    if(!lista){
        novo->prox = novo;
        return novo;
    }
    
    if(lista->prox == lista){
        novo->prox = lista;
        lista->prox = novo;
        return novo;
    }

    No *end = lista;
    while(end->prox != lista) end = end->prox;
    end->prox = novo;
    novo->prox = lista;
    return novo;
}

No *buscarElemento(No *lista, int valor){
    if(!lista) return lista; 
    if(lista->info == valor) return lista;

    No *ls = lista->prox;
    while(ls != lista){
        if(ls->info == valor) return ls;
        ls = ls->prox;
    }

    return NULL;
}

No *inserirElementoOrdenado(No* lista){
    No *novo = createNo(); if(!novo) return lista;
    printf("Novo elemento: "); scanf("%d", &novo->info);
    if(!lista) return novo;

    No *atual = lista;
    No *end = NULL;

    if(novo->info <= lista->info){
        novo->prox = lista;
        while(atual->prox != lista) atual = atual->prox;
        atual->prox = novo;
        return novo;
    }else{
        while(atual->prox != lista && atual->info <= novo->info){
            end = atual;
            atual = atual->prox;
        }
    }

    if(atual->info >= novo->info){
        novo->prox = atual;
        end->prox = novo;
    }else{
        atual->prox = novo;
        novo->prox = lista;
    }

    return lista;
}

No *removerElemento(No* lista, int valor){
    if(!lista) return lista;
    
    if(lista == lista->prox){
        if(lista->info == valor){
            free(lista);
            return NULL;
        }else{
            return lista;
        }
    }

    No *atual = lista;
    No *ant = NULL;

    do{
        if(atual->info == valor){
            if(atual == lista){
                No *aux = lista;
                while(aux->prox != lista) aux = aux->prox;
                aux->prox = lista->prox;
                No *novaCabeca = lista->prox;
                free(lista);
                return novaCabeca;
            }
            ant->prox = atual->prox;
            free(atual);
            return lista;
        }
        ant = atual;
        atual = atual->prox;
    }while(atual != lista);

    return lista;
}

void mostrarLista(No *lista){
    if(!lista || !lista->prox){
        printf("Lista vazia ou corrompida!\n");
        return;  
    } 

    No *atual = lista;
    do{
        printf("%d ", atual->info);
        atual = atual->prox;
    }while(atual != lista);
    printf("\n");
}

void liberarLista(No *lista){
    No *atual = lista;
    No *proximo = NULL;

    while(atual->prox != lista){
        proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
}

void mostrarElementoInicio(No *lista){
    if(!lista){
        printf("Lista vazia!\n");
        return;
    }
    printf("Elemento inicial: %d\n", lista->info);
}

void mostrarElementoFim(No *lista){
    if(!lista){
        printf("Lista vazia!\n");
        return;
    }
    No *atual = lista;
    while(atual->prox != lista) atual = atual->prox;
    printf("Elemento final: %d\n", atual->info);
}