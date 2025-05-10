#include <stdio.h>
#include <stdlib.h>

#include "avenida.h"

Avenida *criaAvenida(int comprimento, int capacidade){
    Avenida *avenida;
    avenida = (Avenida *)malloc(sizeof(Avenida));

    avenida->comprimento = comprimento;
    avenida->capacidade = capacidade;
    avenida->total = 0;

    avenida->sinais = (int *)malloc(capacidade*sizeof(int));

    return avenida;
}

void adicionaSinal(Avenida *a, int posicao){
    if(a->total >= a->capacidade){
        printf("[ERRO] Voce chegou a capacidade maxima de sinais na avenida.\n");
    }else{
        a->total++;
        a->sinais = (int *)realloc(a->sinais, a->total*sizeof(int));
        a->sinais[a->total - 1] = posicao;
    }
}

int maiorTrechoSemSinal(Avenida *a){
    if(a->total == 0){
        return a->comprimento;
    }

    for(int i=0; i<a->total - 1; i++){
        for(int j=0; j<a->total - i - 1; j++){
            if(a->sinais[j] > a->sinais[j+1]){
                int temp = a->sinais[j];
                a->sinais[j] = a->sinais[j+1];
                a->sinais[j+1] = temp;
            }
        }
    }


    int maior = a->sinais[0];

    for(int i=1; i<a->total; i++){
        int trecho = a->sinais[i] - a->sinais[i-1];
        if(trecho > maior) maior = trecho;
    }

    int ultimoTrecho = a->comprimento - a->sinais[a->total - 1];

    if(ultimoTrecho > maior) maior = ultimoTrecho;

    return maior;
}

void liberaAvenida(Avenida *a){
    free(a->sinais);
    free(a);
}