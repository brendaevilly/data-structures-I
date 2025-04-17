#include <stdio.h>
#include <stdlib.h>

    int permutacao(int tam);
    int **alocarMatriz(int tam);
    void copiarVetor(int *dest, int *src, int tam);
    void gerarPermutacoesHeap(int n, int *vet, int **mat, int *linha, int tam);
    int **todasPermutacoes(int tam, int **mat, int*vet);
    void freeMatrizEVetor(int **mat, int tam, int *vet);

    int main(){
        int *vet, tam, **mat;
        printf("Tamanho do vetor: "); scanf("%d", &tam);

        vet = (int *)malloc(tam*sizeof(int));
        for (int i=0; i<tam; i++){
            vet[i] = rand() % 100;
        }

        mat = alocarMatriz(tam);

        mat = todasPermutacoes(tam, mat, vet);

        printf("Vetor.\n");
        for(int i=0; i<tam; i++){
            printf("%d\t", vet[i]);
        }
        printf("\n");

        printf("Permutacoes possiveis dos elementos do vetor.\n");
        for(int i=0; i<permutacao(tam); i++){
            for(int j=0; j<tam; j++){
                printf("%d ", mat[i][j]);
            }
            printf("\n");
        }

        freeMatrizEVetor(mat, tam, vet);

        return 0;
    }

    int permutacao(int tam){
        if(tam == 1){
            return 1;
        }

        return tam*permutacao(tam-1);
    }

    int **alocarMatriz(int tam){
        int **mat;
        int lin = permutacao(tam);
        mat = (int **)malloc(lin*sizeof(int*));
        for(int i=0; i<lin; i++){
            mat[i] = (int *)malloc(tam*sizeof(int));
        }

        return mat;
    }

    void copiarVetor(int *dest, int *src, int tam){
        for(int i=0; i<tam; i++){
            dest[i] = src[i];
        }
    }
    
    void gerarPermutacoesHeap(int n, int *vet, int **mat, int *linha, int tam){
        if (n==1){
            for(int i=0; i<tam; i++){
                mat[*linha][i] = vet[i];
            }
            (*linha)++;
            return;
        }
    
        for(int i=0; i<n; i++){
            gerarPermutacoesHeap(n - 1, vet, mat, linha, tam);
    
            int tmp;
            if(n%2 == 1){
                tmp = vet[0];
                vet[0] = vet[n - 1];
                vet[n - 1] = tmp;
            }else{
                tmp = vet[i];
                vet[i] = vet[n - 1];
                vet[n-1] = tmp;
            }
        }
    }
    
    int **todasPermutacoes(int tam, int **mat, int *vet) {
        int *copia = (int *)malloc(tam * sizeof(int));
        copiarVetor(copia, vet, tam);
        int linha = 0;
        gerarPermutacoesHeap(tam, copia, mat, &linha, tam);
        free(copia);
        return mat;
    }
    

    void freeMatrizEVetor(int **mat, int tam, int *vet){
        for(int i=0; i<permutacao(tam); i++){
            free(mat[i]);
        }

        free(mat);
        free(vet);
    }