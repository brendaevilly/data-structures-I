#include <stdio.h>
#include <stdlib.h>

    typedef struct{
        int dano;
        int cooldown;
        int usavel;
    }Ataque;

    int main(){
        int h, n;
        printf("Vidas do chefe: "); scanf("%d", &h); printf("\n");
        printf("Ataques: "); scanf("%d", &n); printf("\n");

        Ataque *ataque;
        ataque = (Ataque *)malloc(n*sizeof(Ataque));

        for(int i=0; i<n; i++){
            printf("Dano do ataque %d: ", i); scanf("%d", &ataque[i].dano); printf("\n");
        }

        for(int i=0; i<n; i++){
            printf("Cooldown do ataque %d: ", i); scanf("%d", &ataque[i].cooldown); printf("\n");
            ataque[i].usavel = 1;
        }

        int turno = 1, vidaChefe = h;

        while(vidaChefe > 0){
            int danoTurno = 0;

            for(int i=0; i<n; i++){
                if(ataque[i].usavel <= turno){
                    danoTurno += ataque[i].dano;
                    ataque[i].usavel = turno + ataque[i].cooldown;
                }
            }

            vidaChefe -= danoTurno;

            printf("Turno: %d\nDano: %d\nVida do chefe: %d\n", turno, danoTurno, vidaChefe);

            if(vidaChefe <= 0) break;

            turno++;
        }

        printf("Chefe derrotado no turno %d\n", turno);

        free(ataque);

        return 0;
    }
    