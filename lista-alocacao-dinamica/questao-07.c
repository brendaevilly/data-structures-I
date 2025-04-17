#include <stdio.h>
#include <stdlib.h>

    int* removeDuplicates(int *vet, int *tam);

    int main(){
        int tam, *vet;
        printf("Tamanho: "); scanf("%d", &tam); printf("\n");
        while(tam < 1){
            printf("[ERRO]\n");
            printf("Tamanho: "); scanf("%d", &tam); printf("\n");
        }

        vet = (int *)malloc(tam*sizeof(int));

        if(vet == NULL){
			printf("Falha na alocacao de memoria!\n");
			return 1;
		}

        for(int i=0; i<tam; i++){
            printf("Vetor[%d]: ", i); scanf("%d", &vet[i]); printf("\n");
        }

        vet = removeDuplicates(vet, &tam);

        for(int i=0; i<tam; i++){
            printf("Vetor[%d]: %d\n", i, vet[i]);
        }

        free(vet);

        return 0;
    }
    
    int* removeDuplicates(int *vet, int *tam){
        int num;

        for(int i=0; i<*tam; i++){
            num = vet[i];

            for(int j=0; j<*tam; j++){
                if(i != j && num == vet[j]){
                    for(int k=j; k<*tam-1; k++){
                        vet[k] = vet[k+1];
                    }

                    (*tam)--;
                    j--;
                }
            }
        }

        vet = (int *)realloc(vet, (*tam)*sizeof(int));

        return vet;

    }