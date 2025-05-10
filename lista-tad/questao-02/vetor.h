#ifndef VETOR_H
#define BETOR_H

    typedef struct{
        void **dados;
        int tamanho;
        int capacidade;
    }Vetor;
    
    Vetor *criarVetor();
    void pushBack(Vetor *v, void *elemento);
    void *get(Vetor *v, int index);
    void freeVetor(Vetor *ataques);

#endif