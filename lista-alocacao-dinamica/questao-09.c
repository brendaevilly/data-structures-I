#include <stdio.h>
#include <stdlib.h>

    int *transformaNumero(int a, int b, int *index);

    int main(){
        int a, b, *vet, index = 2;
        printf("Insira os numeros A e B: "); scanf("%d %d", &a, &b); printf("\n");

        while(a >= b){
            printf("[ERRO]\n");
            printf("Insira os numeros A e B: "); scanf("%d %d", &a, &b); printf("\n");
        }

        vet = transformaNumero(a, b, &index);

        for(int i=0; i<index; i++){
            printf("%d ", vet[i]);
        }
        printf("\n");

        free(vet);

        return 0;
    }

    int *transformaNumero(int a, int b, int *index){
        int *vet, op;
        vet = (int *)malloc(1*sizeof(int));

        vet[0] = a;

        while(1){
            printf("1 - Multiplicar A por 2\n2 - Adicionar o digito 1 a direita de A\n3 - Parar\nOpcao: "); scanf("%d", &op); printf("\n");
            while(op != 1 && op != 2 && op != 3){
                printf("[ERRO] Opcao invalida.\n");
                printf("1 - Multiplicar A por 2\n2 - Adicionar o digito 1 a direita de A\nOpcao: "); scanf("%d", &op); printf("\n");
            }

            if(op == 3){
                printf("Encerrando...\n");
                (*index)--;
                return vet;
            }

            vet = (int *)realloc(vet, (*index)*sizeof(int));

            if(op == 1){
                vet[(*index)-1] = vet[(*index)-2]*2;
                printf("Resultado: %d\n", vet[(*index)-1]);
            }else{
                vet[(*index)-1] = vet[(*index)-2]*10+1;
                printf("Resultado: %d\n", vet[(*index)-1]);
            }

            if(vet[(*index)-1] == b){
                printf("Numero transformado.\n");
                break;
            }

            if(vet[(*index)-1] > b){
                printf("Ops... Parece que a transformacao nao pode ser concluida.\n");
                break;
            }

            (*index)++; 
        }

        return vet;
    }