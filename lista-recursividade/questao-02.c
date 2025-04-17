#include <stdio.h>
#include <stdlib.h>

    int numeros(int k);

    int main(){
        int k;
        printf("Valor: "); scanf("%d", &k);
        printf("%d ", numeros(k));

        return 0;
    }

    int numeros(int k){
        if(k <= 0){
            return 0;
        }
        if(k > 0){
            printf("%d ", k);
        }

        return numeros(k-1);
    }