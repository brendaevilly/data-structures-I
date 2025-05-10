#include <stdio.h>
#include <stdlib.h>

#include "cavaleiro.c"

    int main(){
        int quantidade, k;
        printf("Quantidade de Cavaleiros da Mesa Polidiagonal (Minimo: 2): "); scanf("%d", &quantidade);
        while(quantidade < 2){
            printf("[ERRO]"); printf("Quantidade de Cavaleiros da Mesa Polidiagonal (Minimo: 2): "); scanf("%d", &quantidade);
        }

        printf("Heranca de ouro (Quant. Cavaleiros com poder menor. Minimo: 1): "); scanf("%d", &k);
        while(k < 1){
            printf("[ERRO]"); printf("Heranca de ouro (Quant. Cavaleiros com poder menor. Minimo: 1): "); scanf("%d", &k);
        }

        Cavaleiro *c;
        c = cadastrarCavaleiro(quantidade);
        for(int i=0; i<quantidade; i++){
            printf("Cavaleiro %d\n", i);
            printf("Poder: "); scanf("%d", &c[i].poder);
            printf("Ouro: "); scanf("%d", &c[i].ouro);
            c[i].idOriginal = i;
        }

        c = ordenarPorPoder(c, quantidade);
        c = calcularHerancaDeOuro(c, quantidade, k);
        exibirValorFinalDeOuro(c, quantidade);
        freeCavaleiro(c);

        return 0;
    }