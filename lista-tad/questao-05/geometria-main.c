#include <stdio.h>
#include <stdlib.h>

#include "geometria.c"

    int main(){
        int **mat, lin, col;
        printf("Linhas: "); scanf("%d", &lin);
        printf("Colunas: "); scanf("%d", &col);

        mat = criaMatriz(lin, col);
        printf("------ MALHA BINARIA ------\n");
        for(int i = 0; i<lin; i++){
            for(int j=0; j<col; j++){
                printf("%d\t", mat[i][j]);
            }
            printf("\n");
        }

        printf("------ DESENHE A FORMA COM 1s ------\n");
        for(int i = 0; i<lin; i++){
            for(int j=0; j<col; j++){
                printf("Malha[%d][%d]: ", i, j); scanf("%d", &mat[i][j]);
                while(mat[i][j] != 0 && mat[i][j] != 1){
                    printf("[ERRO] Apenas 0 ou 1.\n");
                    printf("Malha[%d][%d]: ", i, j); scanf("%d", &mat[i][j]);
                }
            }
        }

        if(ehQuadrado(mat, lin, col)) printf("Eh um quadrado!\n");
        else if(ehTriangulo(mat, lin, col)) printf("Eh um triangulo!\n");
        else printf("Nao eh nenhuma das figuras reconhecidas.\n");

        printf("------ MALHA BINARIA ------\n");
        for(int i = 0; i<lin; i++){
            for(int j=0; j<col; j++){
                printf("%d\t", mat[i][j]);
            }
            printf("\n");
        }

        freeMatriz(mat, lin);

        return 0;
    }