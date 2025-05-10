#include <stdio.h>
#include <stdlib.h>

#include "cavaleiro.h"

Cavaleiro *cadastrarCavaleiro(int quantidade){
    Cavaleiro *c;
    c = (Cavaleiro *)malloc(quantidade*sizeof(Cavaleiro));

    return c;
}

Cavaleiro *ordenarPorPoder(Cavaleiro *c, int quantidade){
    for(int i=0; i<quantidade-1; i++){
        for(int j=0; j<quantidade-i-1; j++){
            if(c[j].poder > c[j+1].poder){
                Cavaleiro temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp;
            }
        }
    }

    return c;
}

Cavaleiro *calcularHerancaDeOuro(Cavaleiro *c, int quantidade, int k){
    int herda;
    for(int i=quantidade-1; i>=0; i--){
        herda = 1;
        while(herda <= k){
            if((i-herda) < 0) break;
            c[i].ouro += c[i-herda].ouro;
            herda++;
        }
    }

    return c;
}

void exibirValorFinalDeOuro(Cavaleiro *c, int quantidade){
    for(int i=0; i<quantidade; i++){
        for(int j=0; j<quantidade; j++){
            if(c[j].idOriginal == i){
                printf("ID %d: %d em ouro.\n", c[j].idOriginal, c[j].ouro);
                break;
            }
        }
    }
}

void freeCavaleiro(Cavaleiro *c){
    free(c);
}