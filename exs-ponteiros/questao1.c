#include<stdio.h>
#include<stdlib.h>

void removerDuplicatas(int *vetor, int n, int *compactado, int *tamCompactado);

    int main(){
        int n;
        printf("\nTamanho do vetor: ");
        scanf("%d", &n);
        printf("\n");
        int vet[n], tamCompac = 0;
        int vetCompact[tamCompac];

        printf("Vetor de inteiros completo.\n");
        for(int i=0; i<n; i++){
            printf("\nVetor[%d]: ", i);
            scanf("%d", &vet[i]);
        }

        printf("\n");

        removerDuplicatas(vet, n, vetCompact, &tamCompac);

        printf("Vetor de inteiros compacto.\n");

        for(int i=0; i<tamCompac; i++){
            printf("Vetor compacto[%d]: %d\n", i, vetCompact[i]);
        }

        return 0;
    }

    void removerDuplicatas(int *vetor, int n, int *compactado, int *tamCompactado){
        int ocorre;
        for(int i=0; i<n; i++){
            ocorre = 0;
            for(int j=0; j<*tamCompactado; j++){
                if(*(vetor+i) == *(compactado+j)) ocorre = 1;
            }
            if(ocorre == 0){
                *(compactado+*tamCompactado) = *(vetor+i);
                (*tamCompactado)++;
            }
        }
    }