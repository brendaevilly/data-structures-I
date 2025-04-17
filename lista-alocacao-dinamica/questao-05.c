#include <stdio.h>
#include <stdlib.h>

    int **alocarMatriz(int i, int j);
    int countNegatives(int **mat, int i, int j);

    int main(){
        int i, j, **mat;
        printf("Linhas: "); scanf("%d", &i); printf("\n");
        printf("Colunas: "); scanf("%d", &j); printf("\n");

        while(i<=0 || j<=0){
            printf("[ERRO]\n");
            printf("Linhas: "); scanf("%d", &i); printf("\n");
            printf("Colunas: "); scanf("%d", &j); printf("\n");
        }

        mat = alocarMatriz(i, j);

        for(int l=0; l<i; l++){
            for(int c=0; c<j; c++){
                printf("Matriz[c][l]: "); scanf("%d", &mat[c][l]); printf("\n");
            }
        }

        printf("Existem %d numeros negativos na matriz.\n", countNegatives(mat, i, j));

        for(int lin=0; lin<i; lin++){
            free(mat[lin]);
        }
        free(mat);

        return 0;
    }

    int **alocarMatriz(int i, int j){
        int **mat;

        mat = (int **)malloc(i*sizeof(int*));

        for(int lin=0; lin<i; lin++){
            mat[lin] = (int *)malloc(j*sizeof(int));
        }

        return mat;
    }

    int countNegatives(int **mat, int i, int j){
        int negativos = 0;

        for(int l=0; l<i; l++){
            for(int c=0; c<j; c++){
                if(mat[l][c] < 0) negativos++;
            }
        }

        return negativos;
    }