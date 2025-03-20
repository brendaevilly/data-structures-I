#include<stdio.h>
#include<math.h>

    int contaDigitos(int num);
    int inverteNumero(int num, int quantDigitos);

    int main(){
        int numero;
        printf("\nDigite um numero: ");
        scanf("%d", &numero);
        int digitos = contaDigitos(numero);
        printf("\nNumero invertido: %d\n", inverteNumero(numero, digitos));

        return 0;
    }

    int contaDigitos(int num){
        if(num == 0) return 0;
        return 1 + contaDigitos(num/10);
    }

    int inverteNumero(int num, int quantDigitos){
        if(num < 10){
            return num;
        }
        return (num % 10) * pow(10, quantDigitos - 1) + inverteNumero(num/10, quantDigitos-1);
    }