#include <stdio.h>
#include <stdlib.h>

    int exponenciacao(int b, int p);

    int main(){
        int b, p;
        printf("Base: "); scanf("%d", &b);
        printf("Expoente: "); scanf("%d", &p);

        if(p == 1) printf("Resultado: %d\n", b);
        else if(p == 0) printf("Resultado: 1\n");
        else printf("Resultado: %d\n", exponenciacao(b, p));


        return 0;
    }

    int exponenciacao(int b, int p){
        if(p == 0){
            return 1;
        }
        
        return b*exponenciacao(b, p-1);
    }