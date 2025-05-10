#include <stdio.h>
#include <stdlib.h>

#include "vetor.h"

Vetor* criarVetor(){
    Vetor *v;
    v = (Vetor*)malloc(sizeof(Vetor));

    v->tamanho = 0;
    v->capacidade = 10;
    v->dados = (void**)malloc(sizeof(void*) * v->capacidade);

    return v;
}

void pushBack(Vetor *v, void *elemento){
    if(v->tamanho > v->capacidade){
        v->capacidade *= 2;
        v->dados = (void **)realloc(v->dados, sizeof(void*)*v->capacidade);
    }

    v->dados[v->tamanho] = elemento;
    v->tamanho++;
}

void* get(Vetor* v, int index) {
    if (index < 0 || index >= v->tamanho) return NULL;
    return v->dados[index];
}

void freeVetor(Vetor *ataques){
    free(ataques);
}