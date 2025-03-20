#include<stdio.h>

    void troca(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    int main(){
        int x = 10, y = 12;
        troca(&x, &y);
        printf("%d %d", x, y);

        return 0;
    }

