#include<stdio.h>
#define MAX 100

    int main() {
        int quant;
        printf("\nQuant. de linhas e colunas: ");        

        scanf("%d", &quant);

        if (quant > MAX) {
            printf("[Erro] O tamanho máximo permitido é %d.\n", MAX);
            return 1; 
        }

        int matriz[MAX][MAX] = {0};

        //Matriz quadrada par.
        if(quant % 2 == 0){
            int a = quant/2 - 1;
            int b = quant/2;

            for(int i=0; i<quant/2; i++){
                for(int j=a; j<=b; j++){
                    matriz[i][j] = 1;
                    matriz[quant - i - 1][j] = 1;
                }

                a--;
                b++;
            } 

        }else{ //Matriz quadrada ímpar.
            int a = quant/2;
            int b = quant/2;

            for(int i=0; i<quant/2; i++){
                for(int j=a; j<=b; j++){
                    matriz[i][j] = 1;
                    matriz[quant - i - 1][j] = 1;
                } 

                a--;
                b++;
            }
        }

        //Matriz com cículo de 1s.
        for(int i=0; i<quant; i++){
            for(int j=0; j<quant; j++){
                printf("%d ", matriz[i][j]);
            }
            printf("\n");
        }

        return 0;
    }