#ifndef ATAQUE_H
#define ATAQUE_H

    typedef struct{
        int dano;
        int cooldown;
        int prontoNoTurno;
    }Ataque;
    
    Ataque* criarAtaque(int dano, int cooldown);

#endif