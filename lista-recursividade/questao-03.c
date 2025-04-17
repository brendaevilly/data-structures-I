#include <stdio.h>
#include <stdlib.h>

    int soma(int k);

    int main(){
        int k;
        printf("Valor: "); scanf("%d", &k);
        printf("%d ", soma(k));

        return 0;
    }

    int soma(int k){
        if(k <= 0){
            return 0;
        }
        
        return k+soma(k-1);  
    }