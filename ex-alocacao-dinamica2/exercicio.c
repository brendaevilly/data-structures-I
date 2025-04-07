#include <stdio.h>
#include <stdlib.h>

int ** alocarEPreencherMatriz(int l, int c){

    int **m;
    m = (int **)calloc(l, sizeof(int*));

    for(int i=0; i<l; i++){
        m[i] = (int *)calloc(c, sizeof(int));
    }

    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            m[i][j] = rand() % 256;
        }
    }

    return m;

}

int *ocorrencias(int **m, int l, int c, int *cont){

    int *vet;
    vet = (int *)calloc(256, sizeof(int));

    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            vet[m[i][j]]++;
        }
    }

    *cont = 0;
    for(int i=0; i<256; i++){
        if(vet[i] > 0){
            (*cont)++;
        }
    }

    int *ocorrencias = (int *)malloc((*cont) * sizeof(int));
    int index = 0;

    for (int i = 0; i < 256; i++) {
        if (vet[i] > 0) {
            ocorrencias[index] = vet[i];
            index++;
        }
    }

    free(vet);
    return ocorrencias;
}

int main(){

    int x, y, cont;

    printf("\nQuant. linhas: ");
    scanf("%d", &x);
    printf("\nQuant. colunas: ");
    scanf("%d", &y);

    int **mat = alocarEPreencherMatriz(x, y);
    int *vetOcorencias = ocorrencias(mat, x, y, &cont);

    printf("\n--- MATRIZ ---\n");
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    printf("\n--- OCORRENCIAS ---\n");
    for(int i=0; i<cont; i++){
        printf("%d\n", vetOcorencias[i]);
    }

    for (int i = 0; i < x; i++) {
        free(mat[i]);
    }

    free(mat);
    free(vetOcorencias);

    return 0;
}