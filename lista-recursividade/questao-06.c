#include <stdio.h>
#include <stdlib.h>

    int *preencheVetor(int tam);
    int busca(int *vet, int tam, int elemento);

    int main(){
        int elemento, *vet, tam;

        printf("Tamanho do vetor: "); scanf("%d", &tam);
        while(tam <= 1){
            printf("[ERRO]\n");
            printf("Tamanho do vetor: "); scanf("%d", &tam);
        }

        vet = preencheVetor(tam);

        for(int i=0; i<tam; i++){
            printf("%d ", vet[i]);
        }
        printf("\n");

        printf("Elemento procurado: "); scanf("%d", &elemento);

        int resultado = busca(vet, tam-1, elemento);
        if(resultado == -1){
            printf("%d nao esta no vetor.\n", elemento);
        }else{
            printf("%d esta no vetor na posicao %d.\n", elemento, resultado);
        }

        free(vet);

        return 0;
    }

    int *preencheVetor(int tam){
        int *vet;
        vet = (int *)malloc(tam*sizeof(int));

        for(int i=0; i<tam; i++){
            vet[i] = rand() % 101;
        }

        return vet;
    }

    int busca(int *vet, int tam, int elemento){
        if(tam < 0){
            return -1;
        }
        if(vet[tam] == elemento){
            return tam;
        }

        return busca(vet, tam-1, elemento);
    }