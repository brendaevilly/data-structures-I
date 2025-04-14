#include <stdio.h>
#include <stdlib.h>

    char **alocarStrings(int n, int possiveis);
    char **preencheStrings(int n, char **strings, int possiveis);
    char **validString(int n, int *returnSize, int possiveis, char **string);
    void liberarMatriz(char **mat, int n);

    int main(){
        int n, possiveis, returnSize = 0;
        char **strings;
        printf("Tamanho das strings: "); scanf("%d", &n);
        while(n < 2){
            printf("[ERRO]\n");
            printf("Tamanho das strings: "); scanf("%d", &n);
        }

        possiveis = 1 << n;

        strings = alocarStrings(n, possiveis);
        strings = preencheStrings(n, strings, possiveis);
        strings = validString(n, &returnSize, possiveis, strings);

        for(int i=0; i<returnSize; i++){
            for(int j=0; j<n; j++){
                printf("%c", strings[i][j]);
            }
            printf("\n");
        }

        liberarMatriz(strings, possiveis);

        return 0;
    }

    char **alocarStrings(int n, int possiveis){
        char **strings;
        strings = (char **)calloc(possiveis, sizeof(char*));

        for(int i=0; i<possiveis; i++){
            strings[i] = (char *)calloc(n+1, sizeof(char));
            strings[i][n] = '\0';
        }

        return strings;
    }

    char **preencheStrings(int n, char **strings, int possiveis){
        int j = 0, intervalo = possiveis, marcador = 0;

        while(j < n){
            intervalo = intervalo/2;
            for(int i=0; i<possiveis; i++){
                if(marcador<intervalo){
                    strings[i][j] = '1';   
                }else{
                    strings[i][j] = '0';
                }
                marcador++;
                if(marcador == (intervalo*2)) marcador = 0;
            }

            j++;
        }

        return strings;
    }

    char **validString(int n, int *returnSize, int possiveis, char **string){
        int invalida;
        char **validas;
        validas = (char **)malloc(1*sizeof(char*));
        validas[0] = (char *)malloc(n*sizeof(char));

        for(int i=0; i<possiveis; i++){
            invalida = 0;

            for(int j=0; j<n-1; j++){

                if(string[i][j] == '0'){
                    if(string[i][j+1] == '0'){
                        invalida = 1;
                        break;
                    }
                }
            }

            if (!invalida){
                validas = (char **)realloc(validas, (*returnSize + 1) * sizeof(char*));
                validas[*returnSize] = (char *)malloc((n + 1) * sizeof(char));

                for (int m = 0; m < n; m++) {
                    validas[*returnSize][m] = string[i][m];
                }
                validas[*returnSize][n] = '\0';
                (*returnSize)++;
            }
        }

        return validas;
        
    }

    void liberarMatriz(char **mat, int n){
        for(int i=0; i<n; i++){
            free(mat[i]);
        }

        free(mat);
    }
