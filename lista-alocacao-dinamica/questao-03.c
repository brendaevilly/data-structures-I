#include <stdio.h>
#include <stdlib.h>

    int searchInsert(int* vet, int tam, int target);

    int main(){
        int tam, *vet, target;
        printf("Tamanho do vetor: "); scanf("%d", &tam);
        printf("\n");

        while(tam < 1){
            printf("[ERRO]\n");
            printf("Tamanho do vetor: "); scanf("%d", &tam);
            printf("\n");
        }

        vet = (int *)malloc(tam*sizeof(int));

        for(int i=0; i<tam; i++){
            printf("Vetor [%d]: ", i);
            scanf("%d", &vet[i]);
            printf("\n");
        }

        printf("Digite um valor alvo: "); scanf("%d", &target);
        printf("\n");

        printf("Posicao: %d\n", searchInsert(vet, tam, target));

        free(vet);

        return 0;
    }

    int searchInsert(int* vet, int tam, int target){
        int index = -1;

        for(int i=0; i<tam; i++){
            if(vet[i] == target){
                index = i;
                break;
            }
        }

        if(index == -1) return tam;

        return index;
    }

