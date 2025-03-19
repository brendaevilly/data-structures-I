#include<stdio.h>

    int main(){
        int nums = 0, soma = 0, maior = 0, menor = 0, cont = 0;
        float media = 0.0;

        while(nums != -1){
            printf("\nInsira valor: ");
            scanf("%d", &nums);
            if(nums == -1) break;
            soma += nums;
            if(cont == 0){
                maior = nums;
                menor = nums;
            }
            if(nums > maior) maior = nums;
            if(nums < menor) menor = nums;
            cont++;
        }

        media = soma/cont;

        printf("\nSoma dos numeros iseridos: %d\nMedia dos numeros iseridos %.2f\nMaior numero iserido: %d\nMenor numero iserido: %d\n", soma, media, maior, menor);

        return 0;
    }