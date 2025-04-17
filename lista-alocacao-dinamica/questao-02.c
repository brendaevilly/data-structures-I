#include <stdio.h>
#include <stdlib.h>

    int ocorrenciasUnicas(int *vet, int tam);

    int main(){
        int tam, *vet;
        printf("Tamanho do vetor: "); scanf("%d", &tam); 
        printf("\n");

        while(tam < 1){
            printf("[ERRO]\n");
            printf("Tamanho do vetor: ");
            scanf("%d", &tam);
            printf("\n");
        }

        vet = (int *)malloc(tam*sizeof(int));

        if(vet == NULL){
            printf("Falha na alocacao de memoria!\n");
			return 1;
        }

        for(int i=0; i<tam; i++){
            printf("Vetor [%d]: ", i);
            scanf("%d", &vet[i]);
            printf("\n");
        }

        int verificar = ocorrenciasUnicas(vet, tam);

        if(verificar){
            printf("TRUE\n");
        }else{
            printf("FALSE\n");
        }

        free(vet);

        return 0;
    }

    int ocorrenciasUnicas(int *vet, int tam){
        int maior = vet[0], menor = vet[0];
        
        for(int i=0; i<tam; i++){
            if(vet[i] > maior) maior = vet[i];
            if(vet[i] < menor) menor = vet[i];
        }
        
        int tamVetOcorrencias = maior - menor + 1;
        int *vetOcorrencias;
        vetOcorrencias = (int *)calloc(tamVetOcorrencias, sizeof(int));
        if(vetOcorrencias == NULL){
            printf("Falha na alocacao de memoria!\n");
			return;
        }

        for(int i=0; i<tam; i++){
            vetOcorrencias[vet[i] - menor]++; 
        }

        int verificar = 0, resultado = 1;

        for(int i=0; i<tamVetOcorrencias; i++){
            if(vetOcorrencias[i] != 0){
                verificar = vetOcorrencias[i];
                for(int j=0; j<maior+1; j++){
                    if(j != i){
                        if(verificar == vetOcorrencias[j]){
                            resultado = 0;
                        }
                    }
                }
            }
        }

        free(vetOcorrencias);

        return resultado;
    }


