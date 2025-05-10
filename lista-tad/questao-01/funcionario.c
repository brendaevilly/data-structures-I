#include <stdio.h>
#include <stdlib.h>

#include "funcionario.h"

    Funcionario* criarFuncionario(int quantidade){
        Funcionario *funcionario = (Funcionario *)malloc(quantidade*sizeof(Funcionario));

        for(int i=0; i<quantidade; i++){
            printf("Nome do funionario %d: ", i+1); setbuf(stdin, NULL); scanf("%[^\n]", funcionario[i].nome);
            printf("Id do funcionario %d: ", i+1); scanf("%d", &funcionario[i].id);
            printf("Inicio do espediente do funcionario %d: ", i+1); scanf("%d", &funcionario[i].inicio);
            printf("Fim do espediente do funcionario %d: ", i+1); scanf("%d", &funcionario[i].fim);

            while(funcionario[i].inicio < 0 || funcionario[i].inicio > 12 ||
                funcionario[i].fim < 0 || funcionario[i].fim > 12 ||
                funcionario[i].inicio >= funcionario[i].fim){
                    printf("[ERRO]\n");
                    printf("Inicio do espediente do funcionario %d: ", i+1); scanf("%d", &funcionario[i].inicio);
                    printf("Fim do espediente do funcionario %d: ", i+1); scanf("%d", &funcionario[i].fim);
                }
        }
        
        return funcionario;
    }

    int verificarSobreposicao(int id1, int id2, Funcionario* funcionario, int quantidade){
        int index1 = -1, index2 = -1;
        for(int i=0; i<quantidade; i++){
            if(funcionario[i].id == id1) index1 = i;
            if(funcionario[i].id == id2) index2 = i;
        }

        if(index1 == -1 || index2 == -1) return -1;

        if(funcionario[index1].inicio < funcionario[index2].fim && funcionario[index2]. inicio < funcionario[index1].fim) return 1;

        return 0;
    }

    void liberarVetor(Funcionario *funcionario){
        free(funcionario);
    }

    