#include <stdio.h>
#include <stdlib.h>

    int elementMin(int *vet1, int tam1, int *vet2, int tam2);
    int acharMinimo(int *vet, int tam);

    int main(){
        int tam1, tam2, *vet1, *vet2;
        printf("Tamanho inicial do vetor 1: "); scanf("%d", &tam1);
        printf("Tamanho inicial do vetor 2: "); scanf("%d", &tam2);

        vet1 = (int *)malloc(tam1*sizeof(int));

        for(int i=0; i<tam1; i++){
            printf("Vetor [%d]: ", i);
            scanf("%d", &vet1[i]);
            printf("\n");
        }

        vet2 = (int *)malloc(tam2*sizeof(int));

        for(int i=0; i<tam2; i++){
            printf("Vetor [%d]: ", i);
            scanf("%d", &vet2[i]);
            printf("\n");
        }

        int minimo = elementMin(vet1, tam1, vet2, tam2);

        if(minimo == -1){
            printf("Nao existe nenhum numero em comum entre os dois vetores.\n");
        }else{
            printf("Menor numero em comum: %d\n", minimo);
        }

        free(vet1);
        free(vet2);

        return 0;
    }

    int acharMinimo(int *vet, int tam){
        int minimo = vet[0];

        for(int i=0; i<tam; i++){
            if(vet[i] < minimo) minimo = vet[i];
        }

        return minimo;
    }

    int elementMin(int *vet1, int tam1, int *vet2, int tam2){

        int loop = tam1;

        while(loop >= 1){

            int min1 = acharMinimo(vet1, tam1);

            for(int i=0; i<tam2; i++){
                if(min1 == vet2[i]) return min1;
            }

            int index = -1;
            for(int i=0; i<tam1; i++){
                if(min1 == vet1[i]){
                    index = i;
                    break;
                }
            }
        
            for(int i=index; i<tam1-1; i++){
                vet1[i] = vet1[i+1];
            }
            tam1--;
            vet1 = (int *)realloc(vet1, tam1*sizeof(int));

            loop--;
        }
        
        return -1;
    }