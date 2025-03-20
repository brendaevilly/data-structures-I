#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 100

    int main(){
        int diametro;
        printf("\nQuant. linhas e colunas: ");
        scanf("%d", &diametro);
        printf("\n");

        int matriz[MAX][MAX] = {0};

        int elementoCentral = diametro/2;
        int raio = diametro/2;

        for(int i=0; i<diametro; i++){
            for(int j=0; j<diametro; j++){
                int distancia = (int)sqrt(pow(i - elementoCentral, 2) + pow(j - elementoCentral, 2));
                if(distancia <= raio){
                    matriz[i][j] = 1;
                }
            }
        }

        for(int i=0; i<diametro; i++){
            for(int j=0; j<diametro; j++){
                printf("%d ", matriz[i][j]);
            }
            printf("\n");
        }

        system("PAUSE");
        return 0;
    }