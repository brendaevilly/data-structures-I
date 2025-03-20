#include<stdio.h>

    float calcular_media(int *v, int n);

    int main(){
        int tam;
        scanf("%d", &tam);
        int v[tam];

        for(int i=0; i<tam; i++){
            scanf("%d", &v[i]);
        }

        printf("Media: %.2f\n", calcular_media(v, tam));

        return 0;
    }

    float calcular_media(int *v, int n){
        int soma = 0;
        for(int i=0; i<n; i++){
            soma += *(v+i);
        }
        return soma/n;
    }