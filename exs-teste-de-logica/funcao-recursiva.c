#include<stdio.h>

    int fatorial(int n) {
        if (n == 0 || n == 1) // Caso base
            return 1;
        return n * fatorial(n - 1); // Chamada recursiva
    }

    int fibonacci(int n) {
        if (n == 0) return 0; // Caso base 1
        if (n == 1) return 1; // Caso base 2
        return fibonacci(n - 1) + fibonacci(n - 2); // Chamada recursiva
    }

    int main(){
        
        int num = 5;
        printf("Fatorial de %d eh %d\n", num, fatorial(num));
        
        num = 6;
        printf("Fibonacci de %d eh %d\n", num, fibonacci(num));  

        return 0;
    }

    