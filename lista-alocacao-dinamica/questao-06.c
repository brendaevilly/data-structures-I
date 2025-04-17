#include <stdio.h>
#include <stdlib.h>

    int checkifExist(int *vet, int tam);

    int main(){
        int tam, *vet;
        printf("Tamanho: "); scanf("%d", &tam); printf("\n");
        vet = (int *)malloc(tam*sizeof(int));

        if(vet == NULL){
			printf("Falha na alocacao de memoria!\n");
			return 1;
		}

        for(int i=0; i<tam; i++){
            printf("Vetor[%d]: ", i); scanf("%d", &vet[i]); printf("\n");
        }

        if(checkifExist(vet, tam)){
            printf("TRUE\n");
        }else{
            printf("FALSE. Nao ha I e J que satisfacam as condiçoes.\n");
        }

        free(vet);

        return 0;
    }

    int checkifExist(int *vet, int tam){
        int loop = tam;

        while(loop >=1){
            for(int i=0; i<tam; i++){
                for(int j=0; j<tam; j++){
                    if(i != j){
                        if(vet[i] == (2*vet[j])) return 1;
                    }
                }
            }

            loop--;
        }

        return 0;
    }