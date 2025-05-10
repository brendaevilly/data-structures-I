#include <stdio.h>
#include <stdlib.h>

#include "avenida.c"

    int main(){
        int comprimento, capacidade;
        printf("Comprimento: "); scanf("%d", &comprimento);

        while(comprimento < 2){
            printf("[ERRO]\n");
            printf("Comprimento: "); scanf("%d", &comprimento);
        }

        printf("Capacidade: "); scanf("%d", &capacidade);

        while(capacidade > comprimento || capacidade < 1){
            printf("[ERRO]\n");
            printf("Capacidade: "); scanf("%d", &capacidade); 
        }

        Avenida *avenida;
        avenida = criaAvenida(comprimento, capacidade);

        while(1){
            int op;
            printf("1 - Adcionar sinal\n2 - Ver maior trecho sem sinal\n3 - Sair\n"); scanf("%d", &op);
            
            while(op != 1 && op != 2 && op != 3){
                printf("[ERRO] Opcao invalida.\n");
                printf("1 - Adcionar sinal\n2 - Ver maior trecho sem sinal\n3 - Sair"); scanf("%d", &op);
            }

            if(op == 3){
                printf("Finalizando programa...\n");
                break;
            }else if(op == 1){
                int posicao;
                printf("Digite a posicao do sinal na avenida: "); scanf("%d", &posicao);

                while(posicao < 0 || posicao > comprimento - 1){
                    printf("[ERRO] Posicao fora da avenida.\n");
                    printf("Digite a posicao do sinal na avenida: "); scanf("%d", &posicao);
                }

                adicionaSinal(avenida, posicao);
            }else{
                printf("Maior trecho sem sinais: %d Km\n", maiorTrechoSemSinal(avenida));
            }

        }

        liberaAvenida(avenida);

        return 0;
    }