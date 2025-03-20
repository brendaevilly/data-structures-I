#include<stdio.h>
#include<stdlib.h>

    int main(){
        int m, n;
        printf("\nLinhas: ");
        scanf("%d", &m);
        printf("\nColunas: ");
        scanf("%d", &n);
        printf("\n");
        int matriz[m][n];
        int vetor[256] = {0};

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                matriz[i][j] = rand() % 256;
                vetor[matriz[i][j]] ++;
                printf("matriz[%d][%d]: %d\n", i, j, matriz[i][j]);
            }
        }

        printf("--------------------\n");

        for(int i=0; i<256; i++){
            if(vetor[i] > 0){
                printf("Frequencia do numero %d na matriz: %d\n", i, vetor[i]);
            }
        }

        system("PAUSE");
        return 0;
    }