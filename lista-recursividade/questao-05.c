#include <stdio.h>
#include <stdlib.h>

    float potencia(float tJuros, int meses);
    float jurosCompostos(float vInicial, float tJuros, int meses);

    int main(){
        float valorInicial, taxaJuros;
        int meses;

        printf("Valor inicial: "); scanf("%f", &valorInicial);
        printf("Taxa de juros(em porcentagem): "); scanf("%f", &taxaJuros);
        printf("Numero de meses: "); scanf("%d", &meses);

        printf("Montante: %.2f\n", jurosCompostos(valorInicial, taxaJuros, meses));

        return 0;
    }

    float potencia(float tJuros, int meses){
        if(meses == 0){
            return 1;
        }

        return (1+tJuros)*potencia(tJuros, meses-1);
    }

    float jurosCompostos(float vInicial, float tJuros, int meses){
        float montante = 0;
        return montante = vInicial*potencia(tJuros, meses);
    }