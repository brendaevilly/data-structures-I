#ifndef AVENIDA_H
#define AVENIDA_H

    struct Avenida{
        int comprimento; // Comprimento da avenida
        int *sinais; // Lista com as posições onde os semáforos serão postos
        int total; // Total de semáforos até o momento
        int capacidade; // Capacidade maxima de semáforos
    };

    typedef struct Avenida Avenida;
    Avenida *criaAvenida(int comprimento, int capacidade);
    void adicionaSinal(Avenida *a, int posicao);
    int maiorTrechoSemSinal(Avenida *a);
    void liberaAvenida(Avenida *a);

#endif