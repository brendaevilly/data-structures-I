#include<stdio.h>

void contar_ocorrencias(int *vetor, int n, int *ocorrencias, int *tam_ocorrencias);

int main(){
    int tam;
    scanf("%d", &tam); 
    int v[tam];

    for(int i = 0; i < tam; i++){
        scanf("%d", &v[i]);
    }

    int vOco[tam];  
    int tamOc[tam];  


    contar_ocorrencias(v, tam, vOco, tamOc);


    printf("Contagem de ocorrencias:\n");
    for(int i = 0; i < tam; i++){
        if(vOco[i] > 0) {
            printf("Valor %d apareceu %d vezes\n", tamOc[i], vOco[i]);
        }
    }

    return 0;
}

void contar_ocorrencias(int *vetor, int n, int *ocorrencias, int *tam_ocorrencias){
    int auxi = 0, oco;
    for(int i = 0; i < n; i++){
        ocorrencias[i] = 0;  
        oco = 0;
        auxi = *(vetor + i); 

        for(int j = 0; j < i; j++){
            if(*(tam_ocorrencias + j) == auxi) {
                oco = 1;
                break;  
            }
        }

     
        if(oco == 0){
            for(int j = 0; j < n; j++){
                if(auxi == *(vetor + j)) {
                    ocorrencias[i]++;
                }
            }

            *(tam_ocorrencias + i) = auxi;
            *(ocorrencias + i) = ocorrencias[i];
        }
    }
}
