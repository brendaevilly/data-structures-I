#include<stdio.h>

    int maior_elemento(int *v, int n);

    int main(){
        int n;
        printf("Tamanho: ");
        scanf("%d", &n);
        int vet[n];
        for(int i=0; i<n; i++){
            printf("\n[%d]: ", i);
            scanf("%d", &vet[i]);
        }

        int maior = maior_elemento(vet, n);

        printf("\nMaior: %d\n", maior);

        return 0;
    }

    int maior_elemento(int *v, int n){
        int maior = *v;
        for(int i=0; i<n; i++){
            if(*(v+i) > maior) maior = *(v+i);
        }

        return maior;
    }