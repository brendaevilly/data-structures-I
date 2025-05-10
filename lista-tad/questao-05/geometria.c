#include <stdio.h>
#include <stdlib.h>

#include "geometria.h"

int **criaMatriz(int lin, int col){
    int **mat;
    mat = (int **)calloc(lin, sizeof(int *));

    for(int i=0; i<lin; i++){
        mat[i] = (int *)calloc(col, sizeof(int));
    }

    return mat;
}

int ehQuadrado(int **mat, int lin, int col){
    int *forma = (int *)calloc(lin, sizeof(int));

    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            if(mat[i][j] == 1)
                forma[i]++;
        }
    }

    int inicio = -1, fim = -1;
    for(int i=0; i<lin; i++){
        if(forma[i] > 0){
            inicio = i;
            break;
        }
    }

    for(int i=inicio; i<lin; i++){
        if(forma[i] == 0){
            fim = i;
            break;
        }
    }

    if (fim == -1) fim = lin;

    int largura = forma[inicio];
    for(int i=inicio; i<fim; i++){
        if(forma[i] != largura){
            free(forma);
            return 0;
        }
    }

    if((fim - inicio) == largura){
        free(forma);
        return 1;
    }else{
        free(forma);
        return 0;
    }
}


int ehTriangulo(int **mat, int lin, int col){
    int *forma = (int *)calloc(lin, sizeof(int));

    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            if(mat[i][j] == 1) forma[i]++;
        }
    }

    int inicio = -1, fim = -1;
    for(int i=0; i<lin; i++){
        if(forma[i] > 0){
            inicio = i;
            break;
        }
    }

    for(int i=inicio; i<lin; i++){
        if(forma[i] == 0){
            fim = i;
            break;
        }
    }

    if (fim == -1) fim = lin;

    int crescente = 1, decrescente = 1;

    for(int i=inicio+1; i<fim; i++){
        if(forma[i] <= forma[i-1]) crescente = 0;
        if(forma[i] >= forma[i-1]) decrescente = 0;
    }

    free(forma);
    return (crescente || decrescente);
}

void freeMatriz(int **mat, int lin){
    for(int i=0; i<lin; i++){
        free(mat[i]);
    }

    free(mat);
}