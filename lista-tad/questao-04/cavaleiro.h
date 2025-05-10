#ifndef CAVALEIRO_H
#define CAVALEIRO_H

struct Cavaleiro{
    int poder, ouro, idOriginal;
};

typedef struct Cavaleiro Cavaleiro;
Cavaleiro *cadastrarCavaleiro(int quantidade);
Cavaleiro *ordenarPorPoder(Cavaleiro *c, int quantidade);
Cavaleiro *calcularHerancaDeOuro(Cavaleiro *c, int quantidade, int k);
void exibirValorFinalDeOuro(Cavaleiro *c, int quantidade);
void freeCavaleiro(Cavaleiro *c);

#endif