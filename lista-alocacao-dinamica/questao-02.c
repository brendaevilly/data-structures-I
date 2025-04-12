#include <stdio.h>
#include <stdlib.h>

    int *preencheVetor(int tam);

    int main(){
        int tam, *vet;
        printf("Tamanho do vetor: ");
        scanf("%d", &tam);
        printf("\n");

        vet = preencheVetor(tam);

        return 0;
    }

    int *preencheVetor(int tam){
        int *vet;
        vet = (int *)malloc(tam*sizeof(int));

        for(int i=0; i<tam; i++){
            printf("Vetor [%d]: ", i);
            scanf("%d", &vet[i]);
            printf("\n");
        }

        return vet;
    }

    int *ocorrencias(int *vet, int tam){
        
    }

