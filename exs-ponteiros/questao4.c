//Corrigir dps, linha 19.

#include<stdio.h>

    int soma_diagonal(int **matriz, int n);

    int main(){
        int n;
        printf("Quant. l e c: \n");
        scanf("%d", &n);
        int matriz[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                printf("[%d][%d]: \n", i, j);
                scanf("%d", &matriz[i][j]);
            }
        }

        int soma = soma_diagonal(matriz, n);

        printf("Soma: %d\n", soma);

        return 0;
    }

    int soma_diagonal(int **matriz, int n){
        int soma = 0;
        for(int i=0; i<n; i++){
            soma = *(*(matriz+i)+i);
        }

        return soma;
    }