#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

    struct funcionario {
        char nome[50];
        int id, inicio, fim;
    };

    typedef struct funcionario Funcionario;
    Funcionario* criarFuncionario(int quantidade);
    int verificarSobreposicao(int id1, int id2, Funcionario* funcionario, int quantidade);
    void liberarVetor(Funcionario *funcionario);


#endif