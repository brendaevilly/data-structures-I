#include <stdio.h>
#include <stdlib.h>

#include "ataque.h"

    Ataque* criarAtaque(int dano, int cooldown) {
        Ataque* a =(Ataque*)malloc(sizeof(Ataque));
        a->dano = dano;
        a->cooldown = cooldown;
        a->prontoNoTurno = 0;
        return a;
    }