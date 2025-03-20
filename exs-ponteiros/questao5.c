#include<stdio.h>

    int* maior(int *a, int *b);

    int main(){
        int a, b;
        scanf("%d", &a);
        scanf("%d", &b);

        int *resultado = maior(&a, &b);

        printf("Maior: %d\n", *resultado);

        return 0;
    }

    int* maior(int *a, int *b){
        if(*a > *b) return a;
        return b;
    }