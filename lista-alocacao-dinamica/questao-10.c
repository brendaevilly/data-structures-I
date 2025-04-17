#include <stdio.h>
#include <stdlib.h>

    int **alocarMatriz(int n);
    int somaElementosBons(int **mat, int n);
    void liberarMatriz(int **mat, int n);

    int main(){
        int n, **mat;
        printf("Tamanho da matriz quadrada: "); scanf("%d", &n); printf("\n");

        while(n%2 == 0 || n < 3){
            printf("[ERRO] Voce inseriu um valor impar ou menor que 3.\n");
            printf("Tamanho da matriz quadrada: "); scanf("%d", &n); printf("\n");
        }

        mat = alocarMatriz(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                printf("Matriz[%d][%d]: ", i, j); scanf("%d", &mat[i][j]);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                printf("%d\t", mat[i][j]);
            }
            printf("\n");
        }

        printf("Soma dos elementos bons da matriz: %d\n", somaElementosBons(mat, n));

        liberarMatriz(mat, n);

        return 0;
    }

    int **alocarMatriz(int n){
        int **mat;
        mat = (int **)malloc(n*sizeof(int*));

        for(int i=0; i<n; i++){
            mat[i] = (int *)malloc(n*sizeof(int));
        }

        return mat;
    }

    int somaElementosBons(int **mat, int n){
        int elementosBons = 0, centro = (n-1)/2;
        
        for(int i=0; i<n; i++){
            elementosBons += mat[i][i];
        }

        int col = n-1;
        for(int i=0; i<n; i++){
            if(col != centro){
                elementosBons += mat[i][col];
            }
            col--;
        }

        for(int j=0; j<n; j++){
            if(j != centro){
                elementosBons += mat[centro][j];
            }
        }

        for(int i=0; i<n; i++){
            if(i != centro){
                elementosBons += mat[i][centro];
            }
        }

        return elementosBons;
    }

    void liberarMatriz(int **mat, int n){
        for(int i=0; i<n; i++){
            free(mat[i]);
        }

        free(mat);
    }
    