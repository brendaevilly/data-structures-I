#include <stdio.h>
#include <stdlib.h>

#include "lista-dp-circular.h"

    typedef struct no{
        int info;
        No *prox, *ant;
    }No;

    No *criarLista(){
        return NULL;
    }

    No *createNo(){
        No *novo = (No *)malloc(sizeof(No));
        if(!novo) return NULL;
        return novo;
    }

    No *inserirOrdenado(No *lista, int valor){
        No *novo = createNo(); if(!novo) return lista;
        novo->info = valor;
        if(!lista){
            novo->prox = novo;
            novo->ant = novo;
            return novo;
        }
        if(lista->info >= novo->info){
            novo->prox = lista;
            lista->ant = novo;
            if(lista->prox == lista){
                lista->prox = novo;
                novo->ant = lista;
                return novo;
            }
            No *atual = lista;
            while(atual->prox != lista) atual = atual->prox;
            atual->prox = novo;
            novo->ant = atual;
            return novo;
        }

        No *atual = lista;
        while(atual->prox != lista && atual->prox->info <= novo->info) atual = atual->prox;
        if(atual->prox == lista){
            atual->prox = novo;
            novo->ant = atual;
            novo->prox = lista;
            lista->ant = novo;
            return lista;
        }
        No *proximo = atual->prox;
        atual->prox = novo;
        novo->ant = atual;
        novo->prox = proximo;
        proximo->ant = novo;
        return lista;

    }

    No *removerElemento(No *lista, int valor){
        if(!lista) return lista;
        if(lista->info == valor){
            if(lista->prox == lista) return NULL;
            No *novaLista = lista->prox;
            No *atual = novaLista;
            while(atual->prox != novaLista) atual = atual->prox;
            atual->prox = novaLista;
            novaLista->ant = atual;
            return novaLista;
        }

        No *atual = lista;
        while(atual->prox != lista){
            if(atual->info == valor){
                atual->ant->prox = atual->prox;
                atual->prox->ant = atual->ant;
            }
            atual = atual->prox;
        }

        if(atual == valor){
            atual = atual->ant;
            atual->prox = lista;
            lista->ant = atual;
        }

        return lista;
    }

    void mostrarLista(No *lista){
        if(!lista){
            printf("Lista vazia!\n");
            return;
        }

        No *atual = lista;
        do{
            printf("%d ", atual->info);
            atual = atual->prox;
        }while(atual != NULL);
    }

    void liberarLista(No *lista){
        No *atual = lista;
        No *proximo = NULL;
        while(atual != lista){
            proximo = atual->prox;
            free(atual);
            atual = proximo;
        }
    }