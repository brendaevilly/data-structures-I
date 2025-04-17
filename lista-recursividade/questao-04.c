#include <stdio.h>
#include <stdlib.h>

    int soma(int a, int b);

    int main(){
        int a, b;
        printf("A e B: "); scanf("%d %d", &a, &b);
        while(a == b){
            printf("[ERRO]\n");
            printf("A e B: "); scanf("%d %d", &a, &b);
        }
        int menor = (a<b)?a:b;
        int maior = (a>b)?a:b;

        printf("%d\n", soma(menor, maior));

        return 0;
    }

    int soma(int menor, int maior){
        if(menor > maior){
            return 0;
        }

        return menor+soma(menor+1, maior);
    }