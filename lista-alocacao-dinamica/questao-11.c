#include <stdio.h>
#include <stdlib.h>

    int **alocarTrianguloPascal();
    int **preencheTriangulo(int **mat);
    void liberarMatriz(int **mat);

    int main(){
        int **tringuloPascal, linha = 1, numLinha;
        tringuloPascal = alocarTrianguloPascal();
        tringuloPascal = preencheTriangulo(tringuloPascal);

        for(int i=0; i<12; i++){
            for(int j=0; j<linha; j++){
                printf("%d\t", tringuloPascal[i][j]);
            }
            printf("\n");
            linha++;
        }

        printf("Entre com o numero da linha procurada(de 0 ate 11): "); scanf("%d", &numLinha);
        while(numLinha < 0 || numLinha > 11){
            printf("[ERRO]\n");
            printf("Entre com o numero da linha procurada(de 0 ate 11): "); scanf("%d", &numLinha);
        }

        for(int i=0; i<numLinha+1; i++){
            printf("%d ", tringuloPascal[numLinha][i]);
        }

        liberarMatriz(tringuloPascal);

        return 0;
    }

    int **alocarTrianguloPascal(){
        int **tringuloPascal, linha = 1;
        tringuloPascal = (int **)calloc(12, sizeof(int*));

        for(int i=0; i<12; i++){
            tringuloPascal[i] = (int *)calloc(linha, sizeof(int));

            linha++;
        }

        return tringuloPascal;
    }

    int **preencheTriangulo(int **mat){
        int linha = 1;

        for(int i=0; i<12; i++){

            for(int j=0; j<linha; j++){
                if(j == 0 || j == i){
                    mat[i][j] = 1;
                }else{
                    mat[i][j] = mat[i-1][j-1] + mat[i-1][j];
                }

            }
            linha++;
        }

        return mat;
    }

    void liberarMatriz(int **mat){
        int linha = 1;

        while(linha <= 12){
            for(int i=0; i<linha; i++){
                free(mat[i]);
            }

            linha++;
        }
        
        free(mat);
    }