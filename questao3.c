#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    printf("\nLinhas: ");
    scanf("%d", &m);
    printf("\nColunas: ");
    scanf("%d", &n);
    printf("\n");

    int matriz[m][n];
    int tam = m * n;
    int vetor[tam];
    int cont = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = rand() % 501;
            vetor[cont++] = matriz[i][j];
            
            printf("Matriz[%d][%d]: %d\n", i, j, matriz[i][j]);
        }
    }

    printf("\nVetor:\n");
    for (int i = 0; i < tam; i++) {
        printf("Vetor[%d]: %d\n", i, vetor[i]);
    }

    int lConsult, cConsult;
    printf("\nLinha para consulta: ");
    scanf("%d", &lConsult);
    printf("\nColuna para consulta: ");
    scanf("%d", &cConsult);

    int cont2 = 0;

    if(lConsult == 0){
        printf("\nValor no vetor: %d\n", vetor[cConsult]);
    }else{
        for(int i=0; i<tam; i=i+n){
            if(cont2 == lConsult){
                printf("\nValor no vetor: %d\n", vetor[i + cConsult]);
            }
            cont2++;
        }
    }

    return 0;
}
