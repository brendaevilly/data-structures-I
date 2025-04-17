#include <stdio.h>
#include <stdlib.h>

    int sequenciaTribonacci(int n);

    int main(){
        int n;
        printf("Fim da sequencia de tribonacci: "); scanf("%d", &n);
        while(n < 0){
            printf("[ERRO]\n");
            printf("Fim da sequencia de tribonacci: "); scanf("%d", &n);
        }

        printf("Tribonacci de %d: %d\n", n, sequenciaTribonacci(n));

        return 0;
    }

    int sequenciaTribonacci(int n){
        if(n == 0){
            return 0;
        }else if(n == 1 || n == 2){
            return 1;
        }

        return sequenciaTribonacci(n-1) + sequenciaTribonacci(n-2) + sequenciaTribonacci(n-3);
    }

    