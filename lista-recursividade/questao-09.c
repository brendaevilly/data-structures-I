#include <stdio.h>
#include <stdlib.h>

int* umsConsecutivos(int *vet, int tam, int *oco, int *tamOco, int count);
int maior(int *oco, int tamOco);
int verificar(int *vet, int tam);

int main(){
    int tam, *vet, *oco = NULL, tamOco = 0;

    printf("Tamanho do vetor: "); scanf("%d", &tam);

    vet = (int *)malloc(tam*sizeof(int));

    for(int i=0; i<tam; i++){
        printf("Vet[%d]: ", i);
        scanf("%d", &vet[i]);
        while(vet[i] != 0 && vet[i] != 1){
            printf("[ERRO] Insira APENAS valores binários.\n");
            printf("Vet[%d]: ", i);
            scanf("%d", &vet[i]);
        }
    }
    
    if(!verificar(vet, tam)){
        printf("So existem zeros no vetor.\n");
        free(vet);
        return 0;
    }

    oco = umsConsecutivos(vet, tam, oco, &tamOco, 0);

    printf("Quantidade maxima de 1s consecutivos: %d\n", maior(oco, tamOco));

    free(vet);
    free(oco);

    return 0;
}

int* umsConsecutivos(int *vet, int tam, int *oco, int *tamOco, int count){
    if(tam == 0){

        if(count > 0){
            (*tamOco)++;
            oco = (int *)realloc(oco, (*tamOco) * sizeof(int));
            oco[*tamOco - 1] = count;
        }
        return oco;
    }

    if(vet[0] == 1){
        return umsConsecutivos(vet + 1, tam - 1, oco, tamOco, count + 1);
    }else{
        if(count > 0){
            (*tamOco)++;
            oco = (int *)realloc(oco, (*tamOco) * sizeof(int));
            oco[*tamOco - 1] = count;
        }
        return umsConsecutivos(vet + 1, tam - 1, oco, tamOco, 0);
    }
}

int maior(int *oco, int tamOco){
    int maior = oco[0];

    for(int i=0; i<tamOco; i++){
        if(oco[i] > maior) maior = oco[i];
    }

    return maior;
}

int verificar(int *vet, int tam){
    int verifica = 0;

    for(int i=0; i<tam; i++){
        if(vet[i] == 1){
            verifica = 1;
            break;
        }
    }

    return verifica;
}
