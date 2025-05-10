#include <stdio.h>
#include <stdlib.h>

#include "vetor.c"
#include "ataque.c"

int main(){
    int h, n;
    printf("Vidas do chefe: "); scanf("%d", &h);
    printf("Ataques: "); scanf("%d", &n);

    Vetor *ataques = criarVetor();

    for(int i=0; i<n; i++) {
        int dano, cooldown;
        printf("Ataque %d - Dano: ", i + 1);
        scanf("%d", &dano);
        printf("Ataque %d - Cooldown: ", i + 1);
        scanf("%d", &cooldown);

        Ataque* a = criarAtaque(dano, cooldown);
        pushBack(ataques, a);
    }

    int turno = 1, vidaChefe = h, semDano = 0, limite = 50;

        while(vidaChefe > 0){
            int danoTurno = 0;

            for(int i=0; i<ataques->tamanho; i++){
                Ataque *atual = (Ataque *)get(ataques, i);
                
                if(atual->prontoNoTurno <= turno){
                    danoTurno += atual->dano;
                    atual->prontoNoTurno = turno + atual->cooldown;
                }
            }

            vidaChefe -= danoTurno;

            printf("Turno: %d\nDano: %d\nVida do chefe: %d\n", turno, danoTurno, vidaChefe);

            if(danoTurno == 0){
                semDano++;
                if(semDano >= limite){
                    printf("O chefe nao pode ser derrotado.\n------ GAME OVER ------\n");
                    break;
                }
            }else{
                semDano = 0;
            }

            if(vidaChefe <= 0){
                printf("Chefe derrotado no turno %d\n", turno);
                break;
            } 

            turno++;
        }

        freeVetor(ataques);

    return 0;
}