#include <stdio.h>
#include <stdlib.h>

    int buscaBinaria(int *vet, int *numeroBuscado, int *inicio, int *fim);

    int main(){
        int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, numeroBuscado, inicio = 0, fim = 9;;
        printf("Numero buscado: "); scanf("%d", &numeroBuscado);

        int resultadoDaBusca = buscaBinaria(vet, &numeroBuscado, &inicio, &fim);
        if(resultadoDaBusca == -1){
            printf("O numero %d nao existe na lista.\n", numeroBuscado);
        }else{
            printf("O numero %d existe na lista na posicao %d.\n", numeroBuscado, resultadoDaBusca);
        }
        
        return 0;
    }

    int buscaBinaria(int *vet, int *numeroBuscado, int *inicio, int *fim){
        int meio = (*inicio + *fim)/2;

        if(*inicio > *fim){
            return -1;
        }

        if(vet[meio] == *numeroBuscado){
            return meio;
        }

        if(vet[meio] > *numeroBuscado){
            *fim = meio - 1;
            return buscaBinaria(vet, numeroBuscado, inicio, fim);
        }else{
            *inicio = meio + 1;
            return buscaBinaria(vet, numeroBuscado, inicio, fim);
        }
    }